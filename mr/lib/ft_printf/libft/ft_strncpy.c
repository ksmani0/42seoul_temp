/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suntlee <suntlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 16:19:41 by suntlee           #+#    #+#             */
/*   Updated: 2020/11/09 17:14:18 by suntlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *dst, char *src, unsigned int nb)
{
	unsigned int i;

	i = 0;
	while (i < nb && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	while (i < nb)
		dst[i++] = '\0';
	return (dst);
}
