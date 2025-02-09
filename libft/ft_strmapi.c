/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufalzone <ufalzone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 20:07:18 by ufalzone          #+#    #+#             */
/*   Updated: 2024/11/12 21:03:52 by ufalzone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*resultat;
	int		i;

	resultat = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!resultat)
		return (NULL);
	i = 0;
	while (s[i])
	{
		resultat[i] = f(i, s[i]);
		i++;
	}
	resultat[i] = '\0';
	return (resultat);
}
