/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungmki <seungmki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 23:34:34 by seungmki          #+#    #+#             */
/*   Updated: 2020/09/29 00:12:23 by seungmki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
	unsigned char		*dp;
	const unsigned char *sp;

	if (dst == 0 || (dst == 0 && src == 0))
		return ((void*)0);
	dp = (unsigned char*)dst;
	sp = (const unsigned char*)src;
	while (n != 0)
	{
		*dp++ = *sp++;
		n--;
	}
	return (dst);
}
