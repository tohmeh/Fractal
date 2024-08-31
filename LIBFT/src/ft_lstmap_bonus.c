/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtohmeh <mtohmeh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 19:27:57 by mtohmeh           #+#    #+#             */
/*   Updated: 2024/08/22 18:51:27 by mtohmeh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/LIBFT.h"

t_void_list	*ft_lstmap(t_void_list *lst, void *(*f)(void *), void (*d)(void *))
{
	t_void_list	*new;

	new = NULL;
	while (lst)
	{
		ft_lstadd_back(&new, ft_lstnew(f(lst->content)));
		if (!new)
		{
			ft_lstclear(&new, d);
			return (NULL);
		}
		lst = lst->next;
	}
	return (new);
}
