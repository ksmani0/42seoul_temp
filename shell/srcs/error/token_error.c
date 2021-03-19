/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseo <tseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 10:20:46 by tseo              #+#    #+#             */
/*   Updated: 2021/03/18 21:26:07 by tseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

int		syntax_error(char *token)
{
	ft_putstr_fd("minishell: syntax error near unexpected token ", STDERR);
	ft_putstr_fd("\'", STDERR);
	ft_putstr_fd(token, STDERR);
	ft_putstr_fd("\'\n", STDERR);
	g_exit_status = 258;
	return (0);
}

void	no_command_error(char *cmd)
{
	ft_putstr_fd("minishell: ", STDERR);
	ft_putstr_fd(cmd, STDERR);
	ft_putstr_fd(": command not found ", STDERR);
	ft_putstr_fd("\n", STDERR);
	exit(127);
}

void	no_file_error(char *path)
{
	ft_putstr_fd("minishell: ", STDERR);
	ft_putstr_fd(path, STDERR);
	ft_putstr_fd(": No such file or directory\n", STDERR);
	exit(1);
}

void	quotes_error(void)
{
	ft_putstr_fd("Syntax Error: Quotes are not matched\n", STDERR);
	g_exit_status = 1;
}
