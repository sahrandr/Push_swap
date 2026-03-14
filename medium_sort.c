/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mny-aro- <mny-aro-@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 09:48:11 by mny-aro-          #+#    #+#             */
/*   Updated: 2026/03/13 16:19:02 by mny-aro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_max_to_a(t_stack **stack_a, t_stack **stack_b)
{
	int	max_pos;
	int	size;

	while (*stack_b)
	{
		size = stack_size(*stack_b);
		max_pos = find_max_position(*stack_b);
		bring_to_top(stack_b, max_pos, size);
		pa(stack_a, stack_b);
	}
}

static void	push_chunks_to_b(t_stack **stack_a, t_stack **stack_b)
{
	int	chunk_size;
	int	current_chunk;
	int	position;
	int	chunk_max;
	int	chunk_min;

	chunk_size = stack_size(*stack_a) / count_chunk(stack_size(*stack_a));
	current_chunk = 0;
	while (*stack_a)
	{
		chunk_min = current_chunk * chunk_size;
		chunk_max = chunk_min + chunk_size - 1;
		position = find_in_chunk(*stack_a, chunk_min, chunk_max);
		if (position == -1)
			current_chunk++;
		else
		{
			bring_to_top(stack_a, position, stack_size(*stack_a));
			pb(stack_a, stack_b);
		}
	}
}

void	medium_sort(t_stack **stack_a, t_stack **stack_b)
{
	if (!*stack_a || !(*stack_a)->next)
		return ;
	push_chunks_to_b(stack_a, stack_b);
	push_max_to_a(stack_a, stack_b);
}
