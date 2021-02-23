#include "minirt.h"

void    scene_to_minirt_window(t_scene *s)
{
    render_scene(s);
}

int     exit_minirt(t_window *win)
{
    printf("Exit seungmki's miniRT!\n");
    mlx_destroy_window(win->mlx_p, win->win_p);
    exit(0);
}

int     key_control(int key, t_scene *s)
{
    if (key == ESC)
        exit_minirt(&s->win);
    else if (key == KEY_A || key == KEY_D || key == KEY_W || key == KEY_S)
        obj_axis_translation(key, s);
    else if (key == ARROW_LEFT || key == ARROW_RIGHT)
        change_camera_with_key(key, s);
    return (0);
}

int     rotate_camera_with_mouse(int click, int x, int y, t_scene *s)
{
    t_vec3 new_n;

    (void)click;//이거 안 하면 컴파일러에 걸리니 그냥 해줌
    new_n = get_local_camera_coord(s, (double)x, (double)y);//마우스 좌표값 기준으로 카메라 중심 좌표 얻음
    new_n = matrix_multiply_vec3(s->camera[s->i_cam]->base, new_n);//카메라 좌표를, 카메라 공간 좌표를 세계 공간 좌표로 바꾸는 행렬(base)과 곱해 세계 좌표로 바꿈
    normalize_vec3(&new_n);
    s->camera[s->i_cam]->n = new_n;//카메라 방향이므로 정규화
    scene_to_minirt_window(s);
    return (0);
}

void    run_minirt(t_scene s)
{
    s.i_cam = s.idx_rec[2] - 1;//제일 처음 파싱한 카메라 쓰기@;
    s.win.win_p = mlx_new_window(s.win.mlx_p, s.x, s.y, "seungmki's miniRT");//mlx 인스턴스 주소 매개변수로 전달
    if (!(s.img.i_adr = mlx_new_image(s.win.mlx_p, s.x, s.y)))//x, y 해상도의 이미지 주소 반환 
		check_error_exit(&s, 7);//0 반환하면 실패한 것
	if (!(s.img.addr = (int*)mlx_get_data_addr(s.img.i_adr,
    s.img.b_pix, s.img.len, s.img.end)))//수정 가능(픽셀 rbg 대입)한 이미지 주소 반환
		check_error_exit(&s, 7);
    mlx_hook(s.win.win_p, KEY_PRESS, 1L << 0, key_control, &s);//KEY_PRESS == 2(KeyPress), 1L<<0(KeyPressMask) 누른 키에 따라 작동
    mlx_hook(s.win.win_p, MOUSE_PRESS, 1L << 0,
    rotate_camera_with_mouse, &s);//MOUSE_PRESS == 4(ButtonPress), 1L<<2(ButtonPressMask) 누른 마우스 버튼에 따라 작동
    mlx_hook(s.win.win_p, EXIT_EVENT, 0L, exit_minirt, &s.win);//EXIT_EVENT == 17(DestroyNotify), 0L(NoEventMask), 창을 끄는 순간 minirt 프로그램도 종료하는 이벤트 처리
    scene_to_minirt_window(&s);
    mlx_loop(s.win.mlx_p);
}