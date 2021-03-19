/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseo <tseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 12:19:36 by tseo              #+#    #+#             */
/*   Updated: 2021/03/18 20:46:59 by tseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	get_input_line(char **line)
{
	int		ret;
	char	*temp;
	char	*temp2;

	*line = ft_strdup("");
	while (1)
	{
		ret = get_next_line(STDIN, &temp2);
		if (g_exit_status != 1)
			temp = ft_strjoin(*line, temp2);
		else
			temp = ft_strdup(temp2);
		free(temp2);
		free(*line);
		*line = temp;
		ft_putstr_fd("  \b\b", STDOUT);
		if (ret == 0 && ft_strlen(*line) != 0)
			continue ;
		else if (ret == 0 && ft_strlen(*line) == 0)
			ft_putstr_fd("exit\n", STDOUT);
		break ;
	}
	return (ret);
}
