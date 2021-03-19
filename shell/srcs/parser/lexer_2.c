/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseo <tseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 10:19:11 by tseo              #+#    #+#             */
/*   Updated: 2021/03/18 18:38:30 by jaeelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		skip_spaces(char *line)
{
	int i;

	i = 0;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	return (i);
}

int		skip_separator(char *line, int i)
{
	int skip;

	skip = 0;
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
	return (skip);
}

int		check_backslash(char *line, int *i, char quote)
{
	if (!line[*i])
		return (0);
	if (line[*i] == '\\')
		++*i;
	else if (line[*i] == quote)
		return (0);
	return (1);
}

int		check_and_jmp_quotes(char *line, int i)
{
	if (line[i] == '\"' && (i == 0 || line[i - 1] != '\\'))
	{
		i++;
		while (check_backslash(line, &i, '\"'))
			i++;
		if (line[i] == '\0')
		{
			quotes_error();
			return (-1);
		}
	}
	else if (line[i] == '\'')
	{
		i++;
		while (line[i] != '\'' && line[i])
			i++;
		if (line[i] == '\0')
		{
			quotes_error();
			return (-1);
		}
	}
	return (i);
}

int		count_tokens(char *line)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	i += skip_spaces(line);
	while (line[i])
	{
		count++;
		while (!is_separtor(SEPARATOR_SPACE, line[i]) && line[i])
		{
			if ((i = check_and_jmp_quotes(line, i)) == -1)
				return (0);
			if (line[i] == '\\' && !line[i + 1])
				return (0);
			i++;
		}
		i += skip_spaces(&line[i]);
		if (is_separtor(SEPARATOR, line[i]))
			count++;
		i += skip_separator(line, i);
	}
	return (count);
}
