/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseo <tseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 10:56:18 by tseo              #+#    #+#             */
/*   Updated: 2021/03/16 13:47:26 by tseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_prompt(void)
{
	ft_putstr_fd(COLOR_BR_BLUE, STDOUT);
	write(STDOUT_FILENO, "minishell", 10);
	ft_putstr_fd(COLOR_WHITE, STDOUT);
	ft_putstr_fd("$ ", STDOUT);
}

char	**get_envs(char **envs, int cnt)
{
	int		i;
	char	**temp;

	if (!(temp = (char **)malloc(sizeof(char *) * (cnt + 1))))
		exit(EXIT_FAILURE);
	i = -1;
	while (envs[++i])
		temp[i] = ft_strdup(envs[i]);
	temp[i] = NULL;
	return (temp);
}
