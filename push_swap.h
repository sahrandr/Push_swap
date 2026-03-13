/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahrandr <sahrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 14:42:45 by sahrandr          #+#    #+#             */
/*   Updated: 2026/03/13 08:10:44 by sahrandr         ###   ########.fr       */
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

t_stack		*create_node(int value);
void		free_stack(t_stack **stack);
int			ft_atoi(const char *nptr);
int			ft_isdi(char *str);
char		**ft_split_mod(char const *s, char c);
int			is_duplicate(t_stack *stack_a, int num);
int			main(int argc, char **argv);
void		free_split(char **tab);
char		*ft_substr(char const *s, unsigned int start, size_t len);
void		ft_lstadd_back(t_stack **stack, t_stack *new_node);
void		pa(t_stack **a, t_stack **b);
void		pb(t_stack **a, t_stack **b);
void		rra(t_stack **a);
void		rrb(t_stack **b);
void		rrr(t_stack **a, t_stack **b);
void		ra(t_stack **a);
void		rb(t_stack **b);
void		rr(t_stack **a, t_stack **b);
void		sa(t_stack **a);
void		sb(t_stack **b);
void		ss(t_stack **a, t_stack **b);

#endif