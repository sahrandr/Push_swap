/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_disorder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahrandr <sahrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 08:09:50 by sahrandr          #+#    #+#             */
/*   Updated: 2026/03/27 08:18:18 by sahrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_disorder(float disorder)
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
