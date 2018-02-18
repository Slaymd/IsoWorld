/*
** EPITECH PROJECT, 2018
** my_world_boostrap_2017
** File description:
** my world
*/

#include "locales.h"
#include "my_uilib.h"
#include "my.h"
#include <SFML/Graphics.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define WIDTH 800
#define HEIGHT 600

/*typedef struct tools_s {
	int		move;
	int		zoom;
	int		rotate;
	int		select_corner;
	int		select_tile;
} tools_t;*/

/*typedef struct info_map_s {
int **map3d;
int lenght;
int width;
int scaling_x;
int scaling_y;
int scaling_z;
int angle_x;
int angle_y;
int coord_map_x;
int coord_map_y;
} info_map_t;*/

typedef struct pos_s {
	int x;
	int y;
	int selected;
}pos_t;

typedef struct map_s {
	int			**map;
	pos_t		**isomap;
	int			width;
	int			height;
	sfVector3f	scaling;
	sfVector2f	angle;
	char			*name;
}map_t;


typedef struct my_world_s {
	sfRenderWindow	*wd;
	scene_t		*actual_scene;
	map_t		*map;
	int			state;
}my_world_t;


//WORLD UI
sfRenderWindow	*create_window();
int	set_window_editor_name(sfRenderWindow *wd, char *map_name);
sfVertexArray *create_line(pos_t *pt1, pos_t *pt2);

char *my_get_str_from_nbr(int nb);

/*void free_map2d(info_map_t *map, sfVector2f **map2d);
void free_map3d(info_map_t *map);
int save_map(info_map_t *map);*/
char *my_get_str_from_nbr(int nb);
int	my_get_int_len(int nb);
/*void resize_map(info_map_t *map, int lenght, int width);
void load_map(info_map_t *map);*/

//MAP DISPS
int draw_iso_map(sfRenderWindow *wd, map_t *map);

//MAP INITS
map_t	*init_map(char *name, int wid, int hei, int **map3D);
pos_t	**convert_as_iso_map(map_t *map);

//MAP TOOLS
int	set_map_angle(map_t *map, int angleX, int angleY);
int	set_map_scaling(map_t *map, int scalX, int scalY, int scalZ);

//INITS
scene_t	*init_toolbar_ui(void);
scene_t	*init_map_creator(my_world_t *world, sfRenderWindow *wd);
scene_t	*init_map_editor(void);

//EVENTS
void	check_event_map_creator(sfRenderWindow *wd, scene_t *map_creator);
void check_event_map_editor(sfRenderWindow *wd, my_world_t *world);

//MAP EVENTS
int	manage_wheel_scroll(sfEvent event, my_world_t *world);
int	manage_selection(sfEvent e, my_world_t *world);
int	select_nearest_point(map_t *map, sfVector2f pos, int delta);

/*void manage_up_key(tools_t *toolbar, info_map_t *map);
void manage_down_key(tools_t *toolbar, info_map_t *map);*/

//UI ACTIONS
void close_window(void *ptr);
void	click_map_create(void *ptr);
