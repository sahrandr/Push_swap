/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatch_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahrandr <sahrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 15:49:48 by mny-aro-          #+#    #+#             */
/*   Updated: 2026/03/20 17:19:29 by sahrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	dispatch_sort(t_stack **a, t_stack **b, t_strategy strat)
{
	int	size;

	size = stack_size(*a);
	if (size <= 5)
	{
		if (size == 2 && ((*a)->value > (*a)->next->value))
			sa(a);
		else if (size == 3)
			sort_3(a);
		else if (size == 4 || size == 5)
			sort_5(a, b);
		else
			return ;
	}
	else
	{
		if (strat == STRAT_SIMPLE)
			simple_sort(a, b);
		else if (strat == STRAT_MEDIUM)
			medium_sort(a, b);
		else if (strat == STRAT_COMPLEX)
			complex_sort(a, b);
		else if (strat == STRAT_ADAPTIVE)
			adaptive_sort(a, b);
	}
}
