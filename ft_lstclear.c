/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungmki <seungmki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 13:57:11 by seungmki          #+#    #+#             */
/*   Updated: 2020/10/02 23:04:41 by seungmki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list **p;

	if (lst == 0 || del == 0)
		return ;
	while (*lst != 0)
	{
		p = &(*lst)->next;
		del((*lst)->content);
		free(*lst);
		lst = p;
	}
}
