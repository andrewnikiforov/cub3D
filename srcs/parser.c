/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omillan <omillan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 12:00:19 by omillan           #+#    #+#             */
/*   Updated: 2021/03/30 15:00:22 by omillan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int				last_trim(char *s, t_all *all, t_list *head)
{
	int	i;

	i = 0;
	while (s && s[i] && s[i] == ' ')
		i++;
	if (s && *s == '\0')
	{
		free(s);
		ft_lstclear_sec(&head);
		put_error(4);
		exit_all(all, 0);
	}
	return (i);
}

int				last_str(t_list *head, char *l, t_all *all)
{
	last_trim(l, all, head);
	ft_lstadd_back(&head, ft_lstnew(l));
	free(l);
	return (0);
}

char			**get_map(t_list *head, t_all *all)
{
	char	**map;
	t_list	*tmp;
	int		j;

	if (head == 0)
		return (0);
	if (!(map = malloc((ft_lstsize(head) + 1) * sizeof(char *))))
		return (0);
	map[ft_lstsize(head)] = 0;
	j = -1;
	tmp = head;
	while (tmp)
	{
		map[++j] = ft_strdup(tmp->content);
		tmp = tmp->next;
	}
	ft_lstclear_sec(&head);
	if (plr_num(all, map) == -1)
	{
		num_str_free_arr(map, 2);
		return (0);
	}
	return (map);
}

t_list			*ft_ft(char *line)
{
	free(line);
	return (0);
}

t_list			*parser(int fd, t_all *all)
{
	t_list	*head;
	char	*l;
	int		j;

	j = 0;
	head = 0;
	l = 0;
	while (get_next_line(fd, &l) == 1)
	{
		if (trim(l, all) == -1)
			continue ;
		if (++j == 8)
			all->f->m++;
		if (j > 8)
		{
			if (check_flags(all) == -1)
				return (ft_ft(l));
			ft_lstadd_back(&head, ft_lstnew(l));
		}
		else if (map_elements(l + trim(l, all), all, trim(l, all)) == -1)
			return (0);
	}
	last_trim(l, all, head);
	ft_lstadd_back(&head, ft_lstnew(l));
	return (head);
}
