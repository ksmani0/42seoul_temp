/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suntlee <suntlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 15:19:03 by suntlee           #+#    #+#             */
/*   Updated: 2020/11/09 16:42:15 by suntlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "includes/libft.h"

static int	is_in_set(char c, char const *set)
{
	int i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static void	ft_strcpy_idx(char *dest, const char *src, int start, int end)
{
	int i;

	i = 0;
	while (start + i <= end)
	{
		dest[i] = src[start + i];
		i++;
	}
	dest[i] = 0;
}

char		*ft_strtrim(char const *s1, char const *set)
{
	int		leading;
	int		trailing;
	int		size;
	char	*ptr;

	leading = 0;
	while (s1[leading] && is_in_set(s1[leading], set))
		leading++;
	trailing = ft_strlen(s1) - 1;
	while (trailing >= 0 && is_in_set(s1[trailing], set))
		trailing--;
	size = (leading >= trailing) ? 1 : trailing - leading + 1;
	ptr = (char *)malloc(sizeof(char) * size);
	if (!ptr)
		return (NULL);
	ft_strcpy_idx(ptr, s1, leading, trailing);
	return (ptr);
}
