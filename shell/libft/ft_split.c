/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseo <tseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 10:31:41 by tseo              #+#    #+#             */
/*   Updated: 2020/10/23 21:55:04 by tseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(char const *s, char c)
{
	size_t size;

	size = 0;
	while (*s != 0)
	{
		if (*s != c && *s != 0)
		{
			size++;
			while (*s != c && *s != 0)
				s++;
		}
		else if (*s != 0)
			s++;
	}
	return (size);
}

static void		ft_strcpy(char *str, char *p, char const *s)
{
	while (p < s)
		*str++ = *p++;
	*str = 0;
}

static void		split_words(char **words_arr, char const *s, char c)
{
	size_t	i;
	char	*p;

	if (*s == 0)
		return ;
	i = 0;
	while (*s != 0)
	{
		if (*s != c && *s != 0)
		{
			p = (char*)s;
			while (*s != c && *s != 0)
				s++;
			words_arr[i] = (char*)malloc(sizeof(char) * (s - p + 1));
			ft_strcpy(words_arr[i], p, s);
			i++;
		}
		else if (*s != 0)
			s++;
	}
}

char			**ft_split(char const *s, char c)
{
	char	**words_arr;
	size_t	size;

	if (s == 0)
		return (0);
	size = count_words(s, c);
	words_arr = (char**)malloc(sizeof(char*) * (size + 1));
	if (words_arr == 0)
		return (0);
	words_arr[size] = 0;
	if (size == 0)
		return (words_arr);
	split_words(words_arr, s, c);
	return (words_arr);
}
