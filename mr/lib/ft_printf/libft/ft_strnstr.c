/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suntlee <suntlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 18:58:02 by suntlee           #+#    #+#             */
/*   Updated: 2020/02/29 00:12:25 by suntlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t big_idx;
	size_t lit_idx;

	if (!big || !little)
		return (NULL);
	if (!(*little))
		return (char *)(big);
	big_idx = 0;
	while (big_idx < len)
	{
		lit_idx = 0;
		while (big_idx + lit_idx < len && big[big_idx] && little[lit_idx] &&
			big[big_idx + lit_idx] == little[lit_idx])
			lit_idx++;
		if (!little[lit_idx])
			return (char *)(big + big_idx);
		big_idx++;
	}
	return (NULL);
}
