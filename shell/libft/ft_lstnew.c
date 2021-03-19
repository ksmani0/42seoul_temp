/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseo <tseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 15:42:39 by tseo              #+#    #+#             */
/*   Updated: 2020/10/06 15:46:05 by tseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list *new_elem;

	if (!(new_elem = malloc(sizeof(t_list))))
		return (0);
	new_elem->content = content;
	new_elem->next = 0;
	return (new_elem);
}
