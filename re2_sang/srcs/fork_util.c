/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghpar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 19:17:09 by sanghpar          #+#    #+#             */
/*   Updated: 2020/11/19 14:00:25 by sanghpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	parent_fork(t_cmd *c_list)
{
	pid_t	pid;
	//int		status;

	g_data->forked = 1;
	pid = fork();
	g_data->last_pid = pid;
	if (pid < 0)
		return ;
	if (pid == 0)
	{
		exit(child_execute(c_list));
	}
	else
	{
		waitpid(pid, &status, 0);
		close(c_list->fds[1]);
		if (WIFEXITED(status))
			g_data->ret = WEXITSTATUS(status);
	}
}