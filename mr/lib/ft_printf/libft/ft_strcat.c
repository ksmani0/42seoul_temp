/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suntlee <suntlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 16:18:05 by suntlee           #+#    #+#             */
/*   Updated: 2020/11/09 17:17:15 by suntlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dst, char *src)
{
	unsigned int	i;
	unsigned int	dst_size;

	i = 0;
	dst_size = 0;
	while (dst[dst_size])
		dst_size++;
	while (src[i])
		dst[dst_size++] = src[i++];
	dst[dst_size] = '\0';
	return (dst);
}
