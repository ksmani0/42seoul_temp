/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseo <tseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 18:21:57 by tseo              #+#    #+#             */
/*   Updated: 2021/03/18 20:42:34 by tseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

int		check_redirection(char **tokens)
{
	int i;

	i = 0;
	while (tokens[i])
	{
		if (is_redirection(tokens[i]))
		{
			if (tokens[i + 1] && (is_redirection(tokens[i + 1])
			|| is_pipe(tokens[i + 1]) || is_semicolon(tokens[i + 1])))
				return (syntax_error(tokens[i]));
		}
		i++;
	}
	if (i > 0 && is_redirection(tokens[i - 1]))
		return (syntax_error("newline"));
	return (1);
}

int		check_pipe(char **tokens)
{
	int i;

	i = 0;
	while (tokens[i])
	{
		if (is_pipe(tokens[i]))
		{
			if (i == 0)
				return (syntax_error("|"));
			if (tokens[i + 1] && (is_pipe(tokens[i + 1])
				|| is_semicolon(tokens[i + 1])))
				return (syntax_error(tokens[i]));
			if (i > 0 && is_semicolon(tokens[i - 1]))
				return (syntax_error("|"));
		}
		i++;
	}
	if (i > 0 && is_pipe(tokens[i - 1]))
		return (syntax_error("|"));
	return (1);
}

int		check_semicolon(char **tokens)
{
	int i;

	i = 0;
	while (tokens[i])
	{
		if (is_semicolon(tokens[i]))
		{
			if (i == 0)
				return (syntax_error(";"));
			if (i > 0 && tokens[i + 1] != 0 && is_semicolon(tokens[i + 1]))
				return (syntax_error(";"));
		}
		i++;
	}
	return (1);
}

int		check_tokens(char **tokens)
{
	if (!(check_semicolon(tokens)))
		return (0);
	if (!check_redirection(tokens))
		return (0);
	if (!check_pipe(tokens))
		return (0);
	return (1);
}
