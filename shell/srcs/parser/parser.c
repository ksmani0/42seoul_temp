/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseo <tseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 12:45:24 by tseo              #+#    #+#             */
/*   Updated: 2021/03/18 20:41:04 by tseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

int		convert_tokens(char **tokens)
{
	int i;

	i = 0;
	while (tokens[i])
	{
		if (tokens[i][0] == '\'')
			tokens[i] = convert_sq_token(tokens[i]);
		else if (tokens[i][0] == '$')
			tokens[i] = handling_dq_env(tokens[i]);
		else if (tokens[i][0] == '\"')
			tokens[i] = convert_dq_token(tokens[i]);
		else
			tokens[i] = convert_normal_token(tokens[i]);
		i++;
	}
	return (1);
}

char	**tokenize_input_line(char *line)
{
	char	**tokens;
	int		token_num;
	int		i;

	token_num = count_tokens(line);
	if (!(tokens = (char **)malloc(sizeof(char *) * (token_num + 1))))
		memory_alloc_error();
	i = -1;
	while (++i < token_num)
		tokens[i] = get_token(line, i + 1);
	tokens[i] = NULL;
	return (tokens);
}

t_cmd	*parse_input_line(char *line)
{
	char	**tokens;
	t_cmd	*cmd_list;

	tokens = tokenize_input_line(line);
	if (!check_tokens(tokens))
	{
		free_tokens(tokens);
		return (0);
	}
	if (!convert_tokens(tokens))
	{
		free_tokens(tokens);
		return (0);
	}
	cmd_list = make_cmd_list(tokens);
	free_tokens(tokens);
	return (cmd_list);
}
