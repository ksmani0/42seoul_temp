/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungmki <seungmki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 00:26:14 by seungmki          #+#    #+#             */
/*   Updated: 2020/10/02 21:43:08 by seungmki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static void	make_min(char *num)
{
	num[0] = '-';
	num[1] = '2';
	num[2] = '1';
	num[3] = '4';
	num[4] = '7';
	num[5] = '4';
	num[6] = '8';
	num[7] = '3';
	num[8] = '6';
	num[9] = '4';
	num[10] = '8';
	num[11] = 0;
}

static void	make_num(char *arr, int n)
{
	int temp;
	int i;

	i = 0;
	if (n < 0)
	{
		n *= -1;
		arr[i++] = '-';
	}
	temp = n;
	while (temp > 0)
	{
		temp /= 10;
		i++;
	}
	arr[i] = 0;
	while (n > 0)
	{
		arr[--i] = n % 10 + '0';
		n /= 10;
	}
}

char		*ft_itoa(int n)
{
	char *arr;

	arr = (char*)malloc(sizeof(char) * 12);
	if (arr == 0)
		return ((void*)0);
	if (n == -2147483648)
		make_min(arr);
	else if (n == 0)
	{
		arr[0] = '0';
		arr[1] = 0;
	}
	else
		make_num(arr, n);
	return (arr);
}
