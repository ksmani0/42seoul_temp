/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseo <tseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 10:19:15 by tseo              #+#    #+#             */
/*   Updated: 2021/03/18 19:10:08 by jaeelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		skip_separator_spaces(char *line, int i)
{
	int	skip;

	if (line[i] == ' ' || line[i] == '\t')
		skip = 1;
	else if (line[i] == '>' && line[i + 1] == '>')
		skip = 2;
	else if (line[i] == '>')
		skip = 1;
	else if (line[i] == '<')
		skip = 1;
	else if (line[i] == '|')
		skip = 1;
	else if (line[i] == ';')
		skip = 1;
	else
		return (0);
	i += skip;
	while (line[i] == ' ' || line[i] == '\t')
	{
		i++;
		skip++;
	}
	return (skip);
}

char	*get_token(char *line, int token_size)
{
	int i;
	int start_idx;

	i = 0;
	start_idx = 0;
	while (line[i])
	{
		if (!is_separtor(SEPARATOR_SPACE, line[i]) && line[i] && token_size--)
		{
			while (!is_separtor(SEPARATOR_SPACE, line[i]) && line[i])
				i = check_and_jmp_quotes(line, i) + 1;
			if (token_size == 0)
				return (ft_substr(line, start_idx, i - start_idx));
			start_idx = i;
		}
		if (is_separtor(SEPARATOR, line[i]) && --token_size == 0)
		{
			return (ft_substr(line, start_idx,
						i + skip_separator(line, i) - start_idx));
		}
		i += skip_separator_spaces(line, i);
		start_idx = i;
	}
	return (NULL);
}
