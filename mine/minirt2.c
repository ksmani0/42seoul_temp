#include "minirt.h"

void    obj_axis_translation(int key, t_scene *s)
{
    if (key == KEY_A || key == KEY_D || key == KEY_W || key == KEY_S)
        //
    else if ()
        //
    else if ()
        //
}

void    change_camera_with_key(int key, t_scene *s)
{
    if (key == ARROW_LEFT)
    {//초반에 파싱한 카메라로 이동
        if (s->i_cam > 0)
            s->i_cam--;
    }
    else if (key == ARROW_RIGHT)
    {//후반에 파싱한 카메라로 이동
        if (s->i_cam < s->idx_rec[2] - 1)
            s->i_cam++;
    }
}

/*
else if (key == ARROW_LEFT || key == ARROW_RIGHT)
        change_camera_with_key(key, s);
*/