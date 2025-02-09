/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufalzone <ufalzone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 13:19:13 by ufalzone          #+#    #+#             */
/*   Updated: 2024/11/21 13:51:46 by ufalzone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int	ft_printf_putnbr_base(size_t n, char *base)
{
	int	i;

	i = 0;
	if (n >= 16)
		i += ft_printf_putnbr_base(n / 16, base);
	ft_printf_putchar(base[n % 16]);
	i++;
	return (i);
}

int	ft_printf_putnbr_pointer(size_t n)
{
	int		i;
	char	*base;

	i = 0;
	if (n == 0)
		return (ft_printf_putstr("(nil)"));
	i += ft_printf_putstr("0x");
	base = "0123456789abcdef";
	if (n >= 16)
		i += ft_printf_putnbr_base(n / 16, base);
	ft_printf_putchar(base[n % 16]);
	i++;
	return (i);
}
