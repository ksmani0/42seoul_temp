/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungmki <seungmki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 15:21:49 by seungmki          #+#    #+#             */
/*   Updated: 2020/09/30 00:04:35 by seungmki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*sp;
	char	*ep;
	char	*arr;
	char	*p;

	if (s1 == 0 || set == 0)
		return ((void*)0);
	while (*s1 != 0 && ft_strchr(set, *s1))
		s1++;
	sp = (char*)s1;
	ep = (ft_strlen(s1) - 1) + (char*)s1;
	while (ep > sp && ft_strchr(set, *ep))
		ep--;
	arr = (char*)malloc(sizeof(char) * (ep - sp + 1));
	if (arr == 0)
		return ((void*)0);
	p = arr;
	while (sp <= ep)
	{
		*p++ = *sp++;
	}
	*p = 0;
	return (arr);
}
