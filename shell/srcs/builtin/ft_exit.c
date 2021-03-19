/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeelee <jaeelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 15:46:15 by jaeelee           #+#    #+#             */
/*   Updated: 2021/03/18 16:05:20 by jaeelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	set_exit_status(int x)
{
	g_exit_status = x;
	if (x != -1)
		exit(g_exit_status);
}

static int	check_obj_isdigit(char *obj)
{
	int i;

	i = -1;
	while (obj[++i])
	{
		if (!ft_isdigit(obj[i]))
			return (0);
	}
	return (1);
}

int			ft_exit(char **cmd_line)
{
	ft_putendl_fd("exit", STDOUT);
	if (cmd_line[1] == NULL)
		set_exit_status(0);
	if (!check_obj_isdigit(cmd_line[1]))
	{
		ft_putstr_fd("minishell: exit: ", STDERR);
		ft_putstr_fd(cmd_line[1], STDERR);
		ft_putstr_fd(": numeric argument required\n", STDERR);
		set_exit_status(255);
	}
	else if (cmd_line[2] != NULL)
	{
		ft_putendl_fd("minishell: exit: too many arguments", STDERR);
		return (1);
	}
	else
		set_exit_status(ft_atoi(cmd_line[1]) % 256);
	return (0);
}
