#include "minirt.h"

void	write_bmp_header(t_scene *s, int fd, int file_size)
{
	t_uchar	bmp_h[54];
	int		minus_y;

	ft_bzero(bmp_h, 54);//(4 - (s->x * 3) % 4) % 4?
	file_size = 4 * s->y * s->x + 54;//해상도 크기만큼 4바이트(픽셀 당 바이트) 곱하고 헤더 더하면 파일 크기
	minus_y = -1 * s->y;
	bmp_h[0] = 'B';
	bmp_h[1] = 'M';
	bmp_h[2] = (t_uchar)file_size;
	bmp_h[3] = (t_uchar)(file_size >> 8);
	bmp_h[4] = (t_uchar)(file_size >> 16);
	bmp_h[5] = (t_uchar)(file_size >> 24);
	bmp_h[10] = 54;//file header + info header 크기이자 오프셋
	bmp_h[14] = 40;//info header size
	bmp_h[18] = (t_uchar)s->x;//내가 받은 가로 길이로 적용
	bmp_h[19] = (t_uchar)(s->x >> 8);
	bmp_h[20] = (t_uchar)(s->x >> 16);
	bmp_h[21] = (t_uchar)(s->x >> 24);
	bmp_h[22] = (t_uchar)minus_y;
	bmp_h[23] = (t_uchar)(minus_y >> 8);
	bmp_h[24] = (t_uchar)(minus_y >> 16);
	bmp_h[25] = (t_uchar)(minus_y >> 24);
	bmp_h[26] = 1;
	bmp_h[28] = 32;//bits per pixel
	write(fd, bmp_h, 54);
}

void	write_bmp_image(t_scene *s, int fd)
{//in render_scene, s->img.addr + (pix_y * s->img.len + pix_x * (s->img.b_pix / 8));
	int i;

	i = 0;
	while (i < (s->img.len / 4) * s->y)
	{//64 배수의 이미지, 64 배수가 아닌 이미지 모두 왜곡 없이 처리하는 로직
		if (i % (s->img.len / 4) < s->x)//딱 x만큼 데이터 저장
			write(fd, &s->img.addr[i * 4], 4);//1픽셀당 4바이트의 색상 정보를 가짐
		++i;
	}
}

void	save_bmp(t_scene s, int fd)
{
	if (!(s.img.inst = mlx_new_image(s.win.mlx_p, s.x, s.y)))//x, y 해상도의 이미지 주소 반환 
		check_error_exit(&s, 7);//0 반환하면 실패한 것
	if (!(s.img.addr = mlx_get_data_addr(s.img.inst,
	&s.img.b_pix, &s.img.len, &s.img.end)))//수정 가능(픽셀 rbg 대입)한 이미지 주소 반환, (int*) 삭제
		check_error_exit(&s, 7);
	if ((fd = open("output_bmp/result.bmp", O_CREAT | O_WRONLY | O_TRUNC,
		0744)) == -1)
		check_error_exit(&s, 8);
	s.i_cam = s.idx_rec[2] - 1;//제일 처음 파싱한 카메라 s->idx_rec[2] - 1에서 [0] 쓰기@
	render_scene(&s);//도형 그리고 s->img에 그림
	printf("Image saving starts!\n");
	write_bmp_header(&s, fd, 0);//저장할 파일에 bmp 헤더부터 씀
	write_bmp_image(&s, fd);//저장할 파일에 렌더링으로 확보한 이미지 버퍼 내용 씀
	close(fd);
	printf("Image saving is complete! Please Check the output_bmp folder:)\n");
}
