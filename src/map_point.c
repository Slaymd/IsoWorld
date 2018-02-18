/*
** EPITECH PROJECT, 2018
** my_world_2017
** File description:
** map point
*/

#include "myworld.h"

int	select_point_if_near(pos_t *point, sfVector2f pos, int delta)
{
	int	distance = sqrt(pow(point->x-pos.x, 2)+pow(point->y-pos.y, 2));

	if (distance <= delta) {
		point->selected = point->selected == 1 ? 0 : 1;
		return (1);
	}
	return (0);
}

int	select_nearest_point(map_t *map, sfVector2f pos, int delta)
{
	int rtn = 0;

	for (int y = map->height-1; y >= 0 && rtn == 0; y--) {
		for (int x = map->width-1; x >= 0 && rtn == 0; x--) {
			rtn = select_point_if_near(&map->isomap[y][x], pos, delta);
		}
	}
	return (rtn);
}
