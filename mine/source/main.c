#include "minirt.h"

char	s_now_obj = 0;//구나 원통 함수를 거칠 땐 's' 또는 'c' 대입

void	free_each_obj(t_scene *s, int i)
{
	while (i <= s->idx_rec[2])
		free(s->camera[i++]);
	i = 0;
	while (i <= s->idx_rec[3])
		free(s->light[i++]);
	i = 0;
	while (i <= s->idx_rec[4])
		free(s->sphere[i++]);
	i = 0;
	while (i <= s->idx_rec[5])
		free(s->plane[i++]);
	i = 0;
	while (i <= s->idx_rec[6])
		free(s->square[i++]);
	i = 0;
	while (i <= s->idx_rec[7])
		free(s->cylinder[i++]);
	i = 0;
	while (i <= s->idx_rec[8])
		free(s->triangle[i++]);
}

void	free_scene(t_scene *s)
{
	free(s->camera);
	free(s->light);
	free(s->sphere);
	free(s->plane);
	free(s->square);
	free(s->cylinder);
	free(s->triangle);
}

void	check_error_exit(t_scene *scene, int error)
{
	if (error == 1)
		printf("Error\n:wrong file entered!");
	else if (error == 2)
		printf("Error\n:the second argument is wrong!");
	else if (error == 3)
		printf("Error\n:while reaing 'minirt_guide.txt' file!");
	else if (error == 4)
		printf("Error\n:while reading '.rt' file!");
	else if (error == 5 || error == 9)
		printf("Error\n:the '.rt' file format is incorrect!");
	else if (error == 6)
		printf("Error\n:while allocating memory!");
	else if (error == 7)
		printf("Error\n:function in mlx.h has failed!!");
	else if (error == 8)
		printf("Error\n:while openig bmp file!");
	if (error == 6 || error == 8 || error == 9)
	{
		free_each_obj(scene, 0);
		free_scene(scene);
	}
	exit(1);
}

void	guide_output(t_scene *scene)
{
	int		fd;
	char	*line;
	int		ret;

	fd = open("minirt_guide.txt", O_RDONLY);//프로그램의 전체적 구조, key별 기능, 내가 완료한 보너스 내용
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		printf("%s\n", line);
		free(line);
	}
	printf("%s\n", line);
	free(line);
	close(fd);
	if (ret == -1)
		check_error_exit(scene, 3);
}

int		main(int ac, char **av)
{
	t_scene	scene;
	char	*tmp;

	ft_bzero(&scene, sizeof(t_scene));
	if (ac == 2 || ac == 3)
	{
		if ((tmp = ft_strstr(av[1], ".rt")) == 0 || *(tmp + 3) != 0)
			check_error_exit(&scene, 1);
		if (ac == 3 && (ft_strcmp(av[2], "--save")) != 0)
			check_error_exit(&scene, 2);
		guide_output(&scene);
		scene.win.mlx_p = mlx_init();//그래픽 시스템에 연결시키고 mlx 인스턴스 주소 반환
		read_rt(av[1], &scene);//.rt 파일 읽어 scene에 저장
		resize_resolution(&scene);//너무 큰 해상도 x, y 들어오면 여기서 안전한 범위로 수정
		ac == 3 ? save_bmp(scene, 0) : run_minirt(scene);//ing
		//화면에 출력, 이벤트 hook 하는 mlx 함수 등 필요
	}
	else
		printf("Error\n:no arguments entered!");
	return (0);
}
