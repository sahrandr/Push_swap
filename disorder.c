/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mny-aro- <mny-aro-@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 04:48:26 by mny-aro-          #+#    #+#             */
/*   Updated: 2026/03/07 14:57:53 by mny-aro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

float	calculate_disorder(t_stack *stack_a)
{
    int		mistakes;
    int		total_pairs;
	int		size;
    t_stack	*ptr1;
    t_stack	*ptr2;

    if (!stack_a || !stack_a->next) //Protection
        return (0.0);
    mistakes = 0;
    total_pairs = 0;
	size = stack_size(stack_a);
    ptr1 = stack_a;
	while (ptr1 && ptr1->index)
	{
		ptr2 = ptr1->next;
		while (ptr2)
		{
			total_pairs++;
			if (ptr1->value > ptr2->value)
				mistakes++;
			ptr2 = ptr2->next;
		}
		ptr1 = ptr1->next;
	}
	return ((float)mistakes / total_pairs);
}
