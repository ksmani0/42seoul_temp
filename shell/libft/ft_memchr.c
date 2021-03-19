/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseo <tseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 15:18:40 by tseo              #+#    #+#             */
/*   Updated: 2020/10/03 15:27:41 by tseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *ptr, int value, size_t n)
{
	while (n--)
	{
		if (*(unsigned char*)ptr == (unsigned char)value)
			return ((void*)ptr);
		ptr++;
	}
	return (NULL);
}
