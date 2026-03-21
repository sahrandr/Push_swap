/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahrandr <sahrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 09:48:11 by mny-aro-          #+#    #+#             */
/*   Updated: 2026/03/21 11:01:44 by sahrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_max_to_a(t_stack **stack_a, t_stack **stack_b)
{
	int	max_pos;
	int	size;
	int	rot;

	while (*stack_b)
	{
		size = stack_size(*stack_b);
		max_pos = find_max_position(*stack_b);
		if (max_pos <= (size / 2))
		{
			while (max_pos-- > 0)
				rb(stack_b);
		}
		else
		{
			rot = size - max_pos;
			while (rot-- > 0)
				rrb(stack_b);
		}
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
