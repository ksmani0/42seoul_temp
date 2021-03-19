/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_conversion_1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseo <tseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 21:24:29 by tseo              #+#    #+#             */
/*   Updated: 2021/03/18 18:26:00 by tseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

char	*convert_env_token(char *token)
{
	char *converted_token;

	converted_token = NULL;
	if (ft_strlen(token) == 2 && ft_strncmp(token, "$?", 2) == 0)
	{
		converted_token = ft_itoa(g_exit_status);
		return (converted_token);
	}
	if (get_envs_value(&token[1]))
		converted_token = ft_strdup(get_envs_value(&token[1]));
	else
		converted_token = ft_strdup("");
	free(token);
	return (converted_token);
}
