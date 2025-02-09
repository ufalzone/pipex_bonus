/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strings_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufalzone <ufalzone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 13:19:50 by ufalzone          #+#    #+#             */
/*   Updated: 2024/11/21 13:51:48 by ufalzone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int	ft_printf_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

size_t	ft_printf_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_printf_putstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (ft_printf_putstr("(null)"));
	while (str[i])
	{
		ft_printf_putchar(str[i]);
		i++;
	}
	return (i);
}
