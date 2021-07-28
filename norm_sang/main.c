/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghpar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 19:17:09 by sanghpar          #+#    #+#             */
/*   Updated: 2020/11/19 14:00:25 by sanghpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_input(void)
{
	char	**commands;
	char	**tmp2;

	g_data->input = readline("$ ");
	if (g_data->input)
	{
		if (check_parse_error(g_data->input) == -1)
		{
			g_data->ret = 2;
			return (0);
		}
		g_data->input = ft_trim(g_data->input, ' ');
		return (g_data->input);
	}
	return ((void *)0);
}

void	init_term2(void)
{
	tcgetattr(STDIN_FILENO, &g_data->main_term);
	tcgetattr(STDIN_FILENO, &g_data->child_term);
	g_data->main_term.c_lflag &= ECHO;
	g_data->main_term.c_cc[VMIN] = 0;
	g_data->main_term.c_cc[VTIME] = 0;
	tcsetattr(STDIN_FILENO, TCSANOW, &g_data->main_term);
}

t_sh_data	*init_setting(char **envp)
{
	g_data = (t_sh_data *)malloc(sizeof(t_sh_data));
	g_data->env_list = parse_env(envp);
	g_data->stdin = 0;
	g_data->stdout = 1;
	g_data->origin_stdin = dup(0);
	g_data->origin_stdout = dup(1);
	g_data->envp = envp;
	g_data->forked = 0;
	g_data->signal = 0;
	signal(SIGINT, main_signal);
	signal(SIGQUIT, main_signal);
	init_term2();
}

int	main(int argc, char **argv, char **envp)
{
	int		state;

	(void)argc;
	(void)argv;
	init_setting(envp);
	while (true)
	{
		if ((g_data->input = get_input()) != 0)//assignment!
		{
			state = parse_execute(g_data->input);
			if (g_data->input)
				add_history(g_data->input);
		}
		else
		{
			tcsetattr(STDIN_FILENO, TCSANOW, &g_data->child_term);
			if (g_data->ret != 2)
				return (0);
		}
		free_buffer(&g_data->input);
	}
	return (0);
}
