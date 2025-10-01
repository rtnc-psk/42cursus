NAME = libftprintf.a

LIBFT = libft

SRCS_DIR = srcs/
OBJS_DIR = obj/

CC = cc

CFLAGS = -Wall -Werror -Wextra -I includes

SRC_FILES = ft_printf ft_format_pf ft_putchar_pf ft_puthex_pf \
			  ft_putnbr_pf ft_putunbr_pf ft_putptr_pf ft_putstr_pf

SRCS = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(SRC_FILES)))

${OBJS_DIR}%.o: ${SRCS_DIR}%.c
	@mkdir -p ${dir $@}
	${CC} ${CFLAGS} -c $< -o $@

all: ${NAME}

${NAME}: ${OBJS}
	@make -C ${LIBFT}
	@cp libft/libft.a . 
	@mv libft.a ${NAME}
	ar rcs ${NAME} ${OBJS}

clean: 
	rm -rf ${OBJS_DIR}
	@make clean -C ${LIBFT}

fclean: clean
	rm -rf ${NAME}
	@make fclean -C ${LIBFT}

re: fclean all

.PHONY: all clean fclean re
