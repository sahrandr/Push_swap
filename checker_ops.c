/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_ops.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahrandr <sahrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 17:35:00 by mny-aro-          #+#    #+#             */
/*   Updated: 2026/03/27 14:33:04 by sahrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static void	swap_local(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	second = (*stack)->next;
	first->next = second->next;
	second->next = first;
	*stack = second;
}

static void	push_local(t_stack **src, t_stack **dst)
{
	t_stack	*tmp;

	if (!src || !*src)
		return ;
	tmp = *src;
	*src = (*src)->next;
	tmp->next = *dst;
	*dst = tmp;
}

static void	rotate_local(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	*stack = (*stack)->next;
	first->next = NULL;
	last = *stack;
	while (last->next)
		last = last->next;
	last->next = first;
}

static void	reverse_rotate_local(t_stack **stack)
{
	t_stack	*last;
	t_stack	*before_last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	last = *stack;
	before_last = NULL;
	while (last->next)
	{
		before_last = last;
		last = last->next;
	}
	before_last->next = NULL;
	last->next = *stack;
	*stack = last;
}

int	do_instruction(char *line, t_stack **a, t_stack **b)
{
	if (!ft_strcmp(line, "sa"))
		swap_local(a);
	else if (!ft_strcmp(line, "sb"))
		swap_local(b);
	else if (!ft_strcmp(line, "ss"))
		return (swap_local(a), swap_local(b), 0);
	else if (!ft_strcmp(line, "pa"))
		push_local(b, a);
	else if (!ft_strcmp(line, "pb"))
		push_local(a, b);
	else if (!ft_strcmp(line, "ra"))
		rotate_local(a);
	else if (!ft_strcmp(line, "rb"))
		rotate_local(b);
	else if (!ft_strcmp(line, "rr"))
		return (rotate_local(a), rotate_local(b), 0);
	else if (!ft_strcmp(line, "rra"))
		reverse_rotate_local(a);
	else if (!ft_strcmp(line, "rrb"))
		reverse_rotate_local(b);
	else if (!ft_strcmp(line, "rrr"))
		return (reverse_rotate_local(a), reverse_rotate_local(b), 0);
	else
		return (1);
	return (0);
}
