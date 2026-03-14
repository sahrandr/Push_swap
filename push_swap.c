/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahrandr <sahrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 15:56:17 by sahrandr          #+#    #+#             */
/*   Updated: 2026/03/14 16:34:19 by sahrandr         ###   ########.fr       */
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
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**args;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		return (0);
	if (argc == 2)
		args = ft_split_mod(argv[1], ' ');
	else
		args = argv + 1;
	if (!args)
		return (1);
	if (fill_stack(&stack_a, args, (argc == 2)))
		return (1);
	if (stack_size(stack_a) > 1)
	{
		assign_index(stack_a);
		adaptive_sort(&stack_a, &stack_b);
	}
	if (argc == 2)
		free_split(args);
	return (free_stack(&stack_a), free_stack(&stack_b), 0);
}
