/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirect_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufalzone <ufalzone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 13:35:15 by ufalzone          #+#    #+#             */
/*   Updated: 2024/11/21 13:51:47 by ufalzone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int	ft_redirect(char const format, va_list ap)
{
	if (format == 'c')
		return (ft_printf_putchar(va_arg(ap, int)));
	if (format == 's')
		return (ft_printf_putstr(va_arg(ap, char *)));
	if (format == 'p')
		return (ft_printf_putnbr_pointer(va_arg(ap, size_t)));
	if (format == 'd' || format == 'i')
		return (ft_printf_putnbr(va_arg(ap, int)));
	if (format == 'u')
		return (ft_printf_putnbr_unsigned((unsigned int)va_arg(ap,
					unsigned int)));
	if (format == 'x')
		return (ft_printf_putnbr_base(va_arg(ap, unsigned int),
				"0123456789abcdef"));
	if (format == 'X')
		return (ft_printf_putnbr_base(va_arg(ap, unsigned int),
				"0123456789ABCDEF"));
	if (format == '%')
		return (ft_printf_putchar('%'));
	return (ft_printf_putchar(format));
}
