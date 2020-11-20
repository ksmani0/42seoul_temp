/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suntlee <suntlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/09 21:28:11 by suntlee           #+#    #+#             */
/*   Updated: 2020/09/05 19:48:55 by suntlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memset(void *ptr, int x, size_t n)
{
	unsigned char *p;

	p = (unsigned char *)ptr;
	while (n--)
		*(p++) = x;
	return (ptr);
}
