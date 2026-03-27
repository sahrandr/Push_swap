/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahrandr <sahrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 16:18:21 by sahrandr          #+#    #+#             */
/*   Updated: 2026/03/04 10:10:35 by sahrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack **stack)
{
	t_stack	*first;
	t_stack	*next;

	if (stack == NULL || *stack == NULL)
		return ;
	first = *stack;
	while (first != NULL)
	{
		next = first->next;
		free(first);
		first = next;
	}
	*stack = NULL;
}
