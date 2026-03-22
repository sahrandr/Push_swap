/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahrandr <sahrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 14:52:40 by sahrandr          #+#    #+#             */
/*   Updated: 2026/03/22 11:24:02 by sahrandr         ###   ########.fr       */
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

void	ra(t_stack **a, t_counter *counter)
{
	rotation(a);
	write(1, "ra\n", 3);
	if (counter)
	{
		counter->total++;
		counter->ra++;
	}
}

void	rb(t_stack **b, t_counter *counter)
{
	rotation(b);
	write(1, "rb\n", 3);
	if (counter)
	{
		counter->total++;
		counter->rb++;
	}
}

void	rr(t_stack **a, t_stack **b, t_counter *counter)
{
	rotation(a);
	rotation(b);
	write(1, "rr\n", 3);
	if (counter)
	{
		counter->total++;
		counter->rr++;
	}
}
