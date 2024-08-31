/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtohmeh <mtohmeh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 19:19:08 by mtohmeh           #+#    #+#             */
/*   Updated: 2024/08/22 18:50:17 by mtohmeh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/LIBFT.h"

void	ft_lstclear(t_void_list **lst, void (*del)(void*))
{
	t_void_list	*temp;
	t_void_list	*temp2;

	temp = *lst;
	while (temp)
	{
		temp2 = temp;
		del(temp->content);
		temp2 = temp;
		temp = temp->next;
		free(temp2);
	}
	*lst = NULL;
}
