/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungmki <seungmki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 15:34:06 by seungmki          #+#    #+#             */
/*   Updated: 2020/10/03 21:51:48 by seungmki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	char	*bp;
	char	*lp;
	size_t	i;
	size_t	j;

	i = 0;
	while (*big != 0 && i < len)
	{
		bp = (char*)big;
		lp = (char*)little;
		j = i;
		while (*lp != 0 && *bp == *lp && j < len)
		{
			bp++;
			lp++;
			j++;
		}
		if (*lp == 0)
			return ((char*)big);
		i++;
		big++;
	}
	return (NULL);
}
