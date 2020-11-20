/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suntlee <suntlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 17:47:28 by suntlee           #+#    #+#             */
/*   Updated: 2020/02/28 23:14:15 by suntlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t len;

	len = 0;
	if (size > 0)
	{
		while (src[len] && len + 1 < size)
		{
			dst[len] = src[len];
			len++;
		}
		dst[len] = 0;
	}
	while (src[len])
		len++;
	return (len);
}
