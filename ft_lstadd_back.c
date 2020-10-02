/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungmki <seungmki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 13:48:57 by seungmki          #+#    #+#             */
/*   Updated: 2020/10/02 13:51:40 by seungmki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (lst == 0)
	{
		*lst = new;
		return ;
	}
	while (lst->next != 0)
	{
		lst = lst->next;
	}
	lst->next = new;
}
