/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_size.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mny-aro- <mny-aro-@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 14:44:02 by mny-aro-          #+#    #+#             */
/*   Updated: 2026/03/07 14:44:45 by mny-aro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_size(t_stack *stack) //comme  strlen mais pour les chaines.
{
	int	count;

	count = 0;
	while (stack != NULL)
	{
		count++;
		stack = stack ->next;
	}
	return (count);
}
