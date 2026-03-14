/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_max_position.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mny-aro- <mny-aro-@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 10:33:06 by mny-aro-          #+#    #+#             */
/*   Updated: 2026/03/09 11:35:00 by mny-aro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_max_position(t_stack *stack) /*meme principe que min */
{
	int	max_value;
	int	max_pos;
	int	current_pos;

	if (!stack)
		return (-1);
	current_pos = 0;
	max_pos = 0;
	max_value = stack->value;
	while (stack)
	{
		if (stack->value > max_value)
		{
			max_value = stack->value;
			max_pos = current_pos;
		}
		current_pos++;
		stack = stack->next;
	}
	return (max_pos);
}
