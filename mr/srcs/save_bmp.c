/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_bmp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suntlee <suntlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 00:50:10 by suntlee           #+#    #+#             */
/*   Updated: 2020/11/18 17:15:08 by suntlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int			create_file(char *name)
{
	char	*bmpname;
	int		fd;
	int		len;
	int		j;

	j = 0;
	if (!(bmpname = (char *)malloc(ft_strlen(name) + 8)))
		fatal_error("in malloc");
	ft_memset(bmpname, 0, ft_strlen(name) + 8);
	len = ft_strlen(name) - 1;
	while (len >= 0 && name[len] != '/')
		len--;
	j = 0;
	len++;
	while (name[len] && name[len] != '.')
		bmpname[j++] = name[len++];
	bmpname[j] = '\0';
	ft_strcat(bmpname, ".bmp");
	if ((fd = open(bmpname, O_WRONLY | O_CREAT | O_TRUNC,
							S_IRUSR | S_IWUSR)) < 0)
		fatal_error("in save_bmp() while creating file");
	free(bmpname);
	return (fd);
}

void		create_header(t_scene data, t_bmp_header *header, t_dib_header *dib)
{
	header->type[0] = 0x42;
	header->type[1] = 0x4D;
	header->size = (data.xres * data.yres * 4) + 54;
	header->reserved = 0x00000000;
	header->offset = 0x36;
	dib->size = 40;
	dib->width = data.xres;
	dib->height = -data.yres;
	dib->colplanes = 1;
	dib->bpp = 32;
	dib->compression = 0;
	dib->img_size = (data.xres * data.yres * 4);
	dib->x_ppm = 2835;
	dib->y_ppm = 2835;
	dib->color_number = 0;
	dib->important_color = 0;
}

void		write_header(int fd, t_bmp_header header, t_dib_header dib)
{
	write(fd, &header.type, 2);
	write(fd, &header.size, 4);
	write(fd, &header.reserved, 4);
	write(fd, &header.offset, 4);
	write(fd, &dib.size, 4);
	write(fd, &dib.width, 4);
	write(fd, &dib.height, 4);
	write(fd, &dib.colplanes, 2);
	write(fd, &dib.bpp, 2);
	write(fd, &dib.compression, 4);
	write(fd, &dib.img_size, 4);
	write(fd, &dib.x_ppm, 4);
	write(fd, &dib.y_ppm, 4);
	write(fd, &dib.color_number, 4);
	write(fd, &dib.important_color, 4);
}

void		write_file(int fd, t_scene data, t_minilibx mlx)
{
	char	*pixel_array;
	int		i;
	int		j;
	int		k;
	int		idx;

	if (!(pixel_array = (char *)malloc(4 * data.xres * data.yres)))
		fatal_error("in malloc");
	k = 0;
	j = -1;
	while (++j < data.yres)
	{
		i = -1;
		while (++i < data.xres)
		{
			idx = j * (mlx.cam->pad + data.xres) + i;
			pixel_array[k++] = mlx.cam->px_img[idx] & 255;
			pixel_array[k++] = (mlx.cam->px_img[idx] & 255 << 8) >> 8;
			pixel_array[k++] = (mlx.cam->px_img[idx] & 255 << 16) >> 16;
			pixel_array[k++] = 0;
		}
	}
	write(fd, pixel_array, 4 * data.xres * data.yres);
	free(pixel_array);
}

void		save_bmp(t_minilibx mlx, t_scene data, char *name)
{
	t_bmp_header	header;
	t_dib_header	dib;
	int				fd;

	fd = create_file(name);
	create_header(data, &header, &dib);
	write_header(fd, header, dib);
	write_file(fd, data, mlx);
	close(fd);
}
