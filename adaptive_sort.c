/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mny-aro- <mny-aro-@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 10:24:24 by mny-aro-          #+#    #+#             */
/*   Updated: 2026/03/22 16:12:07 by mny-aro-         ###   ########.fr       */
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
		return ;
	if (disorder < 0.2)
		simple_sort(a, b, stats);
	else if (disorder < 0.5)
		medium_sort(a, b, stats);
	else
		complex_sort(a, b, stats);
}
