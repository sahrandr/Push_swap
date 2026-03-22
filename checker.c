/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahrandr <sahrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 15:04:59 by sahrandr          #+#    #+#             */
/*   Updated: 2026/03/22 11:24:22 by sahrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	do_instruction(char *line, t_stack **a, t_stack **b)
{
	if (!ft_strcmp(line, "sa"))
		sa(a, NULL);
	else if (!ft_strcmp(line, "sb"))
		sb(b, NULL);
	else if (!ft_strcmp(line, "ss"))
		ss(a, b, NULL);
	else if (!ft_strcmp(line, "ra"))
		ra(a, NULL);
	else if (!ft_strcmp(line, "rb"))
		rb(b, NULL);
	else if (!ft_strcmp(line, "pa"))
		pa(a, b, NULL);
	else if (!ft_strcmp(line, "pb"))
		pb(a, b, NULL);
	else if (!ft_strcmp(line, "rra"))
		rra(a, NULL);
	else if (!ft_strcmp(line, "rrb"))
		rrb(b, NULL);
	else if (!ft_strcmp(line, "rrr"))
		rrr(a, b, NULL);
	else
		return (1);
	return (0);
}

static int	handle_error(t_stack **stack_a, char **args, int must_free)
{
	write(2, "Error\n", 6);
	free_stack(stack_a);
	if (must_free)
		free_split(args);
	return (1);
}

static int	checker_fill_stack(t_stack **stack_a, char **args, int must_free)
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
		if (!new_node)
			return (handle_error(stack_a, args, must_free));
		ft_lstadd_back(stack_a, new_node);
		i++;
	}
	return (0);
}

static char	*read_instruction(void)
{
	char	buffer[100];
	char	c;
	int		i;
	int		rd;

	i = 0;
	rd = read(0, &c, 1);
	if (rd <= 0)
		return (NULL);
	while (rd > 0 && c != '\n' && i < 99) // securite du buffer
	{
		buffer[i++] = c;
		rd = read(0, &c, 1);
	}
	buffer[i] = '\0';
	return (ft_strdup(buffer));
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	*line;

	a = NULL;
	b = NULL;
	if (argc < 2)
		return (0);
	if (checker_fill_stack(&a, argv + 1, 0))
		return (1);
	line = read_instruction();
	while (line)
	{
		if (do_instruction(line, &a, &b))
			return (write(2, "Error\n", 6), free(line), 1);
		free(line);
		line = (read_instruction());
	}
	if (is_sorted(a) && stack_size(b) == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
