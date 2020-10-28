/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str_point.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungmki <seungmki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 13:03:41 by seungmki          #+#    #+#             */
/*   Updated: 2020/10/27 11:47:13 by seungmki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_s_str(t_format *list)//0, +, ' '플래그는 s와는 정의되지 않은 결과로 에러
{
	char	*s;
	size_t	len;
	char	*out;

	if (list->flag[1] == 1 || list->flag[4] == 1 || list->flag[5] == 1)
		return (1);
	s = (char*)va_arg(list->ap, const char*);
	len = ft_strlen(s);//최소 너비.최대너비
	list->out_len = list->width > list->prec ? list->width : list->prec;
	list->out_len = len > list->out_len ? len : list->out_len;
	if ((out = (char*)malloc(sizeof(char) * (list->out_len + 1))) == 0)
		return (-1);
	
}

void	print_s_point(t_foramt *list)
{
	//
}