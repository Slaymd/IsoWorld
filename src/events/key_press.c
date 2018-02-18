/*
** EPITECH PROJECT, 2018
** my_world_2017
** File description:
** moving events
*/

/*#include "myworld.h"

void manage_left_key(tools_t *toolbar, info_map_t *map)
{
	if (toolbar->move == 1 && map->coord_map_x >= 220)
		map->coord_map_x -= 5;
}

void manage_right_key(tools_t *toolbar, info_map_t *map)
{
	if (toolbar->move == 1 && map->coord_map_x <= 580)
		map->coord_map_x += 5;
}

void manage_up_key(tools_t *toolbar, info_map_t *map)
{
	if (toolbar->zoom == 1 && map->scaling_x < 700 && map->scaling_y < 700 && map->scaling_z < 700) {
		map->scaling_x += 2;
		map->scaling_y += 2;
		map->scaling_z += 2;
	}
	if (toolbar->rotate == 1 && map->angle_y <= 35)
		map->angle_y += 5;
}

void manage_down_key(tools_t *toolbar, info_map_t *map)
{
	if (toolbar->zoom == 1 && map->scaling_x > 10 && map->scaling_y > 10 && map->scaling_z > 10) {
		map->scaling_x -= 2;
		map->scaling_y -= 2;
		map->scaling_z -= 2;
	}
	if (toolbar->rotate == 1 && map->angle_y > 0)
		map->angle_y -= 5;
}

void check_keys(sfEvent event, tools_t *toolbar, info_map_t *map)
{
	switch (event.key.code) {
		case sfKeyLeft :
			manage_left_key(toolbar, map);
			break;
		case sfKeyRight :
			manage_right_key(toolbar, map);
			break;
		case sfKeyUp :
			manage_up_key(toolbar, map);
			break;
		case sfKeyDown :
			manage_down_key(toolbar, map);
			break;
		default :
			break;
	}
}*/
