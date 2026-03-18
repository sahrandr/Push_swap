# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sahrandr <sahrandr@student.42antananari    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/13 00:00:00 by                   #+#    #+#              #
#    Updated: 2026/03/17 14:27:39 by sahrandr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap

CC			= cc
CFLAGS		= -Wall -Wextra -Werror

SRCS		= push_swap.c \
			  adaptive_sort.c \
			  assign_index.c \
			  bring_to_top.c \
			  calculate_disorder.c \
			  complex_sort.c \
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
			  ft_split_mod.c \
			  ft_substr.c \
			  get_bits.c \
			  is_duplicate.c \
			  is_in_chunk.c \
			  medium_sort.c \
			  process_bits.c \
			  push_utils.c \
			  reverse_rotate.c \
			  rotation_utils.c \
			  simple_sort.c \
			  stack_size.c \
			  swap_utils.c\
			  radix_sort.c\
			  ft_strcmp.c

OBJS		= $(SRCS:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
			$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o:		%.c
			$(CC) $(CFLAGS) -c $< -o $@

clean:
			rm -f $(OBJS)

fclean:		clean
			rm -f $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
