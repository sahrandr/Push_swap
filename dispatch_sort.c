/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatch_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mny-aro- <mny-aro-@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 15:49:48 by mny-aro-          #+#    #+#             */
/*   Updated: 2026/03/26 17:29:17 by mny-aro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	dispatch_sort(
			t_stack **a,
			t_stack **b,
			t_strategy strat,
			t_stats *stats)
{
	int	size;

	size = stack_size(*a);
	if (size <= 5)
	{
		if (size == 2 && ((*a)->value > (*a)->next->value))
			sa(a, stats);
		else if (size == 3)
			sort_3(a, stats);
		else if (size == 4 || size == 5)
			sort_5(a, b, stats);
		else
			return ;
	}
	else
	{
		if (strat == STRAT_SIMPLE)
			simple_sort(a, b, stats);
		else if (strat == STRAT_MEDIUM)
			medium_sort(a, b, stats);
		else if (strat == STRAT_COMPLEX)
			complex_sort(a, b, stats);
		else if (strat == STRAT_ADAPTIVE)
			adaptive_sort(a, b, stats);
	}
}
