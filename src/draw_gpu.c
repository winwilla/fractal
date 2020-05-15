#include "fractol.h"

static int		terminate(int error, t_cl_params *cl)
{
	ft_error(error);
	if (cl->context)
		clReleaseContext(cl->context);
	if (cl->cq)
		clReleaseCommandQueue(cl->cq);
	if (cl->prog)
		clReleaseProgram(cl->prog);
	if (cl->kernel)
		clReleaseKernel(cl->kernel);
	if (cl->buf)
		clReleaseMemObject(cl->buf);
	if (cl->code)
		ft_strdel(&cl->code);
	exit(1);
}

static void		set_kernel(t_fractal *fractal, t_fractal_cl *var)
{
	cl_int			ret;

	ret = clSetKernelArg(fractal->cl.kernel, 0, sizeof(cl_mem),
													(void *)&(fractal->cl.buf));
	ret |= clSetKernelArg(fractal->cl.kernel, 1, sizeof(t_fractal_cl),
															(void *)(var));
	if (ret != CL_SUCCESS)
		terminate(CL_ERROR, &fractal->cl);
	ret = clEnqueueNDRangeKernel(fractal->cl.cq, fractal->cl.kernel, 1, NULL,
		&(fractal->cl.global_work_size), &(fractal->cl.local_work_size),
		0, NULL, NULL);
	ret |= clEnqueueReadBuffer(fractal->cl.cq, fractal->cl.buf, CL_TRUE, 0,
		fractal->cl.buf_len * sizeof(cl_int),
		fractal->image.data, 0, NULL, NULL);
	if (ret != CL_SUCCESS)
		terminate(CL_ERROR, &fractal->cl);
}

static void		build_cl_program(t_fractal *fractal)
{
	cl_int			ret;

	fractal->cl.prog = clCreateProgramWithSource(fractal->cl.context, 1,
							(const char **)&(fractal->cl.code), NULL, &ret);
	if (ret != CL_SUCCESS)
		terminate(CL_ERROR, &fractal->cl);
	ret = clBuildProgram(fractal->cl.prog, 1,
								&(fractal->cl.dev), "-I./include", NULL, NULL);
	if (ret != CL_SUCCESS)
		terminate(CL_ERROR, &fractal->cl);
	fractal->cl.kernel = clCreateKernel(fractal->cl.prog, "fractals", &ret);
	if (ret != CL_SUCCESS)
		terminate(CL_ERROR, &fractal->cl);
	fractal->cl.buf = clCreateBuffer(fractal->cl.context, CL_MEM_READ_WRITE,
						fractal->cl.buf_len * sizeof(cl_int), NULL, &ret);
	if (ret != CL_SUCCESS)
		terminate(CL_ERROR, &fractal->cl);
}

void			cl_setup(t_fractal *fractal)
{
	cl_int ret;

	ret = clGetPlatformIDs(1, &fractal->cl.pl, NULL);
	ret |= clGetDeviceIDs(fractal->cl.pl,
				CL_DEVICE_TYPE_GPU, 1, &fractal->cl.dev, NULL);
	if (ret != CL_SUCCESS)
		terminate(CL_ERROR, &fractal->cl);
	fractal->cl.context = clCreateContext(NULL, 1,
										&fractal->cl.dev, NULL, NULL, &ret);
	if (ret != CL_SUCCESS)
		terminate(CL_ERROR, &fractal->cl);
	fractal->cl.cq = clCreateCommandQueue(fractal->cl.context,
										fractal->cl.dev, 0, &ret);
	if (ret != CL_SUCCESS)
		terminate(CL_ERROR, &fractal->cl);
	build_cl_program(fractal);
}

void			draw_fractal_gpu(t_fractal *fractal)
{
	t_fractal_cl	var;

	var = init_input(fractal);
	set_kernel(fractal, &var);
	clFinish(fractal->cl.cq);
}
