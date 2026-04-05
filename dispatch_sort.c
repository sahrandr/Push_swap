/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatch_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mny-aro- <mny-aro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 15:49:48 by mny-aro-          #+#    #+#             */
/*   Updated: 2026/04/01 00:59:01 by mny-aro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	dispatch_small(t_stack **a, t_stack **b, t_stats *stats, int size)
{
	stats->actual_strat = STRAT_SIMPLE;
	if (size == 2 && ((*a)->value > (*a)->next->value))
		sa(a, stats);
	else if (size == 3)
		sort_3(a, stats);
	else if (size == 4 || size == 5)
		sort_5(a, b, stats);
}

static void	dispatch_big(t_stack **a, t_stack **b, t_strategy strat,
			t_stats *stats)
{
	if (strat == STRAT_SIMPLE)
	{
		stats->actual_strat = STRAT_SIMPLE;
		simple_sort(a, b, stats);
	}
	else if (strat == STRAT_MEDIUM)
	{
		stats->actual_strat = STRAT_MEDIUM;
		medium_sort(a, b, stats);
	}
	else if (strat == STRAT_COMPLEX)
	{
		stats->actual_strat = STRAT_COMPLEX;
		complex_sort(a, b, stats);
	}
	else if (strat == STRAT_ADAPTIVE)
	{
		stats->actual_strat = STRAT_ADAPTIVE;
		adaptive_sort(a, b, stats);
	}
}

void	dispatch_sort(
			t_stack **a,
			t_stack **b,
			t_strategy strat,
			t_stats *stats)
{
	int	size;

	if (is_sorted(*a))
	{
		if (strat == STRAT_ADAPTIVE)
			stats->actual_strat = STRAT_SIMPLE;
		return ;
	}
	size = stack_size(*a);
	if (size <= 5 && (!(stats->mode & MODE_STRAT_SET)
			|| strat == STRAT_ADAPTIVE))
		dispatch_small(a, b, stats, size);
	else
		dispatch_big(a, b, strat, stats);
}
