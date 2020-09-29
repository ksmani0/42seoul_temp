/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungmki <seungmki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 15:21:49 by seungmki          #+#    #+#             */
/*   Updated: 2020/09/29 16:18:47 by seungmki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	isset(char const *set, char c)
{
	while (*set != 0)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

static int	num_set(char const *s, char const *set)
{
	int num;

	num = 0;
	while (*s != 0)
	{
		if (isset(set, *s) == 1)
			num++;
		s++;
	}
	return (num);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len;
	char	*arr;
	char	*p;

	if (s1 == 0 || set == 0)
		return ((void*)0);
	len = ft_strlen(s1) - num_set(s1);
	arr = (char*)malloc(sizeof(char) * len + 1);
	if (arr == 0)
		return ((void*)0);
	arr[len] = 0;
	p = arr;
	while (*s1 != 0)
	{
		if (isset(set, *s1) == 0)
			*p++ = *s1;
		s1++;
	}
	return (arr);
}
