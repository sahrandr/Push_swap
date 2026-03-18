/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahrandr <sahrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 15:56:17 by sahrandr          #+#    #+#             */
/*   Updated: 2026/03/18 13:16:22 by sahrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	handle_error(t_stack **stack_a, char **args, int must_free)
{
	write(2, "Error\n", 6);
	free_stack(stack_a);
	if (must_free)
		free_split(args);
	return (1);
}

static int	fill_stack(t_stack **stack_a, char **args, int must_free)
{
	int		i;
	int		num;
	int		error;
	t_stack	*new_node;

	i = 0;
	while (args[i] != NULL)
	{
		if (ft_isdi(args[i]) == 0)
			return (handle_error(stack_a, args, must_free));
		num = ft_atoi(args[i], &error);
		if (error == 1)
			return (handle_error(stack_a, args, must_free));
		if (is_duplicate(*stack_a, num) == 1)
			return (handle_error(stack_a, args, must_free));
		new_node = create_node(num);
		ft_lstadd_back(stack_a, new_node);
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_stack *a;
	t_stack *b;
	t_strategy strat = STRAT_ADAPTIVE;
	char **args;
	int i;
	int bench;
	int dst;

	i = 1;
	bench = 0;
	dst = 1;
	a = NULL;
	b = NULL;

	while (i < argc)
	{
		if (argc && argv[i][0] == '-' && argv[i][1] == '-')
		{
			if (!ft_strcmp(argv[i], "--simple"))
				strat = STRAT_SIMPLE;
			if (!ft_strcmp(argv[i], "--complex"))
				strat = STRAT_COMPLEX;
			if (!ft_strcmp(argv[i], "--bench"))
				bench = 1;
		}
		else//pas de -- dans le argv
			argv[dst++] = argv[i];
		i++;
	}
		argc = dst;//le programmes oublie les argument apres le flag
		if (argc == 1)
			return (0);
		if (argc == 2)
			args = ft_split_mod(argv[1], ' ');
		else
			args = argv + 1;
		if (!args || fill_stack(&a, args, (argc == 2)))
			return (1);
		if (stack_size(a) > 1) 
			assign_index(a); 
			dispatch_sort(&a, &b, strat);
		if (bench) print_benchmark();
		    if (argc == 2) free_split(args);
		return (free_stack(&a), free_stack(&b), 0);
	}
