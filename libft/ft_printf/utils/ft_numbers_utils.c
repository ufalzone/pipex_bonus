/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numbers_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufalzone <ufalzone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 13:17:09 by ufalzone          #+#    #+#             */
/*   Updated: 2024/11/21 13:51:47 by ufalzone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int	ft_printf_putnbr(long n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		ft_printf_putchar('-');
		n = -n;
		i++;
	}
	if (n >= 10)
		i += ft_printf_putnbr(n / 10);
	ft_printf_putchar(n % 10 + '0');
	i++;
	return (i);
}

int	ft_printf_putnbr_unsigned(unsigned int n)
{
	int	i;

	i = 0;
	if (n >= 10)
		i += ft_printf_putnbr_unsigned(n / 10);
	ft_printf_putchar(n % 10 + '0');
	i++;
	return (i);
}
