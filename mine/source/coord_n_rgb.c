#include "../include/minirt.h"

t_vec3    parse_coord(t_scene *s, char *buf, char **line)
{
    t_vec3  result;
    char    **comma;

    if (!(comma = ft_split(buf, ',')))
    {
        free_parsing_buf(buf, line);
		check_error_exit(s, 5);
    }
    result.x = ft_atof(comma[0], comma[0]);
    result.y = ft_atof(comma[1], comma[1]);
    result.z = ft_atof(comma[2], comma[2]);
    free_parsing_buf(buf, line);
    return (result);
}

t_rgb      parse_rgb(t_scene *s, char *buf, char **line)
{
    t_rgb   result;
    char    **comma;

    if (!(comma = ft_split(buf, ',')))
    {
        free_parsing_buf(buf, line);
		check_error_exit(s, 5);
    }
    result.r = ft_atoi(comma[0]);
    result.g = ft_atoi(comma[1]);
    result.b = ft_atoi(comma[2]);
    free_parsing_buf(buf, line);
    return (result);
}

int         check_filter(t_scene *s, char *buf)
{
    if (buf == 0)
        return (1);
    else if (ft_strncmp(s, "sepia", 5) == 0)
    {
        s->filter = 's';
        return (1);
    }
    else if (ft_strncmp(s, "red", 3) == 0)
    {
        s->filter = 'r';
        return (1);
    }
    else if (ft_strncmp(s, "green", 5) == 0)
    {
        s->filter = 'g';
        return (1);
    }
    else if (ft_strncmp(s, "blue", 4) == 0)
    {
        s->filter = 'b';
        return (1);
    }
    return (0);
}

void        resize_resolution(t_scene *s)
{
    int *x;
    int *y;

    mlx_get_screen_size(s->win.mlx_p, x, y);
    if (s->x > x)
        s-> x = x;
    if (s->y > y)
        s->y = y;
}
