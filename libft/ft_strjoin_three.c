/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_three.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufalzone <ufalzone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 17:41:57 by ufalzone          #+#    #+#             */
/*   Updated: 2025/02/07 17:44:03 by ufalzone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strjoin_three(char const *s1, char const *s2, char const *s3)
{
	int		size_total;
	char	*resultat;
	int		i;
	int		j;
	int		k;

	if (!s1 || !s2 || !s3)
		return (NULL);
	size_total = (ft_strlen(s1) + ft_strlen(s2) + ft_strlen(s3));
	resultat = malloc(sizeof(char) * (size_total + 1));
	if (!resultat)
		return (NULL);
	i = 0;
	j = 0;
	k = 0;
	while (s1[i])
		resultat[k++] = s1[i++];
	while (s2[j])
		resultat[k++] = s2[j++];
	j = 0;
	while (s3[j])
		resultat[k++] = s3[j++];
	resultat[k] = '\0';
	return (resultat);
}
