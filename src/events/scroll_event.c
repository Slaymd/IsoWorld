/*
** EPITECH PROJECT, 2018
** my_world_2017
** File description:
** wheel scroll
*/

#include "myworld.h"

void manage_up_key(map_t *map)
{
	sfVector3f	scal = map->scaling;

	if (scal.x < 700 && scal.y < 700 && scal.z < 700)
		set_map_scaling(map, scal.x+2, scal.y+2, scal.z+2);
	/*if (toolbar->rotate == 1 && map->angle_y <= 35)
		map->angle_y += 5;*/
}

void manage_down_key(map_t *map)
{
	sfVector3f	scal = map->scaling;

	if (scal.x > 10 && scal.y > 10 && scal.z > 10)
		set_map_scaling(map, scal.x-2, scal.y-2, scal.z-2);
	/*if (toolbar->rotate == 1 && map->angle_y > 0)
		map->angle_y -= 5;*/
}

int	manage_wheel_scroll(sfEvent event, my_world_t *world)
{
	if (event.mouseWheel.x < 0) {
		manage_down_key(world->map);
	} else if (event.mouseWheel.x > 0) {
		manage_up_key(world->map);
	}
	return (0);
}
