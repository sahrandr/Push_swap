/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahrandr <sahrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 14:42:45 by sahrandr          #+#    #+#             */
/*   Updated: 2026/03/22 11:23:44 by sahrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

typedef enum e_strategy
{
	STRAT_SIMPLE,
	STRAT_MEDIUM,
	STRAT_COMPLEX,
	STRAT_ADAPTIVE
}					t_strategy;

typedef struct s_counter
{
	int				total;
	int				sa;
	int				sb;
	int				ss;
	int				pa;
	int				pb;
	int				ra;
	int				rb;
	int				rr;
	int				rra;
	int				rrb;
	int				rrr;
}					t_counter;

t_stack				*create_node(int value);
void				free_stack(t_stack **stack);
void				free_split(char **tab);
int					ft_atoi(const char *nptr, int *error);
int					ft_isdi(char *str);
char				**ft_split_mod(char const *s, char c);
char				*ft_strdup(const char *s);
char				*ft_substr(char const *s, unsigned int start, size_t len);
int					is_duplicate(t_stack *stack_a, int num);
void				ft_lstadd_back(t_stack **stack, t_stack *new_node);
int					stack_size(t_stack *stack);
int					is_sorted(t_stack *stack);
void				assign_index(t_stack *stack_a);
float				calculate_disorder(t_stack *stack_a);
void				process_bits(t_stack **stack_a, t_stack **stack_b, int bit,
						t_counter *counter);
void				sa(t_stack **a, t_counter *counter);
void				sb(t_stack **b, t_counter *counter);
void				ss(t_stack **a, t_stack **b, t_counter *counter);
void				pa(t_stack **a, t_stack **b, t_counter *counter);
void				pb(t_stack **a, t_stack **b, t_counter *counter);
void				ra(t_stack **a, t_counter *counter);
void				rb(t_stack **b, t_counter *counter);
void				rr(t_stack **a, t_stack **b, t_counter *counter);
void				rra(t_stack **a, t_counter *counter);
void				rrb(t_stack **b, t_counter *counter);
void				rrr(t_stack **a, t_stack **b, t_counter *counter);
int					find_min_position(t_stack *stack);
int					find_max_position(t_stack *stack);
void				bring_to_top(t_stack **stack, int position, int size,
						t_counter *counter);
void				simple_sort(t_stack **stack_a, t_stack **stack_b,
						t_counter *counter);
int					count_chunk(int size);
int					is_in_chunk(int index, int chunk_min, int chunk_max);
int					find_in_chunk(t_stack *stack, int chunk_min, int chunk_max);
void				medium_sort(t_stack **stack_a, t_stack **stack_b,
						t_counter *counter);
int					count_bits(int n);
int					get_bit(int number, int bit_position);
void				complex_sort(t_stack **stack_a, t_stack **stack_b,
						t_counter *counter);
void				adaptive_sort(t_stack **a, t_stack **b, t_counter *counter);
void				radix_sort(t_stack **a, t_stack **b, t_counter *counter);
void				assign_index(t_stack *stack_a);
int					ft_strcmp(char *s1, char *s2);
void				dispatch_sort(t_stack **a, t_stack **b, t_strategy strat,
						t_counter *counter);
void				sort_3(t_stack **a, t_counter *counter);
void				sort_5(t_stack **a, t_stack **b, t_counter *counter);
int					fill_stack(t_stack **stack_a, char **args, int must_free);
int					parse_flags(int argc, char **argv, t_strategy *strat,
						int *bench);
void				sort_and_bench(t_stack **a, t_stack **b, t_strategy strat,
						int bench);
void				ft_putnbr_fd(int n, int fd);
void				ft_putstr_fd(char *s, int fd);

#endif