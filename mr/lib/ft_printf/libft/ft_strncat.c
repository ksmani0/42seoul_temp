/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suntlee <suntlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 17:38:49 by suntlee           #+#    #+#             */
/*   Updated: 2020/10/20 17:39:02 by suntlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dst, char *src, int nb)
{
	int	i;
	int	dst_size;

	i = 0;
	dst_size = 0;
	while (dst[dst_size])
		dst_size++;
	while (i < nb && src[i])
	{
		dst[dst_size] = src[i];
		dst_size++;
		i++;
	}
	dst[dst_size] = '\0';
	return (dst);
}
