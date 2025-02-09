/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufalzone <ufalzone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 16:01:38 by ufalzone          #+#    #+#             */
/*   Updated: 2024/11/29 19:27:37 by ufalzone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/get_next_line.h"

int	check_buffer(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == '\n')
			return (0);
		i++;
	}
	return (1);
}

int	ft_lenbuffer(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (i + 1);
		i++;
	}
	return (-1);
}

char	*extract_line(char *s1)
{
	char	*line;
	int		len_line;
	int		i;

	if (!s1)
		return (NULL);
	i = 0;
	len_line = ft_lenbuffer(s1);
	if (len_line == -1)
		len_line = ft_strlen_gnl(s1);
	line = malloc(sizeof(char) * (len_line + 1));
	if (!line)
		return (NULL);
	line[len_line] = '\0';
	while (i < len_line)
	{
		line[i] = s1[i];
		i++;
	}
	return (line);
}

char	*update_stock(char *s1)
{
	char	*resultat;
	int		len_stock;
	int		i;
	int		j;

	if (!s1)
		return (NULL);
	i = 0;
	j = ft_lenbuffer(s1);
	if (j == -1)
		return (NULL);
	len_stock = ft_strlen_gnl(s1) - j;
	resultat = malloc(sizeof(char) * (len_stock + 1));
	if (!resultat)
		return (NULL);
	while (i < len_stock)
	{
		resultat[i] = s1[i + j];
		i++;
	}
	resultat[i] = '\0';
	return (resultat);
}
