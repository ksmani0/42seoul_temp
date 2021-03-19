/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeelee <jaeelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 17:27:39 by jaeelee           #+#    #+#             */
/*   Updated: 2021/03/18 15:57:26 by jaeelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_env(char **cmd_line)
{
	int		i;
	char	*key;

	(void)cmd_line;
	i = -1;
	while (g_envs[++i])
	{
		key = get_key(g_envs[i]);
		if (search_env(key) != NULL)
			ft_putendl_fd(g_envs[i], STDOUT);
		free(key);
	}
	return (0);
}
