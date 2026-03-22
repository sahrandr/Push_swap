/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahrandr <sahrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 15:28:37 by sahrandr          #+#    #+#             */
/*   Updated: 2026/03/22 11:24:51 by sahrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_stack **a, t_counter *counter)
{
	int	top;
	int	mid;
	int	bot;

	top = (*a)->value;
	mid = (*a)->next->value;
	bot = (*a)->next->next->value;
	if (top > mid && mid < bot && top < bot)
		sa(a, counter);
	else if (top > mid && mid > bot)
	{
		sa(a, counter);
		rra(a, counter);
	}
	else if (top > mid && mid < bot && top > bot)
		ra(a, counter);
	else if (top < mid && mid > bot && top < bot)
	{
		sa(a, counter);
		ra(a, counter);
	}
	else if (top < mid && mid > bot && top > bot)
		rra(a, counter);
}

void	sort_5(t_stack **a, t_stack **b, t_counter *counter)
{
	int size;
	int pushed;

	size = stack_size(*a);
	pushed = 0;
	while (pushed < size - 3)
	{
		if ((*a)->index < size - 3)
		{
			pb(a, b, counter);
			pushed++;
		}
		else
			ra(a, counter);
	}
	sort_3(a, counter);
	if (stack_size(*b) == 2 && (*b)->value < (*b)->next->value)
		sb(b, counter);
	while (stack_size(*b) > 0)
		pa(a, b, counter);
}