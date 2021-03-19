/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeelee <jaeelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 20:46:36 by jaeelee           #+#    #+#             */
/*   Updated: 2021/03/18 16:09:40 by jaeelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_pwd(char **cmd_line)
{
	char buf[PATH_MAX];

	(void)cmd_line;
	if (getcwd(buf, PATH_MAX) == NULL)
	{
		ft_putstr_fd("current working directory get error: ", STDERR);
		ft_putendl_fd(strerror(errno), STDERR);
		return (1);
	}
	ft_putendl_fd(buf, STDOUT);
	return (0);
}
