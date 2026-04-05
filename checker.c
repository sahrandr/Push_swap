/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mny-aro- <mny-aro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 15:04:59 by sahrandr          #+#    #+#             */
/*   Updated: 2026/04/04 20:29:39 by mny-aro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static int	read_and_apply(t_stack **a, t_stack **b)
{
	char	*line;

	line = read_instruction();
	while (line)
	{
		if (do_instruction(line, a, b))
			return (write(2, "Error\n", 6), free(line), 1);
		free(line);
		line = read_instruction();
	}
	return (0);
}

static int	prepare_args(int argc, char **argv, char ***args, int *must_free)
{
	*must_free = 0;
	if (argc != 2)
	{
		*args = argv + 1;
		return (0);
	}
	*args = ft_split_mod(argv[1], ' ');
	*must_free = 1;
	if (!*args || !(*args)[0])
	{
		write(2, "Error\n", 6);
		if (*args)
			free_split(*args);
		return (1);
	}
	return (0);
}

static void	print_result(t_stack *a, t_stack *b)
{
	if (is_sorted(a) && stack_size(b) == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	**args;
	int		must_free;

	a = NULL;
	b = NULL;
	if (argc < 2)
		return (0);
	if (prepare_args(argc, argv, &args, &must_free))
		return (1);
	if (checker_fill_stack(&a, args, must_free))
		return (1);
	if (must_free)
		free_split(args);
	if (read_and_apply(&a, &b))
		return (free_stack(&a), free_stack(&b), 1);
	print_result(a, b);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
