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
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define WIDTH 800
#define HEIGHT 600

#define DEFAULT_ZOOM 24
#define DEFAULT_DELTA 8

typedef struct settings_s {
	int			select_type;
	int			zoom;
	sfVector2f	offset;
}settings_t;

typedef struct pos_s {
	float x;
	float y;
	int selected;
	sfColor color;
}pos_t;

typedef struct tile_s {
	pos_t *topleft;
	pos_t *topright;
	pos_t *botleft;
	pos_t *botright;
}tile_t;

typedef struct map_s {
	float		**map;
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
	settings_t	*settings;
	int			state;
}my_world_t;


//WORLD UI
sfRenderWindow	*create_window(void);
int	set_window_editor_name(sfRenderWindow *wd, char *map_name);
sfVertexArray *create_line(pos_t *pt1, pos_t *pt2);
sfVertexArray *create_tile(tile_t *tile);

char *my_get_str_from_nbr(int nb);

char *my_get_str_from_nbr(int nb);
int	my_get_int_len(int nb);
void save_map(void *ptr);
int load_map(my_world_t *world, char *name);

//MAP DISPS
int	draw_iso_map(sfRenderWindow *wd, my_world_t *world);

//MAP INITS
map_t	*init_map(char *name, int width, int height, float **);
pos_t	**convert_as_iso_map(map_t *map, int zoom, sfVector2f);
tile_t	**convert_as_tile_iso_map(my_world_t *wd);
int	update_iso_map_from_settings(my_world_t *world);

//MAP TOOLS
int	set_map_angle(map_t *map, int angleX, int angleY);
int	set_map_scaling(map_t *map, int scalX, int scalY, int scalZ);
int	point_is_visible(my_world_t *wd, pos_t pos);
int tile_is_visible(my_world_t *wd, tile_t tile);
sfVector2i	get_nearest_camera_point(my_world_t *wd);
sfVector2i	get_increment_factor(sfVector2i begin_pos);

//INITS
scene_t		*init_toolbar_ui(void);
scene_t		*init_map_creator(my_world_t *wld, sfRenderWindow *);
scene_t		*init_map_editor(my_world_t *wld);
settings_t	*init_settings(void);

//EVENTS
void	check_event_map_creator(sfRenderWindow *wd, scene_t *);
void check_event_map_editor(sfRenderWindow *wd, my_world_t *world);

//MAP EVENTS
int	manage_wheel_scroll(sfEvent event, my_world_t *world);
int	manage_selection(sfEvent e, my_world_t *world);
int	manage_move(sfEvent e, my_world_t *world);
int	select_nearest_point(my_world_t *wd, sfVector2f pos);
int	reset_selection(map_t *map);

//UI ACTIONS
void close_window(void *ptr);
void	click_map_create(void *ptr);
void switch_selection(void *ptr);

//FILE TOOLS
int	open_file_or_create_to_write(char *path);
int	open_file_or_create_to_read(char *path);
int	is_extension(char *path, char *ext);
