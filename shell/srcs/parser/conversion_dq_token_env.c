/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_dq_token_env.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseo <tseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 10:43:53 by tseo              #+#    #+#             */
/*   Updated: 2021/03/18 20:42:10 by tseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

void	convert_envs_in_token(char *token,
char **converted_token, char **dq_envs, t_env_info e_info)
{
	char *temp;

	temp = ft_strdup(token);
	while (temp[e_info.i])
	{
		if (temp[e_info.i] == '$' && temp[e_info.i + 1] != ' ')
		{
			calc_env_key_len(temp, e_info.i, &(e_info.env_key_len));
			temp[e_info.i] = 0;
			*converted_token = ft_strappend(*converted_token, &temp[e_info.j]);
			*converted_token = ft_strappend(*converted_token,
										dq_envs[e_info.count]);
			e_info.i += e_info.env_key_len;
			e_info.count++;
			e_info.j = e_info.i;
			continue ;
		}
		e_info.i++;
	}
	*converted_token = ft_strappend(*converted_token, &temp[e_info.j]);
	free(temp);
}

void	convert_key_to_value(char **dq_envs, t_env_info e_info)
{
	int i;

	i = 0;
	while (i < e_info.dollor_count)
	{
		dq_envs[i] = convert_env_token(dq_envs[i]);
		i++;
	}
}

char	*handling_dq_env(char *token)
{
	t_env_info	e_info;
	char		*converted_token;
	char		**dq_envs;
	int			i;

	converted_token = 0;
	count_dollors(token, &e_info);
	init_env_info(&e_info);
	if (e_info.dollor_count > 0)
	{
		if (!(dq_envs = (char **)malloc(sizeof(char *)
						* (e_info.dollor_count + 1))))
			memory_alloc_error();
		dq_envs[e_info.dollor_count] = 0;
		find_keys(token, dq_envs, e_info);
		convert_key_to_value(dq_envs, e_info);
		convert_envs_in_token(token, &converted_token, dq_envs, e_info);
		i = -1;
		while (++i < e_info.dollor_count)
			free(dq_envs[i]);
		free(dq_envs);
		free(token);
		return (converted_token);
	}
	return (token);
}
