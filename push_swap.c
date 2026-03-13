/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahrandr <sahrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 15:56:17 by sahrandr          #+#    #+#             */
/*   Updated: 2026/03/10 17:09:23 by sahrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		i;
	t_stack	*new_node;
	int		num;
	char	**args;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		return (0);
	// write(1, "Debut du programme\n", 19);
	i = 0;       // par defaut
	args = NULL; // par defaut
	if (argc == 2)
	{
		// write(1, "Mode Split\n", 11);
		args = ft_split_mod(argv[1], ' ');
		if (!args)
			return (1);
	}
	else
	{
		// write(1, "Mode Normal\n", 12);
		args = argv;
		i = 1;
	}
	// write(1, "Debut boucle\n", 13);
	while (args[i] != NULL)
	{
		// if (!ft_isdi(argv[i]) || is_duplicate(stack_a, ft_atoi(argv[i])))
		// 	return (free_stack(&stack_a), write(2, "Error\n", 6));
		if (ft_isdi(args[i]) == 0)
		{
			write(2, "Error\n", 6);
			if (argc == 2)
				free_split(args);
			free_stack(&stack_a);
			return (1);
		}
		num = ft_atoi(args[i]);
		if (is_duplicate(stack_a, num) == 1)
		{
			write(1, "Error\n", 6);
			free_split(args);
			free_stack(&stack_a);
			if (argc == 2)
				free_split(args);
			return (1);
		}
		new_node = create_node(num);
		ft_lstadd_back(&stack_a, new_node);
		i++;
	}
	write(1, "\nFin boucle\n", 12);
	// AFFICHAGE FINAL (CE QUE TU VEUX VOIR)
	// printf("RESULTAT : ");
	// t_stack *tmp = stack_a;
	// while (tmp)
	// {
	//     printf("%d ", tmp->value);
	//     tmp = tmp->next;
	// }
	// printf("\n");
	if (argc == 2)
		free_split(args);
	free_stack(&stack_a);
	// write(1, "START\n", 6);
	return (0);
}
