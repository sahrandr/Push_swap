/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahrandr <sahrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 14:52:40 by sahrandr          #+#    #+#             */
/*   Updated: 2026/03/20 15:07:10 by sahrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotation(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;

	if (!stack || !(*stack) || !(*stack)->next)
		return ;
	first = *stack;
	*stack = (*stack)->next;
	first->next = NULL;
	last = *stack;
	while (last->next)
		last = last->next;
	last->next = first;
}

void	ra(t_stack **a)
{
	rotation(a);
	write(1, "ra\n", 3);
	increment_stats(RA);
}

void	rb(t_stack **b)
{
	rotation(b);
	write(1, "rb\n", 3);
	increment_stats(RB);
}

void	rr(t_stack **a, t_stack **b)
{
	rotation(a);
	rotation(b);
	write(1, "rr\n", 3);
	increment_stats(RR);
}
