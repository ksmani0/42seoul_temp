/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cmd_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseo <tseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 15:17:38 by tseo              #+#    #+#             */
/*   Updated: 2021/03/18 17:59:52 by tseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

int		count_node_args(char **tokens, t_node_info *node_info)
{
	int i;
	int j;

	i = node_info->start_idx;
	j = node_info->end_idx;
	while (i < j)
	{
		if (is_redirection(tokens[i]))
		{
			if (ft_strncmp(tokens[i + 1], "|", 1) == 0
			|| ft_strncmp(tokens[i + 1], ";", 1) == 0
			|| tokens[i + 1] == 0)
				return (syntax_error(tokens[i]));
			(node_info->redir_count)++;
			i += 2;
		}
		else
		{
			if (ft_strncmp(tokens[i], "", 1) != 0)
				(node_info->args_count)++;
			i++;
		}
	}
	return (1);
}

void	init_new_node(t_cmd *new_node, t_node_info node_info, char **tokens)
{
	new_node->args = NULL;
	new_node->redir = NULL;
	new_node->path = NULL;
	if (!(new_node->args = (char **)malloc(sizeof(char *)
							* (node_info.args_count + 1))))
		memory_alloc_error();
	if (!(new_node->redir = (char **)malloc(sizeof(char *)
							* (node_info.redir_count + 1))))
		memory_alloc_error();
	if (!(new_node->path = (char **)malloc(sizeof(char *)
							* (node_info.redir_count + 1))))
		memory_alloc_error();
	new_node->args[node_info.args_count] = 0;
	new_node->redir[node_info.redir_count] = 0;
	new_node->path[node_info.redir_count] = 0;
	new_node->type = find_node_type(tokens[node_info.end_idx]);
	new_node->prev = NULL;
	new_node->next = NULL;
}

void	alloc_node_data(char **tokens, t_cmd *new_node, t_node_info info)
{
	int args_idx;
	int redir_idx;

	args_idx = 0;
	redir_idx = 0;
	while (info.start_idx < info.end_idx)
	{
		if (is_redirection(tokens[info.start_idx]))
		{
			new_node->redir[redir_idx] = ft_strdup(tokens[info.start_idx]);
			new_node->path[redir_idx] = ft_strdup(tokens[info.start_idx + 1]);
			redir_idx++;
			info.start_idx += 2;
		}
		else
		{
			if (ft_strncmp(tokens[info.start_idx], "", 1) != 0)
			{
				new_node->args[args_idx] = ft_strdup(tokens[info.start_idx]);
				args_idx++;
			}
			info.start_idx++;
		}
	}
}

int		create_cmd_node(t_cmd **head, char **tokens, int start_idx, int end_idx)
{
	t_cmd		*new_node;
	t_node_info	node_info;

	new_node = NULL;
	node_info.start_idx = start_idx;
	node_info.end_idx = end_idx;
	node_info.redir_count = 0;
	node_info.args_count = 0;
	count_node_args(tokens, &node_info);
	if (!(new_node = (t_cmd *)malloc(sizeof(t_cmd))))
		memory_alloc_error();
	init_new_node(new_node, node_info, tokens);
	alloc_node_data(tokens, new_node, node_info);
	append_node(head, new_node);
	return (1);
}

t_cmd	*make_cmd_list(char **tokens)
{
	t_cmd	*head_node;
	int		i;
	int		j;

	i = 0;
	j = i;
	head_node = NULL;
	while (tokens[i])
	{
		if (ft_strncmp(tokens[i], ";", 2) == 0
			|| ft_strncmp(tokens[i], "|", 1) == 0)
		{
			create_cmd_node(&head_node, tokens, j, i);
			j = i + 1;
		}
		else if (tokens[i + 1] == 0)
		{
			create_cmd_node(&head_node, tokens, j, i + 1);
			j = i + 1;
		}
		i++;
	}
	return (head_node);
}
