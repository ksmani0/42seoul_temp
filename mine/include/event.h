#ifndef EVENT_H
# define EVENT_H

# define ESC 53
# define KEY_PRESS 2
# define MOUSE_PRESS 4
# define EXIT_EVENT 17

# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_W 13

# define KEY_Z 6
# define KEY_X 7
# define KEY_C 8
# define KEY_V 9

# define ARROW_LEFT 123
# define ARROW_RIGHT 124

/***src - minirt.c***/
int                 exit_minirt(t_window *win);
void                camera_axis_translation(int key, t_scene *s);
int                 key_control(int key, t_scene *s);
int                 rotate_camera_with_mouse(int click, int x, int y, t_scene *s);
void                run_minirt(t_scene s);

/***src - minirt2.c***/
void                update_obj_position(t_scene *s, int i, t_vec3 new);
void                obj_axis_translation(int key, t_scene *s, int i);
void                change_camera_with_key(int key, t_scene *s);

#endif
