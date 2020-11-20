/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suntlee <suntlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 18:01:16 by suntlee           #+#    #+#             */
/*   Updated: 2020/11/09 16:40:53 by suntlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "includes/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	dst_idx;
	size_t	src_idx;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (dst_len >= size)
		return (size + src_len);
	dst_idx = dst_len;
	src_idx = 0;
	while (dst_idx + 1 < size && src[src_idx])
		dst[dst_idx++] = src[src_idx++];
	dst[dst_idx] = 0;
	return (dst_len + src_len);
}
