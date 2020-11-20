/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrapper.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suntlee <suntlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 17:34:22 by suntlee           #+#    #+#             */
/*   Updated: 2020/11/13 18:09:03 by suntlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	*render_thread(void *wrapper)
{
	t_wrapper *w;

	w = (t_wrapper *)wrapper;
	while (w->mlx.cam)
	{
		render_scene(w);
		w->mlx.cam = w->mlx.cam->next;
	}
	return (NULL);
}

void	wrap_data(t_minilibx mlx, t_scene data, t_figures *lst,
					t_wrapper *wrapper)
{
	wrapper->mlx = mlx;
	wrapper->data = data;
	wrapper->lst = lst;
	wrapper->tid = 0;
}
