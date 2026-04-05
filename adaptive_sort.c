/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mny-aro- <mny-aro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 10:24:24 by mny-aro-          #+#    #+#             */
/*   Updated: 2026/03/30 12:51:42 by mny-aro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	adaptive_sort(t_stack **a, t_stack **b, t_stats *stats)
{
	float	disorder;

	if (!*a || !(*a)->next)
		return ;
	disorder = calculate_disorder(*a);
	if (disorder == 0)
	{
		stats->actual_strat = STRAT_SIMPLE;
		return ;
	}
	if (disorder < 0.2)
	{
		stats->actual_strat = STRAT_SIMPLE;
		simple_sort(a, b, stats);
	}
	else if (disorder < 0.5)
	{
		stats->actual_strat = STRAT_MEDIUM;
		medium_sort(a, b, stats);
	}
	else
	{
		stats->actual_strat = STRAT_COMPLEX;
		complex_sort(a, b, stats);
	}
}
