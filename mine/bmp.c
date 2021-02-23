#include "minirt.h"

void	write_bmp_header(t_scene *s, int fd)
{
	t_bmp_h b_h;

	printf("Image saving starts!");
	ft_bzero(&b_h, sizeof(t_bmp_h));
	b_h.file.type_1 = 'B';
	b_h.file.type_2 = 'M';
	b_h.file.size = 54 + (4 * s->x * s->y);//파일 크기
	b_h.file.reserved_1 = 0;
	b_h.file.reserved_2 = 0;
	b_h.file.offset = 54;//파일 시작부터 비트맵 데이터까지의 오프셋
	b_h.info.size = 40;//info 헤더 크기
	b_h.info.x = s->x;
	b_h.info.y = -(s->y);//음수면 이미지 상하 반전
	b_h.info.plane = 1;
	b_h.info.bit_cnt = 32;//픽셀당 비트 수
	b_h.info.compr = 0;
	b_h.info.img_size = 4 * s->x * s->y;
	b_h.info.meter_x = s->x;
	b_h.info.meter_y = s->y;
	b_h.info.clr_used = 0xffffff;//rgb니까
	b_h.info.clr_imprt = 0;
	write(fd, &b_h, 54);
}

void	write_bmp_image(t_scene *s, int fd)
{
	int		i;
	int		j;
	int		count;
	char	*s;

	s = "000";//4바이트 안 될 때 패팅 채우는 역할
	count = (4 - (s->x * 3) % 4) % 4;
	i = s->y;
	while (i > 0)//해상도 돌면서 파일에 이미지 저장
	{
		i--;
		j = 0;
		while (j < s->x)
		{
			write(fd, &s->img.addr[i * s->x + j], 3);
			j++;
		}
		if (count > 0)//패딩할 게 있다면? 여기서 0 넣어줌
			write(fd, s, count);
	}
}

void	save_bmp(t_scene *s, int fd)
{
	if (!(s->img.i_adr = mlx_new_image(s->win.mlx_p, s->x, s->y)))//x, y 해상도의 이미지 주소 반환 
		check_error_exit(s, 7);//0 반환하면 실패한 것
	if (!(s->img.addr = (int*)mlx_get_data_addr(s->img.i_adr,
	s->img.b_pix, s->img.len, s->img.end)))//수정 가능(픽셀 rbg 대입)한 이미지 주소 반환
		check_error_exit(s, 7);
	if ((fd = open("output/bmp.c", O_CREAT | O_WRONLY | O_TRUNC,
		0755)) == -1)
		check_error_exit(s, 8);
	s->i_cam = s->idx_rec[2] - 1;//제일 처음 파싱한 카메라 쓰기@
	render_scene(s);//도형 그리고 s->img에 그림
	write_bmp_header(s, fd);//저장할 파일에 bmp 헤더부터 씀
	write_bmp_image(s, fd);//저장할 파일에 렌더링으로 확보한 이미지 버퍼 내용 씀
	close(fd);
	printf("Image saving is complete!");
}
