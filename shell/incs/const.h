/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   const.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseo <tseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 08:49:43 by tseo              #+#    #+#             */
/*   Updated: 2021/03/18 20:43:03 by tseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONST_H
# define CONST_H

# define STDIN 0
# define STDOUT 1
# define STDERR 2
# define MAXSIZE 1024

# define TYPE_END 0
# define TYPE_PIPE 1
# define TYPE_BREAK 2

# define COLOR_BR_BLUE "\033[34;1m"
# define COLOR_WHITE "\033[37m"
# define COLOR_CYAN "\033[36m"
# define END_COLOR "\033[0m"

# define MAX_FD 1024
# define GNL_BUFFER_SIZE 25

# define SEPARATOR_SPACE " \t<>|;"
# define SEPARATOR "<>|;"

# define PATH_MAX 1024

#endif
