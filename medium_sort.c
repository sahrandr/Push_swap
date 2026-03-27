/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mny-aro- <mny-aro-@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 09:48:11 by mny-aro-          #+#    #+#             */
/*   Updated: 2026/03/26 17:29:26 by mny-aro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_max_to_a(
			t_stack **stack_a,
			t_stack **stack_b,
			t_stats *stats)
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
				rb(stack_b, stats);
		}
		else
		{
			rot = size - max_pos;
			while (rot-- > 0)
				rrb(stack_b, stats);
		}
		pa(stack_a, stack_b, stats);
	}
}

static void	push_chunks_to_b(
			t_stack **stack_a,
			t_stack **stack_b,
			t_stats *stats)
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
			bring_to_top(stack_a, position, stack_size(*stack_a), stats);
			pb(stack_a, stack_b, stats);
		}
	}
}

void	medium_sort(t_stack **stack_a, t_stack **stack_b, t_stats *stats)
{
	if (!*stack_a || !(*stack_a)->next)
		return ;
	push_chunks_to_b(stack_a, stack_b, stats);
	push_max_to_a(stack_a, stack_b, stats);
}
