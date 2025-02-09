/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufalzone <ufalzone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 16:39:28 by ufalzone          #+#    #+#             */
/*   Updated: 2024/11/29 19:31:27 by ufalzone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*new1;
	t_list	*result;

	if (!lst || !f)
		return (NULL);
	result = ft_lstnew(f(lst->content));
	new1 = lst->next;
	new = result;
	while (new1)
	{
		new->next = ft_lstnew((f)(new1->content));
		if (new->next == NULL)
		{
			ft_lstclear(&new, del);
			return (NULL);
		}
		new = new->next;
		new1 = new1->next;
	}
	return (result);
}

// int	main(void)
// {
// }

// result
// new 1
// new 2
// result = lst; on  y touche pas
// new = lst;
//
// while(new != NULL)
// new1 = (f)(new->content);
// free(new);
// new = new->next;
// return (result);