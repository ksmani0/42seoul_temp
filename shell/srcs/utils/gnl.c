/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseo <tseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 13:09:06 by tseo              #+#    #+#             */
/*   Updated: 2021/03/04 10:55:00 by tseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

char			*ft_strappend(char *s1, char *s2)
{
	char *tmp;

	if (!s1)
	{
		s1 = ft_strdup(s2);
		return (s1);
	}
	else
	{
		tmp = ft_strjoin(s1, s2);
		free(s1);
		s1 = tmp;
		return (s1);
	}
}

static int		get_line(char **strs, char **line, char *ptr, int fd)
{
	char *tmp;

	if (ptr != 0)
	{
		*ptr = 0;
		*line = ft_strdup(strs[fd]);
		tmp = ft_strdup(ptr + 1);
		free(strs[fd]);
		strs[fd] = tmp;
		return (1);
	}
	if (strs[fd] != 0)
	{
		*line = strs[fd];
		strs[fd] = 0;
	}
	else
		*line = ft_strdup("");
	return (0);
}

int				get_next_line(int fd, char **line)
{
	static char		*strs[MAX_FD];
	char			buf[GNL_BUFFER_SIZE + 1];
	int				rd_size;
	char			*ptr;

	if (fd < 0 || !line || GNL_BUFFER_SIZE < 1)
		return (-1);
	while ((ptr = ft_strchr(strs[fd], '\n')) == 0
			&& (rd_size = read(fd, buf, GNL_BUFFER_SIZE)) > 0)
	{
		buf[rd_size] = 0;
		strs[fd] = ft_strappend(strs[fd], buf);
	}
	if (rd_size < 0)
		return (-1);
	return (get_line(strs, line, ptr, fd));
}
