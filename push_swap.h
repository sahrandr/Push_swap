/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahrandr <sahrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 14:42:45 by sahrandr          #+#    #+#             */
/*   Updated: 2026/03/20 17:11:33 by sahrandr         ###   ########.fr       */
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

# define SA 1
# define SB 2
# define SS 3
# define PA 4
# define PB 5
# define RA 6
# define RB 7
# define RR 8
# define RRA 9
# define RRB 10
# define RRR 11

typedef struct s_stats
{
	int				total;
	int				count_sa;
	int				count_sb;
	int				count_ss;
	int				count_pa;
	int				count_pb;
	int				count_ra;
	int				count_rb;
	int				count_rr;
	int				count_rra;
	int				count_rrb;
	int				count_rrr;
}					t_stats;

t_stats		get_stats(void);
void		increment_stats(int op_type);

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
void				assign_index(t_stack *stack_a);
float				calculate_disorder(t_stack *stack_a);
void				process_bits(t_stack **stack_a, t_stack **stack_b, int bit);
void				sa(t_stack **a);
void				sb(t_stack **b);
void				ss(t_stack **a, t_stack **b);
void				pa(t_stack **a, t_stack **b);
void				pb(t_stack **a, t_stack **b);
void				ra(t_stack **a);
void				rb(t_stack **b);
void				rr(t_stack **a, t_stack **b);
void				rra(t_stack **a);
void				rrb(t_stack **b);
void				rrr(t_stack **a, t_stack **b);
int					find_min_position(t_stack *stack);
int					find_max_position(t_stack *stack);
void				bring_to_top(t_stack **stack, int position, int size);
void				simple_sort(t_stack **stack_a, t_stack **stack_b);
int					count_chunk(int size);
int					is_in_chunk(int index, int chunk_min, int chunk_max);
int					find_in_chunk(t_stack *stack, int chunk_min, int chunk_max);
void				medium_sort(t_stack **stack_a, t_stack **stack_b);
int					count_bits(int n);
int					get_bit(int number, int bit_position);
void				complex_sort(t_stack **stack_a, t_stack **stack_b);
void				adaptive_sort(t_stack **a, t_stack **b);
void				radix_sort(t_stack **a, t_stack **b);
void				assign_index(t_stack *stack_a);
int					ft_strcmp(char *s1, char *s2);
void				dispatch_sort(t_stack **a, t_stack **b, t_strategy strat);
void				sort_3(t_stack **a);
void				sort_5(t_stack **a, t_stack **b);
int					fill_stack(t_stack **stack_a, char **args, int must_free);
int					parse_flags(int argc, char **argv, t_strategy *strat,
							int *bench);
void				sort_and_bench(t_stack **a, t_stack **b, t_strategy strat,
							int bench);
void				ft_putnbr_fd(int n, int fd);
void				ft_putstr_fd(char *s, int fd);

#endif