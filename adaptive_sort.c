/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahrandr <sahrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 10:24:24 by mny-aro-          #+#    #+#             */
/*   Updated: 2026/03/14 17:03:35 by sahrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_3(t_stack **a)
{
	int	top;
	int	mid;
	int	bot;

	top = (*a)->value;
	mid = (*a)->next->value;
	bot = (*a)->next->next->value;
	if (top > mid && mid < bot && top < bot)
		sa(a);
	else if (top > mid && mid > bot)
	{
		sa(a);
		rra(a);
	}
	else if (top > mid && mid < bot && top > bot)
		ra(a);
	else if (top < mid && mid > bot && top < bot)
	{
		sa(a);
		ra(a);
	}
	else if (top < mid && mid > bot && top > bot)
		rra(a);
}

static void	sort_5(t_stack **a, t_stack **b)
{
	int	size;
	int	pushed;

	size = stack_size(*a);
	pushed = 0;
	while (pushed < size - 3)
	{
		if ((*a)->index < size - 3)
		{
			pb(a, b);
			pushed++;
		}
		else
			ra(a);
	}
	sort_3(a);
	while (stack_size(*b) > 0)
		pa(a, b);
}
void	adaptive_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	size;

	size = stack_size(*stack_a);
	if (size == 2)
	{
		if ((*stack_a)->value > (*stack_a)->next->value)
			sa(stack_a);
	}
	else if (size == 3)
		sort_3(stack_a);
	else if (size <= 5)
		sort_5(stack_a, stack_b);
	else
		complex_sort(stack_a, stack_b);
}
