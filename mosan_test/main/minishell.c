/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehakam <ehakam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 21:58:08 by ehakam            #+#    #+#             */
/*   Updated: 2021/07/14 21:40:45 by ehakam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

t_minishell	g_config;

int	parse_and_execute(t_lexer *lexer)
{
	t_node		*ast_node;
	t_error		*err;
	t_parser	*p;

	ast_node = NULL;
	p = new_parser(lexer);
	err = check_first_token(p);
	if (catch_errors(p, err)->is_error || err->is_error)
	{
		p_error(NULL, err->error_msg, "Bad Token", 1);
		free_parser(err, p);
		return (EXIT_FAILURE);
	}
	free(err);
	ast_node = parse_command(ast_node, p);
	if (ast_node == NULL)
		return (1);
	run_cmds((t_vector *) fill_out_vector_with_commands(ast_node));
	free_syntax_tree(ast_node, false);
	free(p);
	return (0);
}

char	*get_line(void)
{
	char	*line_read;

	line_read = readline (g_config.prompt);
	if (line_read && *line_read)
		add_history (line_read);
	return (line_read);
}

void	start(char *line)
{
	t_lexer	*lexer;

	lexer = new_lexer(line, (int) ft_strlen(line));
	while (lexer->ch == ' ')
		next_char(lexer);
	if (lexer->ch == 0)
	{
		free(lexer);
		free(line);
		return ;
	}
	parse_and_execute(lexer);
	if (line)
		free (line);
	free(lexer);
}

int	main(int ac, char **av, char **env)
{
	char	*line;
	int		code;

	code = 0;
	ft_init(env, ac, av);
	while (true)
	{
		line = get_line();
		if (line && line[0] == '\0')
		{
			free(line);
			continue ;
		}
		if (!line)
		{
			if (isatty(0))
				write(2, "exit\n", 5);
			break ;
		}
		start(line);
	}
	code = ft_atoi(get_var(g_config.envp, "?"));
	delete_free(g_config.envp, &delete_var);
	free(g_config.prompt);
	return (code);
}
