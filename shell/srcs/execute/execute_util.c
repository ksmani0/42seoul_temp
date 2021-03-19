/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_util.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseo <tseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 15:48:59 by tseo              #+#    #+#             */
/*   Updated: 2021/03/18 14:09:58 by tseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

int		has_redirection(t_cmd *cmd)
{
	if (cmd->redir[0] != 0)
		return (1);
	return (0);
}

void	get_exit_code(int status, int set_exit)
{
	if (set_exit == -1)
	{
		if (WIFEXITED(status))
			g_exit_status = WEXITSTATUS(status);
		else if (WIFSIGNALED(status))
			g_exit_status = 128 + WTERMSIG(status);
	}
	else
		g_exit_status = set_exit;
}

int		is_built_in(t_cmd *cmd)
{
	char *str;

	str = cmd->args[0];
	if (!ft_strncmp(str, "cd", 3))
		return (1);
	else if (!ft_strncmp(str, "echo", 5))
		return (1);
	else if (!ft_strncmp(str, "env", 4))
		return (1);
	else if (!ft_strncmp(str, "exit", 5))
		return (1);
	else if (!ft_strncmp(str, "export", 7))
		return (1);
	else if (!ft_strncmp(str, "pwd", 4))
		return (1);
	else if (!ft_strncmp(str, "unset", 6))
		return (1);
	else
		return (0);
}

int		run_built_in(t_cmd *cmd)
{
	int		ret;
	char	*str;

	ret = 0;
	str = cmd->args[0];
	if (!ft_strncmp(str, "cd", 3))
		ret = ft_cd(cmd->args);
	else if (!ft_strncmp(str, "echo", 5))
		ret = ft_echo(cmd->args);
	else if (!ft_strncmp(str, "env", 4))
		ret = ft_env(cmd->args);
	else if (!ft_strncmp(str, "exit", 5))
		ret = ft_exit(cmd->args);
	else if (!ft_strncmp(str, "export", 7))
		ret = ft_export(cmd->args);
	else if (!ft_strncmp(str, "pwd", 4))
		ret = ft_pwd(cmd->args);
	else if (!ft_strncmp(str, "unset", 6))
		ret = ft_unset(cmd->args);
	return (ret);
}
