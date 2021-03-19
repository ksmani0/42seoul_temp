/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseo <tseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 10:10:14 by tseo              #+#    #+#             */
/*   Updated: 2021/03/18 20:48:30 by tseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <errno.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include "../libft/libft.h"
# include "const.h"
# include "data_types.h"

extern int	g_exit_status;
extern char	**g_envs;

/*
** read_input
*/
int		get_input_line(char **line);

/*
**  memory free
*/
void	free_2d_arr(char **arr);
void	free_tokens(char **tokens);

/*
** utils/ft_charset_split
*/
char	**ft_charset_split(char *str, char *charset);

/*
** utils/gnl
*/
char	*ft_strappend(char *s1, char *s2);
int		get_next_line(int fd, char **line);

/*
** utils/main_utils
*/
void	print_prompt(void);
char	**get_envs(char **envs, int cnt);
void	free_double_arr(char **arr);
int		ft_arrsize(char **arr);

/*
** utils/handling_signals.c
*/
void	handle_main_signals(void);
void	main_signal_handler(int signo);
void	child_signal_hanlder(int signo);

/*
** parser
*/
t_cmd	*parse_input_line(char *line);

/*
** lexer
*/
char	*get_token(char *line, int token_size);
int		skip_separator_spaces(char *line, int i);
int		skip_separator(char *line, int i);
int		check_backslash(char *line, int *i, char quote);
int		check_and_jmp_quotes(char *line, int i);
int		count_tokens(char *line);

/*
** token checker
*/
int		check_tokens(char **tokens);

/*
** parse util
*/
int		is_separtor(char *sep, char c);
int		is_redirection(char *token);
int		is_pipe(char *token);
int		is_semicolon(char *token);
char	*get_envs_value(char *key);

/*
** token conversion
*/
char	*convert_normal_token(char *token);

char	*convert_sq_token(char *token);
char	*convert_env_token(char *token);
char	*convert_dq_token(char *token);
char	*handling_dq_env(char *token);
char	*handling_dq_doublequotes(char *token);
char	*convert_sq_token(char *token);
char	*handling_dq_backslash(char *token);

void	init_env_info(t_env_info *e_info);
void	count_dollors(char *token, t_env_info *e_info);
void	find_keys(char *token, char **dq_envs, t_env_info e_info);
void	calc_env_key_len(char *temp, int i, int *env_key_len);

/*
** init_cmd_list
*/
t_cmd	*make_cmd_list(char **tokens);
int		find_node_type(char *token);

/*
** error
*/
void	quotes_error(void);
void	memory_alloc_error(void);
void	fatal_error(void);
void	failed_create_file(void);
int		syntax_error(char *token);
void	no_command_error(char *cmd);
int		too_many_args_error(char *cmd);
void	no_file_error(char *path);
void	valid_key_error(char *cmd, char *arg);

/*
** linked_list
*/
void	append_node(t_cmd **head, t_cmd *new_node);
void	print_list(t_cmd *head);
void	clear_list(t_cmd *head);

/*
** execute
*/
int		exec_commands(t_cmd *cmd);
void	exec_command(t_cmd *cmd);
char	*find_path(char *cmd);

/*
** execute util
*/
int		has_redirection(t_cmd *cmd);
void	get_exit_code(int status, int set_exit);
int		is_built_in(t_cmd *cmd);
int		run_built_in(t_cmd *cmd);

/*
** redirection
*/
void	make_redirection(t_cmd *cmd);
void	get_redir_count(t_cmd *cmd, t_redir *redir_info);
void	output_redir_create_file(t_cmd *cmd, int i);
void	output_redir_dup_close(t_cmd *cmd, int i);

/*
** builtin
*/
int		ft_echo(char **cmd_line);
int		ft_pwd(char **cmd_line);
int		ft_cd(char **cmd_line);
int		ft_env(char **cmd_line);
int		ft_exit(char **cmd_line);
int		ft_export(char **cmd_line);
int		ft_unset(char **cmd_line);

/*
** env_utils
*/
int		check_validkey(char *obj);
char	*get_key(char *obj);
char	*search_env(char *key);
t_env	*sort_env(t_env *env);
void	free_arr_env(t_env *env);

/*
** debugging
*/
void	print_list(t_cmd *head);

#endif
