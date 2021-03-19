/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_dq_token_backslash.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseo <tseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 20:30:25 by tseo              #+#    #+#             */
/*   Updated: 2021/03/18 20:36:56 by tseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

void	get_handling_dq_bs_size(char *token, int *size, int len)
{
	int i;

	i = 0;
	while (token[i])
	{
		if (token[i] == '\\' && token[i + 1] == '\\')
		{
			i += 2;
			(*size)++;
			continue;
		}
		if (i != len - 2 && token[i] == '\\' && token[i + 1] == '\"')
		{
			i += 2;
			(*size)++;
			continue;
		}
		(*size)++;
		i++;
	}
}

void	handling_indices(int *i, int *j)
{
	(*i) += 2;
	(*j)++;
}

void	alloc_handling_dq_bs(char *token, char *converted_token,
							int size, int len)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (token[i])
	{
		if (token[i] == '\\' && token[i + 1] == '\\')
		{
			converted_token[j] = token[i];
			handling_indices(&i, &j);
			continue;
		}
		if (i != len - 2 && token[i] == '\\' && token[i + 1] == '\"')
		{
			converted_token[j] = token[i + 1];
			handling_indices(&i, &j);
			continue;
		}
		converted_token[j] = token[i];
		j++;
		i++;
	}
	converted_token[size] = 0;
}

char	*handling_dq_backslash(char *token)
{
	int		size;
	char	*converted_token;
	int		len;

	size = 0;
	len = ft_strlen(token);
	get_handling_dq_bs_size(token, &size, len);
	if (!(converted_token = (char *)malloc(sizeof(char) * (size + 1))))
		memory_alloc_error();
	alloc_handling_dq_bs(token, converted_token, size, len);
	free(token);
	return (converted_token);
}
