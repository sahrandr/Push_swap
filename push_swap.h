/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahrandr <sahrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 14:42:45 by sahrandr          #+#    #+#             */
/*   Updated: 2026/03/14 16:01:10 by sahrandr         ###   ########.fr       */
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

t_stack				*create_node(int value);
void				free_stack(t_stack **stack);
void				free_split(char **tab);
int					ft_atoi(const char *nptr, int *error);
int					ft_isdi(char *str);
char				**ft_split_mod(char const *s, char c);
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

#endif