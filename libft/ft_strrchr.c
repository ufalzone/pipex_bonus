/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufalzone <ufalzone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 23:27:44 by ufalzone          #+#    #+#             */
/*   Updated: 2024/11/12 21:29:46 by ufalzone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strrchr(const char *s, int c)
{
	const char	*resultat;

	resultat = NULL;
	while (*s)
	{
		if (*s == (char)c)
			resultat = s;
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return ((char *)resultat);
}
