NAME = push_swap.a

CC = cc

FLAGS = -Wall -Werror -Wextra

HEADER =  push_swap.h 

SRCS = create_node.c\
		free_stack.c\
		ft_atoi.c\
		ft_isdi.c\
		ft_split_mod.c\
		is_duplicate.c\
		push_swap.c\
		free_split.c\
		ft_substr.c\
		ft_lstadd_back.c\
		push_utils.c\
		reverse_rotate.c\
		rotation_utils.c\
		swap_utils.c\

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME) : $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
.PHONY: all clean fclean re