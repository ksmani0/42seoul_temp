/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeelee <jaeelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 23:30:33 by jaeelee           #+#    #+#             */
/*   Updated: 2021/03/18 16:32:45 by jaeelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	is_there_env(char **arg, char *env)
{
	int	i;
	int	len;

	i = -1;
	while (arg[++i])
	{
		len = ft_strlen(arg[i]);
		if (strncmp(arg[i], env, len) == 0 &&
				(env[len] == '=' || env[len] == '\0'))
			return (1);
	}
	return (0);
}

static void	delete_env(char **arg)
{
	char	**temp;
	int		i;
	int		cnt;

	i = ft_arrsize(g_envs);
	if (!(temp = (char **)malloc(sizeof(char *) * (i + 1))))
		exit(EXIT_FAILURE);
	i = -1;
	cnt = 0;
	while (g_envs[++i])
	{
		if (!is_there_env(arg, g_envs[i]))
			temp[cnt++] = ft_strdup(g_envs[i]);
		free(g_envs[i]);
		g_envs[i] = NULL;
	}
	temp[cnt] = NULL;
	free(g_envs);
	g_envs = temp;
}

int			ft_unset(char **cmd_line)
{
	int		i;
	int		cnt;
	int		ret;
	char	**unset;

	ret = 0;
	cnt = ft_arrsize(cmd_line);
	unset = (char **)malloc(sizeof(char *) * (cnt + 1));
	i = 0;
	cnt = 0;
	while (cmd_line[++i])
	{
		if (check_validkey(cmd_line[i]) != (int)ft_strlen(cmd_line[i]))
		{
			valid_key_error("unset", cmd_line[i]);
			ret = 1;
		}
		else
			unset[cnt++] = cmd_line[i];
	}
	unset[cnt] = NULL;
	delete_env(unset);
	free(unset);
	return (ret);
}
