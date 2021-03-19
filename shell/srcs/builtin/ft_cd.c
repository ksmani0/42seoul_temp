/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeelee <jaeelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 17:02:25 by jaeelee           #+#    #+#             */
/*   Updated: 2021/03/18 15:58:57 by jaeelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	set_pwd(void)
{
	char	*old_pwd;
	char	pwd[PATH_MAX];
	int		i;

	old_pwd = ft_strdup(search_env("PWD"));
	getcwd(pwd, PATH_MAX);
	i = -1;
	while (g_envs[++i])
	{
		if (ft_strncmp(g_envs[i], "OLDPWD=", 7) == 0)
		{
			free(g_envs[i]);
			g_envs[i] = ft_strjoin("OLDPWD=", old_pwd);
		}
		if (ft_strncmp(g_envs[i], "PWD=", 4) == 0)
		{
			free(g_envs[i]);
			g_envs[i] = ft_strjoin("PWD=", pwd);
		}
	}
	free(old_pwd);
}

int			ft_cd(char **cmd_line)
{
	char	*temp;

	if (cmd_line[1] == NULL || ft_strncmp(cmd_line[1], "~", 2) == 0)
		temp = search_env("HOME");
	else
		temp = cmd_line[1];
	if (chdir(temp) == -1)
	{
		ft_putstr_fd("minishell: cd: ", STDERR);
		ft_putstr_fd(temp, STDERR);
		ft_putstr_fd(": ", STDERR);
		ft_putstr_fd(strerror(errno), STDERR);
		ft_putstr_fd("\n", STDERR);
		return (1);
	}
	set_pwd();
	return (0);
}
