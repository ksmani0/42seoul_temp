/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_dq_token_env_util.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseo <tseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 20:26:32 by tseo              #+#    #+#             */
/*   Updated: 2021/03/18 20:42:44 by tseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

void	init_env_info(t_env_info *e_info)
{
	e_info->env_key_len = 0;
	e_info->key = 0;
	e_info->i = 0;
	e_info->j = 0;
	e_info->count = 0;
}

void	count_dollors(char *token, t_env_info *e_info)
{
	int i;

	i = 0;
	e_info->dollor_count = 0;
	while (token[i])
	{
		if (token[i] == '$' && token[i + 1] != ' ')
			(e_info->dollor_count)++;
		i++;
	}
}

void	find_keys(char *token, char **dq_envs, t_env_info e_info)
{
	while (token[e_info.i])
	{
		if (token[e_info.i] == '$' && token[e_info.i + 1] != ' ')
		{
			e_info.env_key_len = 0;
			while (token[e_info.i + e_info.env_key_len])
			{
				if (token[e_info.i + e_info.env_key_len] == ' ')
					break ;
				if (token[e_info.i + e_info.env_key_len + 1] == '$')
				{
					e_info.env_key_len++;
					break ;
				}
				e_info.env_key_len++;
			}
			e_info.key = ft_substr(&token[e_info.i], 0, e_info.env_key_len);
			dq_envs[e_info.j] = ft_strdup(e_info.key);
			e_info.j++;
			free(e_info.key);
		}
		e_info.i++;
	}
}

void	calc_env_key_len(char *temp, int i, int *env_key_len)
{
	*env_key_len = 0;
	while (temp[i + *env_key_len])
	{
		if (temp[i + *env_key_len] == ' ')
			break ;
		if (temp[i + *env_key_len + 1] == '$')
		{
			(*env_key_len)++;
			break ;
		}
		(*env_key_len)++;
	}
}
