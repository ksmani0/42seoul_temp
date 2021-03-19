/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection_util.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseo <tseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 14:41:35 by tseo              #+#    #+#             */
/*   Updated: 2021/03/18 14:45:26 by tseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

void	get_redir_count(t_cmd *cmd, t_redir *redir_info)
{
	int i;

	i = 0;
	redir_info->input_redir_count = 0;
	redir_info->output_redir_count = 0;
	while (cmd->redir[i])
	{
		if (ft_strncmp(cmd->redir[i], "<", 1) == 0)
			redir_info->input_redir_count++;
		i++;
	}
	redir_info->output_redir_count = i - redir_info->input_redir_count;
}

void	output_redir_create_file(t_cmd *cmd, int i)
{
	int fdout;

	if (ft_strncmp(cmd->redir[i], ">", 2) == 0)
	{
		fdout = open(cmd->path[i], O_WRONLY | O_CREAT | O_TRUNC, 0744);
		if (fdout < 0)
			fatal_error();
	}
	else if (ft_strncmp(cmd->redir[i], ">>", 2) == 0)
	{
		fdout = open(cmd->path[i], O_WRONLY | O_CREAT | O_APPEND, 0744);
		if (fdout < 0)
			fatal_error();
	}
}

void	output_redir_dup_close(t_cmd *cmd, int i)
{
	int fdout;

	if (ft_strncmp(cmd->redir[i], ">", 2) == 0)
	{
		fdout = open(cmd->path[i], O_WRONLY | O_CREAT | O_TRUNC, 0744);
		if (fdout < 0)
			fatal_error();
		dup2(fdout, STDOUT_FILENO);
		close(fdout);
	}
	else if (ft_strncmp(cmd->redir[i], ">>", 2) == 0)
	{
		fdout = open(cmd->path[i], O_WRONLY | O_CREAT | O_APPEND, 0744);
		if (fdout < 0)
			fatal_error();
		dup2(fdout, STDOUT_FILENO);
		close(fdout);
	}
}
