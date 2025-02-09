/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufalzone <ufalzone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 23:53:54 by ufalzone          #+#    #+#             */
/*   Updated: 2024/11/13 14:08:36 by ufalzone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *pointer1, const void *pointer2, size_t size)
{
	size_t			i;
	unsigned char	*p1;
	unsigned char	*p2;

	i = 0;
	p1 = (unsigned char *)pointer1;
	p2 = (unsigned char *)pointer2;
	while (i < size)
	{
		if (p1[i] == p2[i])
			i++;
		else
			return ((int)p1[i] - p2[i]);
	}
	return (0);
}
