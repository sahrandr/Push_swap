/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_parse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahrandr <sahrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 17:35:00 by mny-aro-          #+#    #+#             */
/*   Updated: 2026/03/27 14:32:51 by sahrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static int	handle_error(t_stack **stack_a, char **args, int must_free)
{
	write(2, "Error\n", 6);
	free_stack(stack_a);
	if (must_free)
		free_split(args);
	return (1);
}

static int	add_number(t_stack **stack_a, char *arg, char **args, int must_free)
{
	int		num;
	int		error;
	t_stack	*new_node;

	if (ft_isdi(arg) == 0)
		return (handle_error(stack_a, args, must_free));
	num = ft_atoi(arg, &error);
	if (error == 1)
		return (handle_error(stack_a, args, must_free));
	if (is_duplicate(*stack_a, num) == 1)
		return (handle_error(stack_a, args, must_free));
	new_node = create_node(num);
	if (!new_node)
		return (handle_error(stack_a, args, must_free));
	ft_lstadd_back(stack_a, new_node);
	return (0);
}

int	checker_fill_stack(t_stack **stack_a, char **args, int must_free)
{
	int	i;

	i = 0;
	while (args[i] != NULL)
	{
		if (args[i][0] == '\0')
		{
			i++;
			continue ;
		}
		if (add_number(stack_a, args[i], args, must_free))
			return (1);
		i++;
	}
	return (0);
}

char	*read_instruction(void)
{
	char	buffer[100];
	char	c;
	int		i;
	int		rd;

	i = 0;
	rd = read(0, &c, 1);
	if (rd <= 0)
		return (NULL);
	while (rd > 0 && c != '\n' && i < 99)
	{
		buffer[i++] = c;
		rd = read(0, &c, 1);
	}
	buffer[i] = '\0';
	return (ft_strdup(buffer));
}
