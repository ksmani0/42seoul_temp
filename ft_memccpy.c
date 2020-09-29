/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungmki <seungmki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 09:56:23 by seungmki          #+#    #+#             */
/*   Updated: 2020/09/29 10:27:35 by seungmki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*dp;
	unsigned char	*sp;
	size_t			i;

	if (dst == 0 || (dst == 0 && src == 0))
		return ((void*)0);
	dp = (unsigned char*)dst;
	sp = (unsigned char*)src;
	i = 0;
	while (i < n)
	{
		*dp = *sp++;
		if (*dp == (unsigned char)c)
			return (dp + 1);
		dp++;
		i++;
	}
	return ((void*)0);
}
