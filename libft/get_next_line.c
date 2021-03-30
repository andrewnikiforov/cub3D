/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omillan <omillan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 14:59:28 by omillan           #+#    #+#             */
/*   Updated: 2021/03/05 14:43:52 by omillan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*cust_ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;
	int		len;

	if (!s1 || !s2)
		return (NULL);
	len = 0;
	if (s1)
		len = ft_strlen(s1);
	if (s2)
		len += ft_strlen(s2);
	i = -1;
	j = -1;
	if (!(str = malloc((len + 1) * sizeof(char))))
		return (NULL);
	while (++i < (len + 1) && *(s1 + i))
		*(str + i) = *(s1 + i);
	while (i + ++j < len && *(s2 + j))
		*(str + i + j) = *(s2 + j);
	*(str + i + j) = '\0';
	free(s1);
	return (str);
}

char				*work_with_source(char *source, char **line)
{
	char			*tmp;
	char			*p_eol;

	tmp = ft_strdup(source);
	free(source);
	p_eol = ft_strchr(tmp, '\n');
	if (p_eol)
	{
		*p_eol = '\0';
		p_eol++;
	}
	*line = ft_strdup(tmp);
	source = ft_strdup(p_eol);
	free(tmp);
	return (source);
}

int					get_next_line(int fd, char **line)
{
	char			*buffer;
	static char		*source;
	int				file;

	file = 1;
	if (fd < 0 || !line || BUFFER_SIZE < 1 || !(buffer = malloc(sizeof(char) *
														(BUFFER_SIZE + 1))))
		return (-1);
	if (!source)
		source = ft_strdup("");
	while ((!(ft_strchr(source, '\n'))) &&
						(file = read(fd, buffer, BUFFER_SIZE)))
	{
		if (file < 0)
		{
			free(buffer);
			return (-1);
		}
		buffer[file] = '\0';
		source = cust_ft_strjoin(source, buffer);
	}
	free(buffer);
	source = work_with_source(source, line);
	return (file == 0) ? (0) : (1);
}
