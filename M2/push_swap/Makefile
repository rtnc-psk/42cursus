NAME = push_swap

LIBFT = include/libft

SRC_DIR = src/
OBJ_DIR = obj/

FLAG_LIBFT = -Wall -Wextra -Werror -I include
FLAG = -Wall -Wextra -Werror ${OBJ} -I include -Linclude/ -lft

SRC_FILE = push_swap parser utils1 utils2 push swap rotate \
		   reverse_rotate test_op butterfly tiny_sort

SRC = $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILE)))
OBJ = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILE)))

${OBJ_DIR}%.o: ${SRC_DIR}%.c
	@mkdir -p ${dir $@}
	cc ${FLAG_LIBFT} -c $< -o $@

all: ${NAME}

${NAME}: libft ${OBJ}
	cc ${FLAG} -o ${NAME}
	
libft:
	@make -C ${LIBFT}
	@cp ./include/libft/libft.a ./include

clean:
	@make clean -C ./include/libft
	rm -rf ${OBJ_DIR}

fclean:	clean
	@make fclean -C ./include/libft
	@rm -rf ./include/libft.a
	@rm -rf ${NAME}

re:	fclean all

.PHONY: all clean fclean re
