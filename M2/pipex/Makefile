NAME = pipex

LIBFT = include/libft

SRC_DIR = src/
OBJ_DIR = obj/

FLAG_LIBFT = -Wall -Wextra -Werror -I include
FLAG = -Wall -Wextra -Werror ${OBJ} -I include -Linclude/ -lft

SRC_FILE = pipex ft_free_tab cmd_check find_envp execute_fork

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
