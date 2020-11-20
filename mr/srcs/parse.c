/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suntlee <suntlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 15:07:31 by suntlee           #+#    #+#             */
/*   Updated: 2020/11/19 16:56:52 by suntlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void		parse(t_minilibx *mlx, t_scene *data, t_figures **lst,
						char **str_ptr)
{
	char	*str;

	str = *str_ptr;
	if (!ft_strncmp(str, "R", 1) && *(str++))
		parse_res(data, &str);
	else if (!ft_strncmp(str, "A", 1) && *(str++))
		parse_ambient_lightning(data, &str);
	else if (*str == 'l' && *(str++))
		parse_light(data, &str);
	else if (*str == 'c' && (*(str + 1) == ' ' || *(str + 1) == '\t')
			&& *(str++))
		parse_camera(mlx, data, &str);
	else if (!ft_strncmp(str, "cy", 2) && *(str++) && *(str++))
		parse_cylinder(lst, &str);
	else if (!ft_strncmp(str, "sp", 2) && *(str++) && *(str++))
		parse_sphere(lst, &str);
	else if (!ft_strncmp(str, "sq", 2) && *(str++) && *(str++))
		parse_square(lst, &str);
	else if (!ft_strncmp(str, "pl", 2) && *(str++) && *(str++))
		parse_plane(lst, &str);
	else if (!ft_strncmp(str, "tr", 2) && *(str++) && *(str++))
		parse_triangle(lst, &str);
	else if (*str != '\n')
		scene_error("formatted incorrectly");
	*str_ptr = str;
}

static void		parse_elems(t_minilibx *mlx, t_scene *data, t_figures **lst,
							char *str)
{
	data->res_init = 0;
	data->al_init = 0;
	while (*str)
	{
		parse(mlx, data, lst, &str);
		if (!(*str))
			break ;
		if (*str != '\n')
			scene_error("formatted incorrectly");
		str++;
	}
	if (data->res_init == 0 || data->al_init == 0 || mlx->cam == NULL)
		scene_error("Not enough elements");
}

void			parse_scene(t_minilibx *mlx, t_scene *data, t_figures **lst,
							char **argv)
{
	char	*str;
	int		fd;

	*lst = NULL;
	data->l = NULL;
	mlx->cam = NULL;
	write(1, "Parsing the scene...\n", 21);
	if (!(str = (char *)malloc(sizeof(char) * (BUFSIZE + 1))))
		fatal_error("in malloc");
	ft_memset(str, 0, sizeof(char) * (BUFSIZE + 1));
	if (ft_strncmp(argv[1] + ft_strlen(argv[1]) - 3, ".rt", 3) != 0)
		fatal_error("not a rt file");
	if ((fd = open(argv[1], O_RDONLY)) < 0)
		fatal_error("opening a file");
	if ((str = readfile(str, fd)) == NULL)
		fatal_error("reading a file");
	parse_elems(mlx, data, lst, str);
	free(str);
}
