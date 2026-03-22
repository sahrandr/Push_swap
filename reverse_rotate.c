/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahrandr <sahrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 16:49:51 by sahrandr          #+#    #+#             */
/*   Updated: 2026/03/22 11:24:22 by sahrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate(t_stack **stack)
{
	t_stack	*up;
	t_stack	*before_the_end;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	up = *stack;
	before_the_end = NULL;
	while (up->next)
	{
		before_the_end = up;
		up = up->next;
	}
	before_the_end->next = NULL;
	up->next = *stack;
	*stack = up;
}

void	rra(t_stack **a, t_counter *counter)
{
	reverse_rotate(a);
	write(1, "rra\n", 4);
	if (counter)
	{
		counter->total++;
		counter->rra++;
	}
}

void	rrb(t_stack **b, t_counter *counter)
{
	reverse_rotate(b);
	write(1, "rrb\n", 4);
	if (counter)
	{
		counter->total++;
		counter->rrb++;
	}
}

void	rrr(t_stack **a, t_stack **b, t_counter *counter)
{
	reverse_rotate(a);
	reverse_rotate(b);
	write(1, "rrr\n", 4);
	if (counter)
	{
		counter->total++;
		counter->rrr++;
	}
}