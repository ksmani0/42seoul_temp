/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungmki <seungmki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 15:08:44 by seungmki          #+#    #+#             */
/*   Updated: 2020/10/03 14:17:19 by seungmki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char *p;

	p = (char*)s;
	while (*s != 0)
		s++;
	while (--s != p)
	{
		if (*s == (char)c)
			return ((char*)s);
	}
	if (*s == (char)c)
		return ((char*)s);
	return ((void*)0);
}
