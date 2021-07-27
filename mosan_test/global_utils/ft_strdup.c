/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehakam <ehakam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 20:28:11 by ehakam            #+#    #+#             */
/*   Updated: 2021/07/06 21:10:29 by ehakam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/global_utils.h"

char	*ft_strdup(const char *s)
{
	int		i;
	int		st;
	char	*ss;

	st = ft_strlen(s);
	ss = (char *)ft_malloc(st + 1);
	i = -1;
	while (s[++i])
		ss[i] = s[i];
	ss[i] = '\0';
	return (ss);
}
