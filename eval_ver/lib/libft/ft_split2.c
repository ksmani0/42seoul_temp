/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghpar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 19:24:37 by sanghpar          #+#    #+#             */
/*   Updated: 2020/10/05 00:09:30 by sanghpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

bool	split2_is_sep(char c, char sep)
{
	if (sep == c)
		return (true);
	return (false);
}

void	split2_jumpaa(char *start, char c, int *i)
{
	char	*tmp;

	tmp = (start) + *i;
	tmp++;
	while (tmp)
	{
		if (*tmp == c)
			break ;
		tmp++;
		*i = *i + 1;
	}
	*i = *i + 1;
}

int	split2_count_array(char *str, char sep)
{
	int		i;
	bool	flag;
	int		count;

	flag = true;
	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '"' || str[i] == '\'')
			split2_jumpaa(str, str[i], &i);
		else if (split2_is_sep(str[i], sep))
			flag = true;
		else
		{
			if (flag)
				count++;
			flag = false;
		}
		i++;
	}
	return (count);
}

char	*split2_create_arr(char *str, char sep, int *ip)
{
	int		i;
	char	*arr;

	arr = (void *)0;
	i = 0;
	haha(str, &i, sep);
	arr = (char *)malloc((i + 1) * sizeof(char));
	i = 0;
	while (str[i] != 0x00)
	{
		if (str[i] == '"' || str[i] == '\'')
			jumpaa3(str, str[i], &i, &arr);
		if (split2_is_sep(str[i], sep))
			break ;
		arr[i] = str[i];
		if (str[i] != 0x00)
			i++;
	}
	*ip = i;
	arr[i] = 0x00;
	return (arr);
}

char	**ft_split2(char *str, char charset, int index, char *r_arr)
{
	int		size_count;
	char	**p_arr;

	size_count = split2_count_array(str, charset);
	p_arr = (char **)malloc((size_count + 1) * sizeof(char *));
	p_arr[size_count] = (void *)0;
	if (size_count == 1)
	{
		p_arr[0] = ft_strdup(str);
		return (p_arr);
	}
	while (*str)
	{
		if (*str == '"' || *str == '\'')
			jumpaa2(&str, *str, 0);
		else if (*str == charset)
			str++;
		else
		{
			r_arr = split2_2(&str, charset);
			if (r_arr)
				p_arr[index++] = r_arr;
		}
	}
	return (p_arr);
}
