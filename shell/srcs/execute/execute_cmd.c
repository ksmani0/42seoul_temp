/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseo <tseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 15:58:33 by tseo              #+#    #+#             */
/*   Updated: 2021/03/18 21:18:49 by tseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

void	exec_child_process(t_cmd *cmd)
{
	int ret;

	if (cmd->type == TYPE_PIPE && dup2(cmd->fd[1], STDOUT) < 0)
		fatal_error();
	if (cmd->prev && cmd->prev->type == TYPE_PIPE
					&& dup2(cmd->prev->fd[0], STDIN) < 0)
		fatal_error();
	if (has_redirection(cmd))
		make_redirection(cmd);
	if (is_built_in(cmd))
	{
		ret = run_built_in(cmd);
		exit(ret);
	}
	else
	{
		if ((ret = execve(find_path(cmd->args[0]), cmd->args, g_envs)) < 0)
			no_command_error(cmd->args[0]);
	}
	exit(0);
}

void	exec_parent_process(t_cmd *cmd, pid_t pid, int status, int pipe_open)
{
	waitpid(pid, &status, 0);
	if (pipe_open)
	{
		close(cmd->fd[1]);
		if (!cmd->next || cmd->type == TYPE_BREAK)
			close(cmd->fd[0]);
	}
	if (cmd->prev && cmd->prev->type == TYPE_PIPE)
		close(cmd->prev->fd[0]);
	get_exit_code(status, -1);
}

void	exec_command(t_cmd *cmd)
{
	pid_t	pid;
	int		status;
	int		pipe_open;

	status = 0;
	pipe_open = 0;
	if (cmd->type == TYPE_PIPE || (cmd->prev && cmd->prev->type == TYPE_PIPE))
	{
		pipe_open = 1;
		if (pipe(cmd->fd) < 0)
			fatal_error();
	}
	pid = fork();
	if (pid < 0)
		fatal_error();
	else if (pid == 0)
		exec_child_process(cmd);
	else
		exec_parent_process(cmd, pid, status, pipe_open);
}

int		exec_commands(t_cmd *cmd)
{
	int ret;

	while (cmd)
	{
		if (cmd->type != TYPE_PIPE && !has_redirection(cmd))
		{
			if (is_built_in(cmd))
			{
				ret = run_built_in(cmd);
				get_exit_code(-1, ret);
			}
			else
				exec_command(cmd);
		}
		else
			exec_command(cmd);
		cmd = cmd->next;
	}
	return (1);
}
