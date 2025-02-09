/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufalzone <ufalzone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 00:11:43 by ufalzone          #+#    #+#             */
/*   Updated: 2024/11/13 17:37:01 by ufalzone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *destination, const void *source, size_t size)
{
	size_t			i;
	unsigned char	*d;
	unsigned char	*s;

	i = 0;
	d = (unsigned char *)destination;
	s = (unsigned char *)source;
	if (!destination && !source && size)
		return (NULL);
	if (destination > source)
		while (size--)
			d[size] = s[size];
	else
	{
		while (i < size)
		{
			d[i] = s[i];
			i++;
		}
	}
	return (destination);
}
