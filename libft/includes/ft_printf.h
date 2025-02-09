/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufalzone <ufalzone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 16:35:53 by ufalzone          #+#    #+#             */
/*   Updated: 2024/11/18 14:55:41 by ufalzone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <limits.h>
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

// Fonction principale
int		ft_printf(const char *format, ...);

// Redirection
int		ft_redirect(char const format, va_list ap);

// Fonctions pour les nombres
int		ft_printf_putnbr(long n);
int		ft_printf_putnbr_unsigned(unsigned int n);

// Fonctions pour les strings
int		ft_printf_putchar(char c);
int		ft_printf_putstr(char *str);
size_t	ft_printf_strlen(const char *str);

// Fonctions pour l'hexadécimal
int		ft_printf_putnbr_base(size_t n, char *base);
int		ft_printf_putnbr_pointer(size_t n);

#endif