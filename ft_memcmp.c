/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungmki <seungmki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 12:55:08 by seungmki          #+#    #+#             */
/*   Updated: 2020/09/29 13:19:26 by seungmki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char *p1;
	unsigned char *p2;

	p1 = (unsigned char*)s1;
	p2 = (unsigned char*)s2;
	while (*p1 != 0 && *p1 == *p2 && n != 0)
	{
		p1++;
		p2++;
		n--;
	}
	return (*p1 - *p2);
}
