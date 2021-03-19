/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseo <tseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 08:47:55 by tseo              #+#    #+#             */
/*   Updated: 2021/03/18 09:26:40 by tseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

void	append_node(t_cmd **head, t_cmd *new_node)
{
	t_cmd *tail;

	if ((*head) == NULL)
		*head = new_node;
	else
	{
		tail = (*head);
		while (tail->next != NULL)
			tail = tail->next;
		tail->next = new_node;
		new_node->prev = tail;
	}
}

void	clear_list(t_cmd *head)
{
	t_cmd *tmp;

	while (head)
	{
		free_2d_arr(head->args);
		free_2d_arr(head->redir);
		free_2d_arr(head->path);
		tmp = head;
		head = tmp->next;
		free(tmp);
	}
}
