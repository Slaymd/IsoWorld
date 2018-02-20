/*
** EPITECH PROJECT, 2018
** my_world_2017
** File description:
** wheel scroll
*/

#include "myworld.h"

/*void manage_up_key(map_t *map)
{
	sfVector3f	scal = map->scaling;

	if (scal.x < 400 && scal.y < 400 && scal.z < 400)
		set_map_scaling(map, scal.x+2, scal.y+2, scal.z+2);
	if (toolbar->rotate == 1 && map->angle_y <= 35)
		map->angle_y += 5;
}

void manage_down_key(map_t *map)
{
	sfVector3f	scal = map->scaling;

	if (scal.x > 40 && scal.y > 40 && scal.z > 40)
		set_map_scaling(map, scal.x-2, scal.y-2, scal.z-2);
	if (toolbar->rotate == 1 && map->angle_y > 0)
		map->angle_y -= 5;
}*/

int	manage_wheel_scroll(sfEvent event, my_world_t *world)
{
	int		oldzoom = world->settings->zoom;

	if (event.mouseWheel.x < 0) {
		if (oldzoom > 5)
			world->settings->zoom--;
	} else if (event.mouseWheel.x > 0) {
		if (oldzoom < 50)
			world->settings->zoom++;
	}
	if (world->settings->zoom != oldzoom)
		update_iso_map_from_settings(world);
	return (0);
}
