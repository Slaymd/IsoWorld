/*
** EPITECH PROJECT, 2018
** my_world_2017
** File description:
** wheel scroll
*/

#include "myworld.h"

int	manage_wheel_scroll(sfEvent event, my_world_t *world)
{
	int	oldzoom = world->settings->zoom;

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
