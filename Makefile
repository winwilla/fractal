NAME = fractol

SRC_DIR 	= ./src
BUILD_DIR	= ./build
LIBFT_DIR	= ./libft
HEADER_DIR	= ./include
FLAGS 		= -Wall -Werror -Wextra
FRAMEFLAGS	= -framework OpenGL -framework AppKit -framework OpenCL
CC 			= gcc
		
SRC			= $(notdir $(wildcard $(SRC_DIR)/*.c))
SRCS 		= $(addprefix $(SRC_DIR)/, $(SRC))
OBJS		= $(addprefix $(BUILD_DIR)/, $(SRC:.c=.o))

LFT_DIR		= ./libft
LIBFT		= $(LIBFT_DIR)/libft.a 

LIBMLX_DIR	= ./minilibx_macos
LIBMLX		= $(LIBMLX_DIR)/libmlx.a

INCL		= -I $(LIBFT_DIR) -I $(LIBMLX_DIR) -I $(HEADER_DIR)
LIBS		= -L $(LIBFT_DIR) -lft -L $(LIBMLX_DIR) -lmlx -lm

RED			= \033[0;31m
GREEN		= \033[1;32m
SEA			= \033[0;36m
NORMAL		= \033[00m

.PHONY: all, clean, fclean, re 

all : $(NAME) 

$(NAME):  $(LIBMLX) $(LIBFT) $(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(LIBS) $(FRAMEFLAGS)
	@echo "$(GREEN)fractol compiled!$(NORMAL)"

$(OBJS): $(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(BUILD_DIR)
	$(CC) $(FLAGS) -MD -c $(INCL) $< -o $@ 

$(LIBFT):
	make -C $(LIBFT_DIR)

$(LIBMLX):
	make -C $(LIBMLX_DIR)	
	
include $(wildcard $(BUILD_DIR)/*.d)

clean:
	rm -rf $(BUILD_DIR)/*
	make -C $(LIBFT_DIR) clean
	make -C $(LIBMLX_DIR) clean
	@echo "$(SEA)fractol clean done$(NORMAL)"
		
fclean: clean
	rm -rf $(BUILD_DIR)
	rm -rf $(NAME)
	rm -f $(LIBFT)
	rm -f $(LIBMLX)
	@echo "$(RED)fractol fclean done$(NORMAL)"

re: fclean all

.PHONY: all clean fclean re
