SRCS=	main.c test_ft_read.c test_ft_strcpy.c \
	test_ft_strlen.c test_ft_strcmp.c test_ft_strdup.c test_ft_write.c \
	valid_test.c
SRCS_DIR = srcs/
OBJS= $(addprefix $(SRCS_DIR), $(SRCS:.c=.o))
CC= gcc
CFLAGS= -Wall -Werror -Wextra
LIBDIR= copy_the_path_of_your_libasm_dir_here
HEADER= -I includes -I $(LIBDIR)
LDFLAGS= -L./$(LIBDIR)
LIB= -lasm
NAME=	my_libasm_test

.c.o:
	$(CC) $(CFLAGS) $(HEADER) -c $< -o $(<:.c=.o)
$(NAME): $(OBJS)
	make -C $(LIBDIR)
	$(CC) $(CFLAGS) $(LDFLAGS) $(OBJS) -o $(NAME) $(LIB)
all: $(NAME)
clean:
	rm -f $(OBJS)
fclean: clean
	rm -f $(NAME)
re: fclean all
.PHONY: all clean fclean re
