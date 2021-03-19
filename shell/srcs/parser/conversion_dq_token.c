/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_dq_token.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseo <tseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 10:43:53 by tseo              #+#    #+#             */
/*   Updated: 2021/03/18 20:38:09 by tseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

void	get_handling_dq_size(char *token, int *size)
{
	int i;

	i = 0;
	*size = 0;
	while (token[i])
	{
		if (token[i] != '\"' || (i > 0 && token[i] == '\"'
		&& token[i - 1] == '\\' && token[i + 1]))
			(*size)++;
		i++;
	}
}

char	*handling_dq_doublequotes(char *token)
{
	int		i;
	int		j;
	int		size;
	char	*converted_token;

	get_handling_dq_size(token, &size);
	if (!(converted_token = (char *)malloc(sizeof(char) * (size + 1))))
		memory_alloc_error();
	i = 0;
	j = 0;
	while (token[i])
	{
		if (token[i] != '\"' || (i > 0 && token[i] == '\"'
			&& token[i - 1] == '\\' && token[i + 1]))
		{
			converted_token[j] = token[i];
			j++;
		}
		i++;
	}
	converted_token[size] = 0;
	free(token);
	return (converted_token);
}

char	*convert_dq_token(char *token)
{
	char *ret;

	ret = handling_dq_doublequotes(token);
	ret = handling_dq_backslash(ret);
	ret = handling_dq_env(ret);
	return (ret);
}
