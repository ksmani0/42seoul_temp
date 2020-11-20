/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suntlee <suntlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 17:07:01 by suntlee           #+#    #+#             */
/*   Updated: 2020/11/20 18:33:38 by suntlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	main(int argc, char **argv)
{
	t_minilibx	mlx;
	t_scene		data;
	t_figures	*lst;
	t_wrapper	wrapper;

	if (argc < 2 || argc > 3)
		usage(argv[0]);
	if (argc == 3 && ft_strcmp(argv[2], "--save"))
		scene_error("invalid argument\n");
	parse_scene(&mlx, &data, &lst, argv);
	init_mlx(&mlx, &data);
	wrap_data(mlx, data, lst, &wrapper);
	render_thread(&wrapper);
	if (argc == 3)
		save_bmp(mlx, data, argv[1]);
	print_message(argc);
	graphic_loop(mlx, data);
	return (0);
}
