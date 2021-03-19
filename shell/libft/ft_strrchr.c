/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseo <tseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 11:51:28 by tseo              #+#    #+#             */
/*   Updated: 2021/03/04 10:55:36 by tseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char *ret;

	ret = 0;
	while (1)
	{
		if (*s == (unsigned char)c)
			ret = (char*)s;
		if (*s == 0)
			break ;
		s++;
	}
	return (ret);
}
