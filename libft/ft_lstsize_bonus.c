/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufalzone <ufalzone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 03:09:30 by ufalzone          #+#    #+#             */
/*   Updated: 2024/11/29 19:31:25 by ufalzone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int	ft_lstsize(t_list *lst)
{
	int	compteur;

	compteur = 0;
	while (lst)
	{
		lst = lst->next;
		compteur++;
	}
	return (compteur);
}
