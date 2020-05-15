#ifndef COMPLEX_H
# define COMPLEX_H

typedef	struct	s_complex
{
	double	re;
	double	im;
}				t_complex;

/*
** COMPLEX OPERATIONS
*/
t_complex		new_complex(double re, double im);
t_complex		complex_mult(t_complex a, t_complex b);
t_complex		complex_mult_num(t_complex a, double k);
t_complex		complex_div(t_complex a, t_complex b);
t_complex		complex_add(t_complex a, t_complex b);
t_complex		complex_cos(t_complex c);
t_complex		complex_sin(t_complex c);
t_complex		func(t_complex z, int d);
double			complex_abs(t_complex c);
double			complex_abs_min(t_complex a, t_complex b);

#endif
