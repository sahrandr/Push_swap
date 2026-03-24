/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahrandr <sahrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 16:52:35 by sahrandr          #+#    #+#             */
/*   Updated: 2026/02/07 15:02:05 by sahrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	find;

	find = (unsigned char)c;
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == find)
			return ((char *)s);
		s++;
	}
	if (*s == find)
		return ((char *)s);
	return (NULL);
}
