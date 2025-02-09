/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufalzone <ufalzone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 18:00:42 by ufalzone          #+#    #+#             */
/*   Updated: 2025/01/21 18:46:09 by ufalzone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

long	ft_atol(const char *str)
{
	long	resultat;
	int		signe;

	resultat = 0;
	signe = 1;
	while (ft_isspace((int)*str))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			signe = -1;
		str++;
	}
	while (ft_isdigit((int)*str))
	{
		resultat = resultat * 10 + (*str - '0');
		str++;
	}
	return (resultat * signe);
}
