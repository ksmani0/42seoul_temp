/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungmki <seungmki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 15:08:44 by seungmki          #+#    #+#             */
/*   Updated: 2020/09/28 15:26:15 by seungmki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	char *p;

	p = s;
	while (*s != 0)
		s++;
	while (--s != p)
	{
		if (*s == (char)c)
			return (s);
	}
	if (*s == (char)c)
		return (s);
	return ((void*)0);
}
