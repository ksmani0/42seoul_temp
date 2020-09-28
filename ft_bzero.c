/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungmki <seungmki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 22:13:07 by seungmki          #+#    #+#             */
/*   Updated: 2020/09/28 23:11:57 by seungmki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char *p;

	if (n == 0)
		return ;
	p = (unsigned char*)s;
	while (n-- != 0)
		*p++ = 0;
}
