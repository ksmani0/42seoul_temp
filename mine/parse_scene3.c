#include "minirt.h"

void	parse_sphere(t_scene *s, char **line)
{
	char        **buf;
    t_sphere    *tmp;

    s->idx[4]--;
	if (!(tmp = (t_sphere*)malloc(sizeof(t_sphere)))
    || !(buf = ft_split(line, ' ')))
	{
		free_parsing_buf(0, line);
		check_error_exit(s, 5);
	}
	tmp->center = parse_coord(s, buf[1], line);
	tmp->radius = ft_atof(buf[2], buf[2]);
	tmp->rgb = parse_rgb(s, buf[3], line);
    if (tmp->rgb.r < 0 || tmp->rgb.r > 255 || tmp->rgb.g < 0 ||
    tmp->rgb.g > 255 || tmp->rgb.b < 0 || tmp->rgb.b > 255 || buf[4] != 0)
    {
        free_parsing_buf(buf, line);
		check_error_exit(s, 6);
    }
    s->sphere[s->idx[4]] = tmp;
	free_parsing_buf(buf, line);
}

void	parse_plane(t_scene *s, char **line)
{
	char **buf;

    s->idx[5]--;
	if (!(s->plane[s->idx[5]] = (t_plane*)malloc(sizeof(t_plane)))
    || !(buf = ft_split(line, ' ')))
	{
		free_parsing_buf(0, line);
		check_error_exit(s, 5);
	}
	s->plane[s->idx[5]]->point = parse_coord(s, buf[1], line);
	s->plane[s->idx[5]]->n = parse_coord(s, buf[2], line);
	s->plane[s->idx[5]]->rgb = parse_rgb(s, buf[3], line);
    if ((is_n_valid(s->plane[s->idx[5]]->n)) == -1 ||
    s->plane[s->idx[5]]->rgb.r < 0 || s->plane[s->idx[5]]->rgb.r > 255 ||
    s->plane[s->idx[5]]->rgb.g < 0 || s->plane[s->idx[5]]->rgb.g > 255 ||
    s->plane[s->idx[5]]->rgb.b < 0 || s->plane[s->idx[5]]->rgb.b > 255
    || buf[4] != 0)
    {
        free_parsing_buf(buf, line);
		check_error_exit(s, 6);
    }
	free_parsing_buf(buf, line);
}

void	parse_square(t_scene *s, char **line)
{
	char **buf;

    s->idx[6]--;
	if (!(s->square[s->idx[6]] = (t_square*)malloc(sizeof(t_square)))
    || !(buf = ft_split(line, ' ')))
	{
		free_parsing_buf(0, line);
		check_error_exit(s, 5);
	}
	s->square[s->idx[6]]->center = parse_coord(s, buf[1], line);
	s->square[s->idx[6]]->n = parse_coord(s, buf[2], line);
	s->square[s->idx[6]]->side = ft_atof(buf[3], buf[3]);
    s->square[s->idx[6]]->rgb = parse_rgb(s, buf[4], line);
    if ((is_n_valid(s->square[s->idx[6]]->n)) == -1 ||
    s->square[s->idx[6]]->rgb.r < 0 || s->square[s->idx[6]]->rgb.r > 255
    || s->square[s->idx[6]]->rgb.g < 0 ||
    s->square[s->idx[6]]->rgb.g > 255 || s->square[s->idx[6]]->rgb.b < 0
    || s->square[s->idx[6]]->rgb.b > 255 || buf[5] != 0)
    {
        free_parsing_buf(buf, line);
		check_error_exit(s, 6);
    }
    s->square[s->idx[6]]->dx = (t_vec3){ 0, 1, 0 };
    s->square[s->idx[6]]->dy = (t_vec3){ 0, 0, 0 };
	free_parsing_buf(buf, line);
}

void	parse_cylinder(t_scene *s, char **line)
{
	char        **buf;
    t_cylinder  *tmp;

    s->idx[7]--;
	if (!(tmp = (t_cylinder*)malloc(sizeof(t_cylinder)))
    || !(buf = ft_split(line, ' ')))
	{
		free_parsing_buf(0, line);
		check_error_exit(s, 5);
	}
	tmp->point = parse_coord(s, buf[1], line);
	tmp->n = parse_coord(s, buf[2], line);
    tmp->rgb = parse_rgb(s, buf[3], line);
	tmp->radius = ft_atof(s, buf[4]) / 2;
    tmp->height = ft_atof(s, buf[5]);
    if ((is_n_valid(tmp->n)) == -1 || buf[6] != 0 || tmp->rgb.r < 0
    || tmp->rgb.r > 255 || tmp->rgb.g < 0 || tmp->rgb.g > 255
    || tmp->rgb.b < 0 || tmp->rgb.b > 255)
    {
        free_parsing_buf(buf, line);
		check_error_exit(s, 6);
    }
    s->cylinder[s->idx[7]] = tmp;
	free_parsing_buf(buf, line);
}

void	parse_triangle(t_scene *s, char **line)
{
	char        **buf;
    t_triangle  *tmp;

    s->idx[8]--;
	if (!(tmp = (t_triangle*)malloc(sizeof(t_triangle))) ||
    !(buf = ft_split(line, ' ')))
	{
		free_parsing_buf(0, line);
		check_error_exit(s, 5);
	}
	tmp->a = parse_coord(s, buf[1], line);
	tmp->b = parse_coord(s, buf[2], line);
    tmp->c = parse_coord(s, buf[2], line);
    tmp->rgb = parse_rgb(s, buf[3], line);
    if (buf[6] != 0 || tmp->rgb.r < 0 || tmp->rgb.r > 255 ||
    tmp->rgb.g < 0 || tmp->rgb.g > 255 ||
    tmp->rgb.b < 0 || tmp->rgb.b > 255)
    {
        free_parsing_buf(buf, line);
		check_error_exit(s, 6);
    }
    get_triangle_edges(tmp);//모서리와 외적한 벡터=법선의 방향 구함
    s->triangle[s->idx[8]] = tmp;
	free_parsing_buf(buf, line);
}
