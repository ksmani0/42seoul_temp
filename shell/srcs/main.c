/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseo <tseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 10:10:42 by tseo              #+#    #+#             */
/*   Updated: 2021/03/18 20:46:35 by tseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**g_envs;
int		g_exit_status;

void	run_minishell(void)
{
	char	*line;
	t_cmd	*cmd_list;
	t_cmd	*head;
	int		ret;

	cmd_list = NULL;
	head = cmd_list;
	ret = 1;
	while (ret)
	{
		handle_main_signals();
		print_prompt();
		ret = get_input_line(&line);
		cmd_list = parse_input_line(line);
		exec_commands(cmd_list);
		clear_list(head);
		free(line);
		line = NULL;
	}
}

int		main(int argc, char **argv, char **envp)
{
	(void)argc;
	(void)argv;
	g_envs = get_envs(envp, ft_arrsize(envp));
	run_minishell();
	return (EXIT_SUCCESS);
}
