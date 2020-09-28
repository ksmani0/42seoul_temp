/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungmki <seungmki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 20:06:53 by seungmki          #+#    #+#             */
/*   Updated: 2020/09/28 20:39:58 by seungmki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void			*arr;
	unsigned char	*p;
	size_t			len;
	size_t			i;

	arr = malloc(size * count);
	if (arr == 0)
		return ((void*)0);
	p = (unsigned char*)arr;
	len = size * count;
	i = 0;
	while (i < len)
	{
		*p++ = 0;
		i++;
	}
	return (arr);
}
