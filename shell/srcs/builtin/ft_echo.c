/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeelee <jaeelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 15:15:20 by jaeelee           #+#    #+#             */
/*   Updated: 2021/03/18 16:33:47 by jaeelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	check_opt(char *opt)
{
	int	i;

	if (opt[0] != '-')
		return (0);
	i = 1;
	while (opt[i])
	{
		if (opt[i++] != 'n')
			return (0);
	}
	return (1);
}

int			ft_echo(char **cmd_line)
{
	int	opt_n;
	int	i;

	opt_n = 0;
	if (cmd_line[1] != NULL)
		opt_n = check_opt(cmd_line[1]);
	i = opt_n;
	while (cmd_line[++i])
	{
		if (i > (1 + opt_n))
			ft_putstr_fd(" ", STDOUT);
		ft_putstr_fd(cmd_line[i], STDOUT);
	}
	if (opt_n == 0)
		ft_putstr_fd("\n", STDOUT);
	return (0);
}
