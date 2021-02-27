#include "minirt.h"

int     exit_minirt(t_window *win)
{
    printf("Exit seungmki's miniRT!\n");
    mlx_destroy_window(win->mlx_p, win->win_p);
    exit(0);
}

void    camera_axis_translation(int key, t_scene *s)
{
    t_vec3 new_pos;

    if (key == KEY_A)//move left
        new_pos = (t_vec3){ -1, 0, 0 };
    else if (key == KEY_D)//move right
        new_pos = (t_vec3){ 1, 0, 0 };
    else if (key == KEY_W)//move up
        new_pos = (t_vec3){ 0, 1, 0 };
    else if (key == KEY_S)//move down
        new_pos = (t_vec3){ 0, -1, 0 };
    new_pos = matrix_multiply_vec3(s->camera[s->i_cam]->base, new_pos);
    s->camera[s->i_cam]->pos = vec3_add_vec3(s->camera[s->i_cam]->pos, new_pos);//조정한 카메라 좌표로 갱신
    render_scene(&s);//여기서 이벤트 내용 적용해서 다시 이미지 렌더링
    mlx_put_image_to_window(s->win.mlx_p, s->win.win_p, s->img.inst, 0, 0);//이미지 정보를 모았다가 한번에 그림. 새로운 mlx 호환 이미지를 생성
}

int     key_control(int key, t_scene *s)
{
    if (key == ESC)
        exit_minirt(&s->win);
    else if (key == KEY_A || key == KEY_D || key == KEY_W || key == KEY_S)
        camera_axis_translation(key, s);
    else if (key == KEY_Z || key == KEY_X || key == KEY_C || key == KEY_V)
        obj_axis_translation(key, s, 4);//4부터 도형들
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
    render_scene(&s);//여기서 이벤트 내용 적용해서 다시 이미지 렌더링
    mlx_put_image_to_window(s->win.mlx_p, s->win.win_p, s->img.inst, 0, 0);//이미지 정보를 모았다가 한번에 그림. 새로운 mlx 호환 이미지를 생성
    return (0);
}

void    run_minirt(t_scene s)
{
    s.i_cam = s.idx_rec[2] - 1;//제일 처음 파싱한 카메라 쓰기@
    s.win.win_p = mlx_new_window(s.win.mlx_p, s.x, s.y, "seungmki's miniRT");//mlx 인스턴스 주소 매개변수로 전달
    if (!(s.img.inst = mlx_new_image(s.win.mlx_p, s.x, s.y)))//x, y 해상도의 이미지 주소(이미지 인스턴스) 반환
		check_error_exit(&s, 7);//0 반환하면 실패한 것
	if (!(s.img.addr = (int*)mlx_get_data_addr(s.img.inst,
    s.img.b_pix, s.img.len, s.img.end)))//수정 가능(픽셀 rbg 대입)한 이미지 주소 반환
		check_error_exit(&s, 7);
    mlx_hook(s.win.win_p, KEY_PRESS, 1L << 0, key_control, &s);//KEY_PRESS == 2(KeyPress), 1L<<0(KeyPressMask) 누른 키에 따라 작동
    mlx_hook(s.win.win_p, MOUSE_PRESS, 1L << 0,
    rotate_camera_with_mouse, &s);//MOUSE_PRESS == 4(ButtonPress), 1L<<2(ButtonPressMask) 누른 마우스 버튼에 따라 작동
    mlx_hook(s.win.win_p, EXIT_EVENT, 0L, exit_minirt, &s.win);//EXIT_EVENT == 17(DestroyNotify), 0L(NoEventMask), 창을 끄는 순간 minirt 프로그램도 종료하는 이벤트 처리
    render_scene(&s);//여기서 이벤트 내용 적용해서 다시 이미지 렌더링
    mlx_put_image_to_window(s.win.mlx_p, s.win.win_p, s.img.inst, 0, 0);//이미지 정보를 모았다가 한번에 그림. 새로운 mlx 호환 이미지를 생성
    mlx_loop(s.win.mlx_p);
}
