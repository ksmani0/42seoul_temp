#include "../include/minirt.h"

void	count_scene_obj(t_scene *scene, char *line)
{
	if (line[0] == 'R' && line[1] == ' ' && scene->idx[0] == 0)
		scene->idx_rec[0] = ++(scene->idx[0]);
	else if (line[0] == 'A' && line[1] == ' ' && scene->idx[1] == 0)
		scene->idx_rec[1] = ++(scene->idx[1]);
	else if (line[0] == 'c' && line[1] == ' ')
		scene->idx_rec[2] = ++(scene->idx[2]);
	else if (line[0] == 'l' && line[1] == ' ')
		scene->idx_rec[3] = ++(scene->idx[3]);
	else if (line[0] == 's' && line[1] == 'p' && line[2] == ' ')
		scene->idx_rec[4] = ++(scene->idx[4]);
	else if (line[0] == 'p' && line[1] == 'l' && line[2] == ' ')
		scene->idx_rec[5] = ++(scene->idx[5]);
	else if (line[0] == 's' && line[1] == 'q' && line[2] == ' ')
		scene->idx_rec[6] = ++(scene->idx[6]);
	else if (line[0] == 'c' && line[1] == 'y' && line[2] == ' ')
		scene->idx_rec[7] = ++(scene->idx[7]);
	else if (line[0] == 't' && line[1] == 'r' && line[2] == ' ')
		scene->idx_rec[8] = ++(scene->idx[8]);
}

void	malloc_scene_obj(t_scene *s)
{
	if (s->idx[0] != 1 || s->idx[1] != 1 || s->idx[2] < 1)
		check_error_exit(s, 5);
	if (!(s->camera = (t_camera**)malloc(sizeof(t_camera*)
	* (s->idx[2] + 1))))
		check_error_exit(s, 6);
	else if (!(s->light = (t_light**)malloc(sizeof(t_light*)
	* (s->idx[3] + 1))))
		check_error_exit(s, 6);
	else if (!(s->sphere = (t_sphere**)malloc(sizeof(t_sphere*)
	* (s->idx[4] + 1))))
		check_error_exit(s, 6);
	else if (!(s->plane = (t_plane**)malloc(sizeof(t_plane*)
	* (s->idx[5] + 1))))
		check_error_exit(s, 6);
	else if (!(s->square = (t_square**)malloc(sizeof(t_square*)
	* (s->idx[6] + 1))))
		check_error_exit(s, 6);
	else if (!(s->cylinder = (t_cylinder**)malloc(sizeof(t_cylinder*)
	* (s->idx[7] + 1))))
		check_error_exit(s, 6);
	else if (!(s->triangle = (t_triangle**)malloc(sizeof(t_triangle*)
	* (s->idx[8] + 1))))
		check_error_exit(s, 6);
}

void	fill_each_obj(t_scene *scene, char **line)
{
	if (line[0] == 'R' && line[1] == ' ' && scene->idx[0] == 0)
		parse_resolution(scene, line);
	else if (line[0] == 'A' && line[1] == ' ' && scene->idx[1] == 0)
		parse_ambient(scene, line);
	else if (line[0] == 'c' && line[1] == ' ')
		parse_camera(scene, line);
	else if (line[0] == 'l' && line[1] == ' ')
		parse_light(scene, line);
	else if (line[0] == 's' && line[1] == 'p' && line[2] == ' ')
		parse_sphere(scene, line);
	else if (line[0] == 'p' && line[1] == 'l' && line[2] == ' ')
		parse_plane(scene, line);
	else if (line[0] == 's' && line[1] == 'q' && line[2] == ' ')
		parse_square(scene, line);
	else if (line[0] == 'c' && line[1] == 'y' && line[2] == ' ')
		parse_cylinder(scene, line);
	else if (line[0] == 't' && line[1] == 'r' && line[2] == ' ')
		parse_triangle(scene, line);
}

void	fill_scene(char *file, t_scene *scene)
{
	int		fd;
	char	*line;
	int		ret;

	line = 0;
	fd = open(file, O_RDONLY);
	scene->camera[scene->idx[2]] = 0;
	scene->light[scene->idx[3]] = 0;
	scene->sphere[scene->idx[4]] = 0;
	scene->plane[scene->idx[5]] = 0;
	scene->square[scene->idx[6]] = 0;
	scene->cylinder[scene->idx[7]] = 0;
	scene->triangle[scene->idx[8]] = 0;
	while ((ret = get_next_line(fd, &line)) > 0)
		fill_each_obj(scene, &line);//free(line);//fill_each_obj() > parse_*() > free_parsing_buf() do free(line)
	close(fd);
	if (ret == -1)
	{
		free(line);
		check_error_exit(scene, 4);
	}
	fill_each_obj(scene, &line);
}

void	read_rt(char *file, t_scene *scene)
{
	int		fd;
	char	*line;
	int		ret;

	fd = open(file, O_RDONLY);
	line = 0;
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		count_scene_obj(scene, line);
		free(line);
	}
	close(fd);
	if (ret == -1)
	{
		free(line);
		check_error_exit(scene, 4);
	}
	count_scene_obj(scene, line);
	free(line);
	malloc_scene_obj(scene);
	fill_scene(file, scene);
}
