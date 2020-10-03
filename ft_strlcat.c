/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungmki <seungmki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 14:34:17 by seungmki          #+#    #+#             */
/*   Updated: 2020/10/03 12:52:18 by seungmki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	len;

	len = 0;
	while (*dst++ != 0 && len < dstsize)
		len++;
	while (*src != 0 && len + 1 < dstsize)
	{
		*dst++ = *src++;
		len++;
	}
	*dst = 0;
	while (*src++ != 0)
		len++;
	return (len);
}
