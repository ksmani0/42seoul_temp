#ifndef SCENE_H
# define SCENE_H

typedef union		u_dble
{
	double			value;
	struct
	{
		size_t		m : 52;
		size_t		e : 11;
		size_t		s : 1;
	}				s_int;
}					t_dble;

/*
**size:54 + 4 * x * y | reserved_1 ~_2:0 | offset:54
*/
typedef struct		s_bmp_fh
{
	t_uchar			type_1;//'B'
	t_uchar			type_2;//'M'
	t_uint			size;
	t_usint			reserved_1;
	t_usint			reserved_2;
	t_uint			offset;
}					t_bmp_fh;

/*
**size:40 | y:image is reversed when negative | plane:1
**bit_cnt:bit per pixel, 32 | compr:compression, 0
**img_size:4 * x * y | meter_x:x | meter_y:y
**clr_used:color used, 0xffffff | clr_imprt:0
*/
typedef struct		s_bmp_ih
{
	t_uint			size;
	int				x;
	int				y;
	t_usint			plane;
	t_usint			bit_cnt;
	t_uint			compr;
	t_uint			img_size;
	t_uint			meter_x;
	t_uint			meter_y;
	t_uint			clr_used;
	t_uint			clr_imprt;
}					t_bmp_ih;

typedef struct		s_bmp_h
{
	t_bmp_fh		file;
	t_bmp_ih		info;
}					t_bmp_h;

/*
**addr:해상도 크기만한 이미지 정보(버퍼로 봐도 될 듯) 주소 받음. 여기에 색상 입힘 
**id:image instance address | b_pix:bit_pixel | alias:aliasing
*/
typedef struct		s_image
{
	void			*inst;
	int				*addr;
	char			*alias;
	int				len;
	int				b_pix;
	int				end;
}					t_image;

/*
**idx:scene index == idx_rec(records)
**0:scene resolution | 1:ambient | 2:camera | 3:light
**4:sphere | 5:plane | 6:square
**7:cylinder | 8:triangle
**
**x:width | y:height
**filter:0 or 's' or 'r' of 'g' or 'b' when A has 'sepia, red, green, blue'
*/
typedef struct		s_scene
{
	char			idx[9];
	char			idx_rec[9];
	int				x;
	int				y;
	char			filter;
	short			i_cam;
	short			i_light;
	t_axis			axis;
	t_window		win;
	t_image			img;
	t_ambient		ambient;
	t_camera		**camera;
	t_light			**light;
	t_sphere		**sphere;
	t_plane			**plane;
	t_square		**square;
	t_cylinder		**cylinder;
	t_triangle		**triangle;
} t_scene;

#endif