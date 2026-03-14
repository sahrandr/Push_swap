/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mny-aro- <mny-aro-@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 16:21:03 by sahrandr          #+#    #+#             */
/*   Updated: 2026/03/14 07:28:18 by mny-aro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	check_overflow(int sign, long result, int *error)
{
	if ((sign == 1 && result > 2147483647)
		|| (sign == -1 && result > 2147483648))
		*error = 1;
}

int	ft_atoi(const char *nptr, int *error)
{
	int		i;
	int		sign;
	long	result;

	*error = 0;
	i = 0;
	sign = 1;
	result = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = result * 10 + (nptr[i] - '0');
		check_overflow(sign, result, error);
		i++;
	}
	if (nptr[i] != '\0')
		*error = 1;
	return ((int)(result * sign));
}
