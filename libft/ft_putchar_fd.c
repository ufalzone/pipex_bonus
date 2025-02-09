/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufalzone <ufalzone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 20:24:14 by ufalzone          #+#    #+#             */
/*   Updated: 2024/11/12 20:57:46 by ufalzone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// 0 	Entrée standard 	STDIN_FILENO 	stdin
// 1 	Sortie standard 	STDOUT_FILENO 	stdout
// 2 	Erreur standard 	STDERR_FILENO 	stderr

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
