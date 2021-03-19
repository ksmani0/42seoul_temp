/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseo <tseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 11:54:18 by tseo              #+#    #+#             */
/*   Updated: 2021/03/18 14:48:54 by tseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

void	exec_input_redirection(t_cmd *cmd,
		t_redir redir_info, int input_count, int i)
{
	int fdin;

	if (input_count < redir_info.input_redir_count)
	{
		fdin = open(cmd->path[i], O_RDONLY, 0644);
		if (fdin < 0)
			no_file_error(cmd->path[i]);
	}
	else
	{
		fdin = open(cmd->path[i], O_RDONLY, 0644);
		if (fdin < 0)
			no_file_error(cmd->path[i]);
		dup2(fdin, STDIN_FILENO);
		close(fdin);
	}
}

void	exec_output_redirection(t_cmd *cmd,
		t_redir redir_info, int output_count, int i)
{
	if (output_count < redir_info.output_redir_count)
		output_redir_create_file(cmd, i);
	else
		output_redir_dup_close(cmd, i);
}

void	make_redirection(t_cmd *cmd)
{
	int			i;
	int			input_count;
	int			output_count;
	t_redir		redir_info;

	get_redir_count(cmd, &redir_info);
	i = 0;
	input_count = 0;
	output_count = 0;
	while (cmd->redir[i])
	{
		if ((ft_strncmp(cmd->redir[i], "<", 1) == 0))
		{
			input_count++;
			exec_input_redirection(cmd, redir_info, input_count, i);
		}
		if (ft_strncmp(cmd->redir[i], ">", 2) == 0
		|| ft_strncmp(cmd->redir[i], ">>", 2) == 0)
		{
			output_count++;
			exec_output_redirection(cmd, redir_info, output_count, i);
		}
		i++;
	}
}
