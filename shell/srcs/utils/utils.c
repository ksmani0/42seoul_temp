/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseo <tseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 22:51:52 by jaeelee           #+#    #+#             */
/*   Updated: 2021/03/18 21:47:56 by jaeelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_arrsize(char **arr)
{
	int	cnt;

	cnt = 0;
	while (arr[cnt])
		cnt++;
	return (cnt);
}

void	free_double_arr(char **arr)
{
	int i;

	i = -1;
	while (arr[++i])
		free(arr[i]);
	free(arr);
}

char	*find_path(char *cmd)
{
	int			i;
	char		*temp;
	char		*path;
	char		**paths;
	struct stat	buf;

	if ((temp = search_env("PATH")) == NULL)
		return (cmd);
	paths = ft_split(temp, ':');
	i = -1;
	while (paths[++i])
	{
		temp = ft_strjoin("/", cmd);
		path = ft_strjoin(paths[i], temp);
		free(temp);
		if (stat(path, &buf) == 0)
		{
			cmd = path;
			break ;
		}
		free(path);
	}
	free_double_arr(paths);
	return (cmd);
}
