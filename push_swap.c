/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahrandr <sahrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 15:56:17 by sahrandr          #+#    #+#             */
/*   Updated: 2026/03/20 17:13:55 by sahrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	fill_stack(t_stack **stack_a, char **args, int must_free)
{
	int	i;
	int	num;
	int	error;

	i = 0;
	while (args[i] != NULL)
	{
		error = (ft_isdi(args[i]) == 0);
		if (!error)
			num = ft_atoi(args[i], &error);
		if (!error && is_duplicate(*stack_a, num) == 1)
			error = 1;
		if (error)
		{
			write(2, "Error\n", 6);
			free_stack(stack_a);
			if (must_free)
				free_split(args);
			return (1);
		}
		ft_lstadd_back(stack_a, create_node(num));
		i++;
	}
	return (0);
}

int	parse_flags(int argc, char **argv, t_strategy *strat, int *bench)
{
	int	i;
	int	dst;

	i = 1;
	dst = 1;
	*strat = STRAT_ADAPTIVE;
	*bench = 0;
	while (i < argc)
	{
		if (argv[i][0] == '-' && argv[i][1] == '-')
		{
			if (!ft_strcmp(argv[i], "--simple"))
				*strat = STRAT_SIMPLE;
			else if (!ft_strcmp(argv[i], "--complex"))
				*strat = STRAT_COMPLEX;
			else if (!ft_strcmp(argv[i], "--bench"))
				*bench = 1;
		}
		else
			argv[dst++] = argv[i];
		i++;
	}
	return (dst);
}

static void	print_operations(t_stats stats)
{
	static char	*names[11] = {"sa: ", "sb: ", "ss: ", "pa: ", "pb: ", "ra: ",
			"rb: ", "rr: ", "rra: ", "rrb: ", "rrr: "};
	int			*ops;
	int			i;

	ops = &stats.count_sa;
	i = 0;
	while (i < 11)
	{
		ft_putstr_fd(names[i], 2);
		ft_putnbr_fd(ops[i], 2);
		ft_putstr_fd("\n", 2);
		i++;
	}
}

static void	print_benchmark(t_stats stats, float disorder, t_strategy strat)
{
	ft_putstr_fd("Disorder: ", 2);
	ft_putnbr_fd((int)(disorder * 100), 2);
	ft_putstr_fd("%\n", 2);
	if (strat == STRAT_SIMPLE)
		ft_putstr_fd("Strategy: Simple O(n^2)\n", 2);
	else if (strat == STRAT_COMPLEX)
		ft_putstr_fd("Strategy: Complex O(n log n)\n", 2);
	else
		ft_putstr_fd("Strategy: Adaptive\n", 2);
	ft_putstr_fd("Total operations: ", 2);
	ft_putnbr_fd(stats.total, 2);
	ft_putstr_fd("\n", 2);
	print_operations(stats);
}

void	sort_and_bench(t_stack **a, t_stack **b, t_strategy strat, int bench)
{
	float	disorder;

	disorder = calculate_disorder(*a);
	if (stack_size(*a) > 1)
	{
		assign_index(*a);
		dispatch_sort(a, b, strat);
	}
	if (bench)
		print_benchmark(get_stats(), disorder, strat);
}
