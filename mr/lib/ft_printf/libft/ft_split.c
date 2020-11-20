/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suntlee <suntlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 16:05:18 by suntlee           #+#    #+#             */
/*   Updated: 2020/09/14 14:53:07 by suntlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

static int	count_words(char const *s, char c)
{
	int	l;
	int	r;
	int	cnt;

	cnt = 0;
	r = 0;
	l = 0;
	while (s[r])
	{
		if (s[r] == c)
		{
			if (l != r)
				cnt++;
			l = r + 1;
		}
		r++;
	}
	if (l != r)
		cnt++;
	return (cnt);
}

static void	free_split(char **ptr, int num_strs)
{
	int i;

	i = 0;
	while (i < num_strs)
		free(ptr[i++]);
	free(ptr);
	*ptr = NULL;
}

static char	*make_str(const char *s, char c)
{
	char	*p;
	int		i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	p = (char *)malloc(sizeof(char) * (i + 1));
	if (!p)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != c)
	{
		p[i] = s[i];
		i++;
	}
	return (p);
}

char		**ft_split(char const *s, char c)
{
	char	**ptr;
	int		i;

	if (!s || !(ptr = (char **)malloc(sizeof(char *) *
				(count_words(s, c) + 1))))
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
		{
			if (!(ptr[i++] = make_str(s, c)))
			{
				free_split(ptr, i);
				return (NULL);
			}
			while (*s && *s != c)
				s++;
		}
	}
	ptr[i] = NULL;
	return (ptr);
}
