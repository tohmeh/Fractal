/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtohmeh <mtohmeh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 17:36:57 by mtohmeh           #+#    #+#             */
/*   Updated: 2024/08/22 18:50:17 by mtohmeh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/LIBFT.h"

t_void_list	*ft_lstnew(void *content)
{
	t_void_list	*new;

	new = malloc(sizeof(t_void_list));
	new->content = content;
	new->next = NULL;
	return (new);
}
