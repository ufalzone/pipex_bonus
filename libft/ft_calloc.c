/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufalzone <ufalzone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 21:14:37 by ufalzone          #+#    #+#             */
/*   Updated: 2024/11/14 22:39:03 by ufalzone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	total;

	total = nmemb * size;
	if (nmemb && size && (total / nmemb) != size)
		return (NULL);
	ptr = malloc(total);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, total);
	return (ptr);
}

// void	*ft_calloc(size_t nmemb, size_t size)
// {
// 	void	*ptr;
// 	size_t	size_total;
// 	size_t	compteur;

// 	size_total = nmemb * size;
// 	if (nmemb && size && (size_total / nmemb) != size)
// 		return (NULL);
// 	ptr = malloc(size_total);
// 	if (!ptr)
// 		return (NULL);
// 	compteur = 0;
// 	while (compteur < size_total)
// 	{
// 		((unsigned char *)ptr)[compteur] = 0;
// 		compteur++;
// 	}
// 	return (ptr);
// }