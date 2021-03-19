/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_normal_token.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseo <tseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 18:21:00 by tseo              #+#    #+#             */
/*   Updated: 2021/03/18 18:21:32 by tseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

char	*convert_normal_token(char *token)
{
	int i;

	i = 0;
	while (token[i])
	{
		if (token[i] == '\"')
		{
			token = handling_dq_doublequotes(token);
			break ;
		}
		if (token[i] == '\'')
		{
			token = convert_sq_token(token);
			break ;
		}
		if (token[i] == '$')
		{
			token = handling_dq_env(token);
			break ;
		}
		i++;
	}
	return (token);
}
