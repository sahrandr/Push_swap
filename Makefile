NAME		= push_swap
BONUS_NAME	= checker

CC			= cc
CFLAGS		= -Wall -Wextra -Werror

COMMON_SRCS	= assign_index.c \
			  bring_to_top.c \
			  calculate_disorder.c \
			  count_bytes.c \
			  count_chunk.c \
			  create_node.c \
			  find_in_chunk.c \
			  find_max_position.c \
			  find_min_position.c \
			  free_split.c \
			  free_stack.c \
			  ft_atoi.c \
			  ft_isdi.c \
			  ft_lstadd_back.c \
			  parse_flags.c \
			  ft_split_mod.c \
			  ft_substr.c \
			  ft_strcmp.c \
			  get_bits.c \
			  is_duplicate.c \
			  is_in_chunk.c \
			  is_sorted.c \
			  medium_sort.c \
			  process_bits.c \
			  push_utils.c \
			  radix_sort.c \
			  reverse_rotate.c \
			  rotation_utils.c \
			  small_sort.c \
			  stack_size.c \
			  swap_utils.c \
			  ft_putsr_fd.c\
			  ft_putnbr_fd.c\
			  dispatch_sort.c\
			  sort_type_without_medium.c

SRCS		= main.c push_swap.c $(COMMON_SRCS)
BONUS_SRCS	= checker.c $(COMMON_SRCS)

OBJS		= $(SRCS:.c=.o)
BONUS_OBJS	= $(BONUS_SRCS:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

bonus:		$(BONUS_NAME)

$(BONUS_NAME): $(BONUS_OBJS)
	$(CC) $(CFLAGS) $(BONUS_OBJS) -o $(BONUS_NAME)

%.o:		%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(BONUS_OBJS)

fclean:		clean
	rm -f $(NAME) $(BONUS_NAME)

re:		fclean all

.PHONY:		all bonus clean fclean re
