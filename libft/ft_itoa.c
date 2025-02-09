/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufalzone <ufalzone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 19:33:15 by ufalzone          #+#    #+#             */
/*   Updated: 2024/11/15 01:13:38 by ufalzone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	size_itoa(int n)
{
	int	compteur;

	compteur = 0;
	if (n <= 0)
		compteur++;
	while (n != 0)
	{
		compteur++;
		n = n / 10;
	}
	return (compteur);
}

char	*ft_itoa(int n)
{
	char	*resultat;
	int		lenght;
	long	nb;

	nb = n;
	lenght = size_itoa(n);
	resultat = malloc(sizeof(char) * (lenght + 1));
	if (!resultat)
		return (NULL);
	resultat[lenght] = '\0';
	lenght--;
	if (nb < 0)
	{
		resultat[0] = '-';
		nb = -nb;
	}
	if (nb == 0)
		resultat[0] = '0';
	while (nb > 0)
	{
		resultat[lenght] = (nb % 10) + '0';
		nb = nb / 10;
		lenght--;
	}
	return (resultat);
}
