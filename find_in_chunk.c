/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_in_chunk.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mny-aro- <mny-aro-@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 10:50:18 by mny-aro-          #+#    #+#             */
/*   Updated: 2026/03/09 11:30:19 by mny-aro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_in_chunk(t_stack *stack, int chunk_min, int chunk_max)
{
    int	position;
	
	if (!stack)
		return (-1);
    position = 0;
	while (stack)
	{
		if (is_in_chunk(stack->index, chunk_min, chunk_max))
			return (position); /*trouver,on retourne sa position*/
		position++;
		stack = stack->next;
	}
    return (-1);
}