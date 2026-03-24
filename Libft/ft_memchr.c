/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahrandr <sahrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 15:44:16 by sahrandr          #+#    #+#             */
/*   Updated: 2026/01/23 17:46:43 by sahrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*a;
	unsigned char	b;

	a = (unsigned char *)s;
	b = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (a[i] == b)
		{
			return ((void *)(a + i));
		}
		i++;
	}
	return (NULL);
}
