/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bring_to_top.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mny-aro- <mny-aro-@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 09:51:13 by mny-aro-          #+#    #+#             */
/*   Updated: 2026/03/26 17:37:16 by mny-aro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bring_to_top(t_stack **stack_a, int position, int size, t_stats *stats)
{
	int	rotation;

	rotation = 0;
	if (position <= (size / 2))
	{
		while (position > 0)
		{
			ra(stack_a, stats);
			position--;
		}
	}
	else
	{
		rotation = size - position;
		while (rotation > 0)
		{
			rra(stack_a, stats);
			rotation--;
		}
	}
}
