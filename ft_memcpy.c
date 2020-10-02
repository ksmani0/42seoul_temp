/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungmki <seungmki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 23:34:34 by seungmki          #+#    #+#             */
/*   Updated: 2020/10/03 00:07:31 by seungmki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*dp;
	const unsigned char *sp;

	if (dst == 0 || src == 0)
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
