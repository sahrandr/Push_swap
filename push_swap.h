/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahrandr <sahrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 14:42:45 by sahrandr          #+#    #+#             */
/*   Updated: 2026/03/27 11:40:10 by sahrandr         ###   ########.fr       */
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

# define MODE_BENCH 1
# define MODE_COUNT_ONLY 2

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
	int				print_ops;
	t_strategy		actual_strat;
}					t_stats;

typedef struct s_ctx
{
	t_stack			*a;
	t_stack			*b;
	t_stats			stats;
	t_strategy		strat;
	int				mode;
}					t_ctx;

void				init_stats(t_stats *stats);
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
void				process_bits(t_stack **a, t_stack **b, int bit, t_stats *s);
void				sa(t_stack **a, t_stats *stats);
void				sb(t_stack **b, t_stats *stats);
void				ss(t_stack **a, t_stack **b, t_stats *stats);
void				pa(t_stack **a, t_stack **b, t_stats *stats);
void				pb(t_stack **a, t_stack **b, t_stats *stats);
void				ra(t_stack **a, t_stats *stats);
void				rb(t_stack **b, t_stats *stats);
void				rr(t_stack **a, t_stack **b, t_stats *stats);
void				rra(t_stack **a, t_stats *stats);
void				rrb(t_stack **b, t_stats *stats);
void				rrr(t_stack **a, t_stack **b, t_stats *stats);
int					find_min_position(t_stack *stack);
int					find_max_position(t_stack *stack);
void				bring_to_top(t_stack **s, int pos, int size, t_stats *st);
void				simple_sort(t_stack **a, t_stack **b, t_stats *stats);
int					count_chunk(int size);
int					is_in_chunk(int index, int chunk_min, int chunk_max);
int					find_in_chunk(t_stack *stack, int chunk_min, int chunk_max);
void				medium_sort(t_stack **a, t_stack **b, t_stats *stats);
int					count_bits(int n);
int					get_bit(int number, int bit_position);
void				complex_sort(t_stack **a, t_stack **b, t_stats *stats);
void				adaptive_sort(t_stack **a, t_stack **b, t_stats *stats);
int					ft_strcmp(char *s1, char *s2);
void				dispatch_sort(t_stack **a, t_stack **b, t_strategy st,
						t_stats *s);
void				sort_3(t_stack **a, t_stats *stats);
void				sort_5(t_stack **a, t_stack **b, t_stats *stats);
int					fill_stack(t_stack **stack_a, char **args, int must_free);
int					parse_flags(int ac, char **av, t_strategy *st, int *m);
void				sort_and_bench(t_stack **a, t_stack **b, t_strategy st,
						int m);
void				ft_putnbr_fd(int n, int fd);
void				ft_putstr_fd(char *s, int fd);
void				print_disorder(float disorder);

#endif
