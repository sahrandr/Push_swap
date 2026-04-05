/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_min_position.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mny-aro- <mny-aro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 20:28:47 by mny-aro-          #+#    #+#             */
/*   Updated: 2026/03/31 20:40:56 by mny-aro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min_position(t_stack *stack)
{
	int	min_value;
	int	min_pos;
	int	current_pos;

	if (!stack)
		return (-1);
	current_pos = 0;
	min_pos = 0;
	min_value = stack->value;
	while (stack)
	{
		if (stack->value < min_value)
		{
			min_value = stack->value;
			min_pos = current_pos;
		}
		current_pos++;
		stack = stack->next;
	}
	return (min_pos);
}
