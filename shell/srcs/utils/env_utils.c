/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseo <tseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 18:27:15 by jaeelee           #+#    #+#             */
/*   Updated: 2021/03/18 16:21:10 by jaeelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		check_validkey(char *obj)
{
	int	cnt;

	cnt = 0;
	if (ft_isdigit(obj[0]) || obj[0] == '=')
		return (0);
	while (obj[cnt] && (ft_isalnum(obj[cnt]) || obj[cnt] == '_'))
		cnt++;
	return (cnt);
}

char	*get_key(char *obj)
{
	int		size_key;
	char	*key;

	if (ft_strchr(obj, '=') == 0)
		size_key = ft_strlen(obj) + 1;
	else
		size_key = ft_strchr(obj, '=') - obj + 1;
	if (size_key - 1 != check_validkey(obj) || check_validkey(obj) == 0)
		return (NULL);
	key = (char *)malloc(sizeof(char) * size_key);
	ft_strlcpy(key, obj, size_key);
	return (key);
}

char	*search_env(char *key)
{
	int	i;

	i = -1;
	while (g_envs[++i])
	{
		if (ft_strncmp(key, g_envs[i], ft_strlen(key)) == 0 &&
				g_envs[i][ft_strlen(key)] == '=')
			return (&g_envs[i][ft_strlen(key) + 1]);
	}
	return (NULL);
}

t_env	*sort_env(t_env *env)
{
	int		i;
	int		j;
	char	*temp;

	i = -1;
	while (env[++i].key)
	{
		j = i;
		while (env[++j].key)
		{
			if (ft_strncmp(
						env[i].key, env[j].key, ft_strlen(env[i].key) + 1) > 0)
			{
				temp = env[i].key;
				env[i].key = env[j].key;
				env[j].key = temp;
				temp = env[i].value;
				env[i].value = env[j].value;
				env[j].value = temp;
			}
		}
	}
	return (env);
}

void	free_arr_env(t_env *env)
{
	int i;

	i = -1;
	while (env[++i].key != NULL)
		free(env[i].key);
	free(env);
}
