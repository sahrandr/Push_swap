/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mny-aro- <mny-aro-@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 14:22:35 by mny-aro-          #+#    #+#             */
/*   Updated: 2026/03/26 17:20:30 by mny-aro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	complex_sort(t_stack **stack_a, t_stack **stack_b, t_stats *stats)
{
	int	bits;
	int	current_bit;

	if (!*stack_a || !(*stack_a)->next)
		return ;
	bits = count_bits(stack_size(*stack_a));
	current_bit = 0;
	while (current_bit < bits)
	{
		process_bits(stack_a, stack_b, current_bit, stats);
		current_bit++;
	}
}
