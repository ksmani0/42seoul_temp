/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungmki <seungmki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 13:06:17 by seungmki          #+#    #+#             */
/*   Updated: 2020/10/19 13:10:42 by seungmki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include "libft/libft.h"

typedef struct s_format {
	char	*str;
	char	flags[7];/*-0.*# +*/
	char	specifier;/*cspdiuxX%nfge*/
	char	if_num[12];
	int	width;
	int	precision;
	int	length;/*h:1, hh:2, l:3, ll:6*/
	int	output_len;
	int	output_num;
}		t_format

#endif
