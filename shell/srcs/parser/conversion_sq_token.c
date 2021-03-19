/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_sq_token.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseo <tseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 18:25:16 by tseo              #+#    #+#             */
/*   Updated: 2021/03/18 20:40:03 by tseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

void	get_sq_token_size(char *token, int *size)
{
	int		i;

	i = 0;
	*size = 0;
	while (token[i])
	{
		if (token[i] != '\'')
			(*size)++;
		i++;
	}
}

char	*convert_sq_token(char *token)
{
	int		i;
	int		j;
	int		size;
	char	*converted_token;

	get_sq_token_size(token, &size);
	if (!(converted_token = (char *)malloc(sizeof(char) * (size + 1))))
		memory_alloc_error();
	i = 0;
	j = 0;
	while (token[i])
	{
		if (token[i] != '\'')
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
