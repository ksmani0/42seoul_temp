/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cmd_list_util.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseo <tseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 17:49:25 by tseo              #+#    #+#             */
/*   Updated: 2021/03/18 17:51:43 by tseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

int			find_node_type(char *token)
{
	if (token == 0)
		return (0);
	if (ft_strncmp(token, "|", 1) == 0)
		return (1);
	if (ft_strncmp(token, ";", 1) == 0)
		return (2);
	return (-1);
}
