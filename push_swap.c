/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahrandr <sahrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 15:56:17 by sahrandr          #+#    #+#             */
/*   Updated: 2026/03/24 15:41:16 by sahrandr         ###   ########.fr       */
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

/* ... includes ... */

static void	print_disorder(float disorder)
{
    int	value;

    value = (int)(disorder * 10000 + 0.5f);
    ft_putstr_fd("[bench] disorder: ", 2);
    ft_putnbr_fd(value / 100, 2);
    ft_putstr_fd(".", 2);
    if (value % 100 < 10)
        ft_putstr_fd("0", 2);
    ft_putnbr_fd(value % 100, 2);
    ft_putstr_fd("%\n", 2);
}

static void	print_operations(t_counter counter)
{
    ft_putstr_fd("[bench] ", 2);
    ft_putstr_fd("sa: ", 2);
    ft_putnbr_fd(counter.sa, 2);
    ft_putstr_fd(", sb: ", 2);
    ft_putnbr_fd(counter.sb, 2);
    ft_putstr_fd(", ss: ", 2);
    ft_putnbr_fd(counter.ss, 2);
    ft_putstr_fd(", pa: ", 2);
    ft_putnbr_fd(counter.pa, 2);
    ft_putstr_fd(", pb: ", 2);
    ft_putnbr_fd(counter.pb, 2);
    ft_putstr_fd("\n[bench] ", 2);
    ft_putstr_fd("ra: ", 2);
    ft_putnbr_fd(counter.ra, 2);
    ft_putstr_fd(", rb: ", 2);
    ft_putnbr_fd(counter.rb, 2);
    ft_putstr_fd(", rr: ", 2);
    ft_putnbr_fd(counter.rr, 2);
    ft_putstr_fd(", rra: ", 2);
    ft_putnbr_fd(counter.rra, 2);
    ft_putstr_fd(", rrb: ", 2);
    ft_putnbr_fd(counter.rrb, 2);
    ft_putstr_fd(", rrr: ", 2);
    ft_putnbr_fd(counter.rrr, 2);
    ft_putstr_fd("\n", 2);
}

static void	print_benchmark(float disorder, t_strategy strat, t_counter counter)
{
    print_disorder(disorder);
    ft_putstr_fd("[bench] strategy: ", 2);
    
    if (strat == STRAT_ADAPTIVE)
    {
        if (counter.actual_strat == STRAT_SIMPLE)
            ft_putstr_fd("adaptive / O(n^2)\n", 2);
        else if (counter.actual_strat == STRAT_MEDIUM)
            ft_putstr_fd("adaptive / O(n√n)\n", 2);
        else
            ft_putstr_fd("adaptive / O(n log n)\n", 2);
    }
    else if (strat == STRAT_SIMPLE)
        ft_putstr_fd("simple / O(n^2)\n", 2);
    else if (strat == STRAT_MEDIUM)
        ft_putstr_fd("medium / O(n√n)\n", 2);
    else
        ft_putstr_fd("complex / O(n log n)\n", 2);

    ft_putstr_fd("[bench] total_ops: ", 2);
    ft_putnbr_fd(counter.total, 2);
    ft_putstr_fd("\n", 2);
    print_operations(counter);
}

void	sort_and_bench(t_stack **a, t_stack **b, t_strategy strat, int bench)
{
    float		disorder;
    t_counter	counter;

    counter = (t_counter){0};
    disorder = calculate_disorder(*a);
    if (stack_size(*a) > 1)
    {
        assign_index(*a);
        dispatch_sort(a, b, strat, &counter);
    }
    if (bench)
        print_benchmark(disorder, strat, counter);
}
