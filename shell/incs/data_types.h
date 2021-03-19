/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_types.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseo <tseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 08:48:32 by tseo              #+#    #+#             */
/*   Updated: 2021/03/18 20:49:49 by tseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_TYPES_H
# define DATA_TYPES_H

typedef struct		s_cmd
{
	char			**args;
	char			**redir;
	char			**path;
	int				type;
	int				fd[2];
	struct s_cmd	*prev;
	struct s_cmd	*next;
}					t_cmd;

typedef struct		s_redir
{
	int				input_redir_count;
	int				output_redir_count;
}					t_redir;

typedef	struct		s_node_info
{
	int				start_idx;
	int				end_idx;
	int				redir_count;
	int				args_count;
}					t_node_info;

typedef	struct		s_env_info
{
	int				dollor_count;
	int				env_key_len;
	char			*key;
	int				i;
	int				j;
	int				count;
}					t_env_info;

typedef struct		s_env
{
	char			*key;
	char			*value;
}					t_env;

#endif
