/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omillan <omillan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 16:42:39 by omillan           #+#    #+#             */
/*   Updated: 2021/03/05 14:42:52 by omillan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, char *l)
{
	t_list *tmp;

	if (!*lst)
		return ;
	while (*lst)
	{
		tmp = *lst;
		*lst = tmp->next;
		free(tmp->content);
		free(tmp);
	}
	free(l);
	*lst = NULL;
}

void	ft_lstclear_sec(t_list **lst)
{
	t_list *tmp;

	if (!*lst)
		return ;
	while (*lst)
	{
		tmp = *lst;
		*lst = tmp->next;
		free(tmp->content);
		free(tmp);
	}
	*lst = NULL;
}
