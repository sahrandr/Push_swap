/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mny-aro- <mny-aro-@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 15:28:37 by sahrandr          #+#    #+#             */
/*   Updated: 2026/03/26 17:26:59 by mny-aro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_stack **a, t_stats *stats)
{
	int	top;
	int	mid;
	int	bot;

	top = (*a)->value;
	mid = (*a)->next->value;
	bot = (*a)->next->next->value;
	if (top > mid && mid < bot && top < bot)
		sa(a, stats);
	else if (top > mid && mid > bot)
	{
		sa(a, stats);
		rra(a, stats);
	}
	else if (top > mid && mid < bot && top > bot)
		ra(a, stats);
	else if (top < mid && mid > bot && top < bot)
	{
		sa(a, stats);
		ra(a, stats);
	}
	else if (top < mid && mid > bot && top > bot)
		rra(a, stats);
}

void	sort_5(t_stack **a, t_stack **b, t_stats *stats)
{
	int	size;
	int	pushed;

	size = stack_size(*a);
	pushed = 0;
	while (pushed < size - 3)
	{
		if ((*a)->index < size - 3)
		{
			pb(a, b, stats);
			pushed++;
		}
		else
			ra(a, stats);
	}
	sort_3(a, stats);
	if (stack_size(*b) == 2 && (*b)->value < (*b)->next->value)
		sb(b, stats);
	while (stack_size(*b) > 0)
		pa(a, b, stats);
}
