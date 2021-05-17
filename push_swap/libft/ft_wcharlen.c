/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wcharlen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungmki <seungmki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 00:08:17 by seungmki          #+#    #+#             */
/*   Updated: 2020/11/21 00:08:28 by seungmki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_wcharlen(const wchar_t *s)
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