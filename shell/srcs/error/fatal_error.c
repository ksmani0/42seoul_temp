/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fatal_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseo <tseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 14:39:13 by tseo              #+#    #+#             */
/*   Updated: 2021/03/18 16:31:58 by jaeelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

void	memory_alloc_error(void)
{
	ft_putstr_fd("minishell: memory allocation failed\n", STDERR);
	exit(1);
}

void	fatal_error(void)
{
	ft_putstr_fd("minishell: fatal error\n", STDERR);
	exit(1);
}

void	failed_create_file(void)
{
	ft_putstr_fd("minishell: failed to create file\n", STDERR);
	exit(1);
}

void	valid_key_error(char *cmd, char *arg)
{
	ft_putstr_fd("minishell: ", STDERR);
	ft_putstr_fd(cmd, STDERR);
	ft_putstr_fd(": '", STDERR);
	ft_putstr_fd(arg, STDERR);
	ft_putendl_fd("': not a valid identifier", STDERR);
}
