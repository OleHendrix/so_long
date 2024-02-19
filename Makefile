NAME	:= so_long
CFLAGS	:= -Wextra -Wall -Werror -Wunreachable-code -Ofast -g -v #-fsanitize=address
LIBMLX	:= ./MLX42
LIBFTPATH = ./Libft/
LIBFT = $(LIBFTPATH)libft.a
PRINTFPATH = ./ft_printf/
PRINTF = $(PRINTFPATH)libftprintf.a

HEADERS	:= -I ./include -I $(LIBMLX)/include
LIBS	:= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm
SRCS	:= $(shell find ./MLX42/src -iname "*.c") $(shell find ./src -iname "*.c")
OBJS	:= ${SRCS:.c=.o}

all: $(NAME)
 
%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)

$(NAME): $(OBJS)
	@make -C $(LIBFTPATH) all
	@make -C $(PRINTFPATH) all
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4
	@$(CC) $(OBJS) $(LIBS) $(LIBFT) $(PRINTF) $(HEADERS) -o $(NAME)

clean:
	@rm -rf $(OBJS)
	@rm -rf $(LIBMLX)/build
	@make -C $(LIBFTPATH) clean
	@make -C $(PRINTFPATH) clean

fclean: clean
	@rm -rf $(NAME)
	@make -C $(LIBFTPATH) fclean
	@make -C $(PRINTFPATH) fclean

re: clean all

.PHONY: all, clean, fclean, re, libmlx