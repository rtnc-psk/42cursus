SRC = $(addsuffix .c, ft_isalpha ft_isdigit ft_isalnum ft_isascii ft_isprint ft_strlen ft_memset ft_bzero ft_memcpy ft_memmove ft_strlcpy ft_strlcat ft_toupper ft_tolower ft_strchr ft_strrchr ft_strncmp ft_memchr ft_memcmp ft_strnstr ft_atoi ft_calloc ft_strdup ft_substr ft_strjoin ft_strtrim ft_split ft_itoa ft_strmapi ft_striteri ft_putchar_fd ft_putstr_fd ft_putendl_fd ft_putnbr_fd)

OBJS := $(SRC:%.c=%.o)

B_SRCS = $(addsuffix _bonus.c, ft_lstnew ft_lstadd_front ft_lstsize ft_lstlast ft_lstadd_back ft_lstdelone ft_lstclear ft_lstiter ft_lstmap)

B_OBJS = $(B_SRCS:%.c=%.o)

NAME = libft.a

FLAGS = -Wall -Wextra -Werror -I$(HEADER_DIR)

HEADER_DIR = .

RM = rm -f

OBJS_BASBO = $(OBJS) $(B_OBJS)

ARNAME = ar rcs $(NAME)

all: $(NAME)

$(NAME): $(OBJS)
	$(ARNAME) $(OBJS)

%.o: %.c
	cc $(FLAGS) -o $@ -c $<

clean:
	$(RM) $(OBJS_BASBO)

fclean: clean
	$(RM) $(NAME)

re: fclean all

bonus: $(OBJS_BASBO)
	$(ARNAME) $(OBJS_BASBO)

.PHONY: all clean fclean re
