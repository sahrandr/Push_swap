/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_index.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mny-aro- <mny-aro-@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 13:40:25 by mny-aro-          #+#    #+#             */
/*   Updated: 2026/03/13 11:13:28 by mny-aro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	bubble_sort(int arr[], int n)
{
	int	check;
	int	i;
	int	temp;

	check = 1;
	while (check)
	{
		check = 0;
		i = 0;
		while (i < n - 1)
		{
			if (arr[i] > arr[i + 1])
			{
				temp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = temp;
				check = 1;
			}
			i++;
		}
	}
}


static void	fill_tab(t_stack *stack, int *tab)
{
	int	i;

	i = 0;
	while (stack)
	{
		tab[i] = stack ->value;
		stack = stack->next;
		i++;
	}
}

static void	set_indexes(t_stack *stack, int *tab, int size)
{
	int	i;

	while (stack)
	{
		i = 0;
		while (i < size)
		{
			if (stack ->value == tab[i])
			{
				stack ->index = i;
				break;
			}
			i++;
		}
		stack = stack ->next;
	}
}

void	assign_index(t_stack *stack_a)
{
	int size;
	int *tab;

	size = stack_size(stack_a);
	tab = malloc(sizeof(int) * size);
	if (!tab)
		return ;
	fill_tab(stack_a, tab);
	bubble_sort(tab, size);
	set_indexes(stack_a, tab, size);
	free(tab);
}
