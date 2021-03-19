/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseo <tseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 19:11:56 by tseo              #+#    #+#             */
/*   Updated: 2020/10/06 20:14:39 by tseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t i;

	i = 0;
	while (*dst && i < size)
	{
		i++;
		dst++;
	}
	while (*src && i + 1 < size)
	{
		*dst++ = *src++;
		i++;
	}
	if (i < size)
		*dst = 0;
	while (*src++)
		i++;
	return (i);
}
