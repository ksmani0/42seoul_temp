/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungmki <seungmki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 19:52:24 by seungmki          #+#    #+#             */
/*   Updated: 2020/09/28 20:41:21 by seungmki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*strdup(const char *s)
{
	size_t	size;
	char	*arr;

	size = ft_strlen(s);
	arr = (char*)malloc(sizeof(char) * size + 1);
	if (arr == 0)
		return ((void*)0);
	while (*s != 0)
		*arr++ = *s++;
	*arr = 0;
	return (arr);
}
