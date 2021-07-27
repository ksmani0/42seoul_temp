/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehakam <ehakam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 20:48:38 by moboustt          #+#    #+#             */
/*   Updated: 2021/07/06 21:13:35 by ehakam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

t_token	*construct_token(t_lexer *l)
{
	t_token	*tok;

	tok = ft_malloc(sizeof(t_token));
	tok->lexer = l;
	return (tok);
}

t_bool	is_env_identifier(const t_lexer *l)
{
	return (l->ch == '$' && (ft_isalnum(l->input[l->read_position])
			|| l->input[l->read_position] == '?'));
}

t_token	*next_token(t_lexer *l)
{
	t_token	*tok;

	tok = construct_token(l);
	skip_white_spaces(l);
	if (l->ch == '~' && (peek_char(l) == ' ' || \
	peek_char(l) == '/' || peek_char(l) == '+' || peek_char(l) == 0))
		tok = new_token(TILDE, l->ch, tok);
	else if (l->ch == '<' || l->ch == '>')
		tok = handle_right_redir(l, tok);
	else if (l->ch == '|')
		tok = new_token(PIPE, l->ch, tok);
	else if (l->ch == '\'')
		handle_single_quote_identifier(l, tok);
	else if (l->ch == '"')
		handle_double_quotes_identifier(l, tok);
	else if (l->ch == 0)
		return (handle_eof_token(tok));
	else if (is_letter(l->ch) || l->ch == '$')
		return (handle_identifier_with_no_quotes(l, tok));
	else
		return (handle_illegal_token(l, tok));
	next_char(l);
	return (tok);
}

void	replace_env(t_lexer *l, char **s, int *index)
{
	char	*env_value;

	next_char(l);
	if (ft_isdigit(l->ch))
	{
		next_char(l);
		return ;
	}
	env_value = get_env_value(l);
	if (env_value == NULL)
		return ;
	*s = strjoin_s(*s, env_value, true);
	(*index) += (int) ft_strlen(env_value);
}

void	read_and_parse_double_quoted(t_lexer *l, char **s, int *index)
{
	check_quotes_errors(l, l->ch);
	next_char(l);
	while (l->ch != '"')
	{
		if (is_env_identifier(l))
		{
			replace_env(l, s, index);
			continue ;
		}
		*index += 1;
		*s = strjoin_c(*s, l->ch, true);
		next_char(l);
	}
	next_char(l);
}
