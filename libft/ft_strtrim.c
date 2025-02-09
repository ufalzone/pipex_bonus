/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufalzone <ufalzone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 20:56:24 by ufalzone          #+#    #+#             */
/*   Updated: 2024/11/15 01:14:22 by ufalzone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	skip_start(char const *s1, char const *set)
{
	int		i;
	size_t	skip;

	i = 0;
	skip = 0;
	while (s1[i])
	{
		if (ft_strchr(set, s1[i]))
			skip++;
		else
			break ;
		i++;
	}
	return (skip);
}

static size_t	skip_end(char const *s1, char const *set)
{
	int		i;
	size_t	skip;

	i = ft_strlen(s1) - 1;
	skip = 0;
	while (i >= 0)
	{
		if (ft_strchr(set, s1[i]))
			skip++;
		else
			break ;
		i--;
	}
	return (skip);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*resultat;
	size_t	sk_start;
	size_t	sk_end;
	size_t	len;
	size_t	i;

	sk_start = skip_start(s1, set);
	sk_end = skip_end(s1, set);
	len = ft_strlen(s1);
	if (sk_start + sk_end >= len)
		len = 0;
	else
		len = len - (sk_start + sk_end);
	resultat = malloc(sizeof(char) * (len + 1));
	if (!resultat)
		return (NULL);
	i = 0;
	while (i < len)
	{
		resultat[i] = s1[sk_start + i];
		i++;
	}
	resultat[i] = '\0';
	return (resultat);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char *s1 = "  \t \t \n   \n\n\n\t";
// 	printf("%zu\n", skip_start(s1, " \n\t"));
// 	printf("%zu\n", skip_end(s1, " \n\t"));
// 	printf("%s\n", ft_strtrim(s1, " \n\t"));
// }