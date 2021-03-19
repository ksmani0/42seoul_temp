/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeelee <jaeelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 19:33:33 by jaeelee           #+#    #+#             */
/*   Updated: 2021/03/18 21:41:42 by jaeelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_env	*get_key_value(int cnt)
{
	t_env	*env;
	int		i;

	env = (t_env *)malloc(sizeof(t_env) * (cnt + 1));
	i = -1;
	while (g_envs[++i])
	{
		env[i].key = get_key(g_envs[i]);
		env[i].value = search_env(env[i].key);
	}
	if (search_env("OLDPWD") == NULL)
	{
		env[i].key = ft_strdup("OLDPWD");
		env[i++].value = NULL;
	}
	env[i].key = NULL;
	return (env);
}

static void		print_export(void)
{
	t_env	*env;
	int		i;
	int		cnt;

	cnt = ft_arrsize(g_envs);
	if (search_env("OLDPWD") == NULL)
		cnt++;
	env = sort_env(get_key_value(cnt));
	i = -1;
	while (env[++i].key)
	{
		ft_putstr_fd("declare-x ", STDOUT);
		ft_putstr_fd(env[i].key, STDOUT);
		if (env[i].value != NULL)
		{
			ft_putstr_fd("=\"", STDOUT);
			ft_putstr_fd(env[i].value, STDOUT);
			ft_putstr_fd("\"", STDOUT);
		}
		ft_putstr_fd("\n", STDOUT);
	}
	free_arr_env(env);
}

static void		add_env(char **envs, char *key, char *new)
{
	int		i;
	int		size;

	i = -1;
	size = ft_strlen(key);
	while (envs[++i])
	{
		if (ft_strncmp(key, envs[i], size) == 0 &&
				(envs[i][size] == '=' || envs[i][size] == '\0'))
		{
			free(envs[i]);
			break ;
		}
	}
	if (i == ft_arrsize(envs))
		envs[i + 1] = NULL;
	envs[i] = ft_strdup(new);
	free(key);
}

int				ft_export(char **cmd_line)
{
	char	**temp;
	char	*key;
	int		cnt;
	int		i;
	int		ret;

	ret = 0;
	if (ft_arrsize(cmd_line) == 1)
		print_export();
	cnt = ft_arrsize(g_envs) + ft_arrsize(cmd_line);
	temp = get_envs(g_envs, cnt);
	i = 0;
	while (cmd_line[++i])
	{
		if ((key = get_key(cmd_line[i])) == NULL)
		{
			valid_key_error("export", cmd_line[i]);
			ret = 1;
		}
		else
			add_env(temp, key, cmd_line[i]);
	}
	free_double_arr(g_envs);
	g_envs = temp;
	return (ret);
}
