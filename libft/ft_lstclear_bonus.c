/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufalzone <ufalzone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 16:22:37 by ufalzone          #+#    #+#             */
/*   Updated: 2024/11/29 19:31:33 by ufalzone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include <unistd.h>

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;
	t_list	*next;

	if (!lst || !del)
		return ;
	temp = *lst;
	if (!temp)
		return ;
	next = temp->next;
	while (temp != NULL)
	{
		next = temp->next;
		(*del)(temp->content);
		free(temp);
		temp = next;
	}
	*lst = NULL;
}

// void	ft_del(void *content)
// {
// 	free(content);
// }
// #include <stdio.h>
// #include <stdlib.h>

// int	main(void)
// {
// 	t_list *new = ft_lstnew(ft_strdup("test"));
// 	t_list *new1 = ft_lstnew(ft_strdup("test"));
// 	t_list *new2 = ft_lstnew(ft_strdup("test"));
// 	t_list *new3 = ft_lstnew(ft_strdup("test"));

// 	new->next = new1;
// 	new1->next = new2;
// 	new2->next = new3;

// 	ft_lstclear(&new, &ft_del);
// 	write(1, new->content, ft_strlen(new->content));
// }