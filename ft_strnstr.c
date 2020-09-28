/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungmki <seungmki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 15:34:06 by seungmki          #+#    #+#             */
/*   Updated: 2020/09/28 16:22:04 by seungmki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	char	*bp;
	char	*lp;
	size_t	i;
	size_t	j;

	if (*bp == 0)
		return (char*)big;
	i = 0;
	while (*big != 0 && i < len)
	{
		bp = big;
		lp = little;
		j = i;
		while (*bp != 0 && *lp != 0 && *bp == *lp && j < len)
		{
			bp++;
			lp++;
			j++;
		}
		if (*lp == 0)
			return (char*)big;
		i++;
		big++;
	}
	return (void*)0;
}
