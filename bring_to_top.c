/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bring_to_top.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahrandr <sahrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 09:51:13 by mny-aro-          #+#    #+#             */
/*   Updated: 2026/03/22 11:24:51 by sahrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bring_to_top(t_stack **stack_a, int position, int size,
					t_counter *counter)
						// faire tourner la pile a pour amener l'élément à la position donnée en haut de la pile
{
	int rotation;

	rotation = 0;
	if (position <= (size / 2))
	{
		while (position > 0)
		{
			ra(stack_a, counter);
			position--;
		}
	}
	else
	{
		rotation = size - position;
		while (rotation > 0)
		{
			rra(stack_a, counter);
			rotation--;
		}
	}
}
