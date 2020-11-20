/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ustrlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungmki </var/mail/seungmki>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 22:48:40 by seungmki          #+#    #+#             */
/*   Updated: 2020/11/20 22:48:43 by seungmki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_ustrlen(const t_uchar *s)
{
	size_t len;

	len = 0;
	while (*s != 0)
	{
		s++;
		len++;
	}
	return (len);
}
