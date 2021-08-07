/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split2_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghpar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 19:24:37 by sanghpar          #+#    #+#             */
/*   Updated: 2020/10/05 00:09:30 by sanghpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*split2_2(char **str, char charset)
{
	char	*r_arr;
	int		size_count;

	size_count = 0;
	r_arr = split2_create_arr(*str, charset, &size_count);
	*str = *str + size_count;
	return (r_arr);
}
