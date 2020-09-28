/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungmki <seungmki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 13:52:40 by seungmki          #+#    #+#             */
/*   Updated: 2020/09/28 14:32:52 by seungmki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

size_t	ft_strlcpy(char *restrict dst, const char *restrict src, size_t dstsize)
{
	size_t	len;
	char	*sp;

	len = 0;
	sp = src;
	while (*sp++ != 0)
		len++;
	if (dstsize != 0)
	{
		while (dstsize > 1 && *src != 0)
		{
			*dst++ = *src++;
			dstsize--;
		}
		*dst = 0;
	}
	return (len);
}
