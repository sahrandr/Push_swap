/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_index.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mny-aro- <mny-aro-@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 13:40:25 by mny-aro-          #+#    #+#             */
/*   Updated: 2026/03/07 14:43:43 by mny-aro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	bubble_sort(int arr[], int n) //Tri a bulle
{
	int	check; //verification
	int	i; //index
	int	temp; //pour le swap

	check = 1; //on l'initialise a 1
	while (check)
	{
		check = 0;
		i = 0;
		while (i < n - 1)
		{
			if (arr[i] > arr[i + 1]) // on swap si par ex 1 est avant 2 
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


static void	fill_tab(t_stack *stack, int *tab) // completion du tableau
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

static void	set_indexes(t_stack *stack, int *tab, int size) // ajout des indexes c-a-d le tab [tab[0], tab[1], ...] devient -> [0, 1, 2, ...] ou tab[0] = 0 et ainsi de suite
{
	int	i;

	while (stack)
	{
		i = 0;
		while (i < size);
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


void	assign_index(t_stack *stack_a) // la fonction prinipale d'indexation
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
