/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungmki <seungmki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 11:52:53 by seungmki          #+#    #+#             */
/*   Updated: 2020/10/02 14:51:11 by seungmki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	t_list **temp;

	if (lst == 0 || new == 0)
		return (NULL);
	temp = lst;
	new->next = *temp;
	lst = &new;
}
