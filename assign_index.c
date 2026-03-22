/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_index.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahrandr <sahrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 13:40:25 by mny-aro-          #+#    #+#             */
/*   Updated: 2026/03/22 09:42:07 by sahrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	bubble_sort(int arr[], int n)//Cette fonction trie un tableau d'entiers par ordre croissant. Elle utilise l'algorithme du tri à bulles
{
	int	check;// Drapeau pour savoir si des échanges ont eu lieu.
	int	i;
	int	temp;

	check = 1;
	while (check)//tant que le tableau n'est pas trié
	{
		check = 0;
		i = 0;
		while (i < n - 1)//parcourir le tableau
		{
			if (arr[i] > arr[i + 1])//si l'élément courant est plus grand que le suivant, les échanger
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

static void	fill_tab(t_stack *stack, int *tab)//remplir le tableau d'entiers avec les valeurs de la pile
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

static void	set_indexes(t_stack *stack, int *tab, int size)//attribuer les index aux éléments de la pile en fonction de leur position dans le tableau trié
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
				break ;
			}
			i++;
		}
		stack = stack ->next;
	}
}

void	assign_index(t_stack *stack_a)//attribuer les index aux éléments de la pile a en fonction de leur position dans le tableau trié
{
	int	size;
	int	*tab;

	size = stack_size(stack_a);
	tab = malloc(sizeof(int) * size);
	if (!tab)
		return ;
	fill_tab(stack_a, tab);
	bubble_sort(tab, size);
	set_indexes(stack_a, tab, size);
	free(tab);
}
