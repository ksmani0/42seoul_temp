/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseo <tseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 15:31:51 by tseo              #+#    #+#             */
/*   Updated: 2020/10/06 20:08:43 by tseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *ptr1, const void *ptr2, size_t n)
{
	while (n--)
	{
		if (*(unsigned char*)ptr1 != *(unsigned char*)ptr2)
			return (*(unsigned char*)ptr1 - *(unsigned char*)ptr2);
		ptr1++;
		ptr2++;
	}
	return (0);
}
