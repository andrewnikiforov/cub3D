/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nspiron <nspiron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 16:42:25 by omillan           #+#    #+#             */
/*   Updated: 2021/02/19 22:55:22 by nspiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list *tmp;

	if (!*lst)
	{
		*lst = new;
		return ;
	}
	if (!new)
		return ;
	tmp = ft_lstlast(*lst);
	tmp->next = new;
}
