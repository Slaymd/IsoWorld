/*
** EPITECH PROJECT, 2018
** my_world_2017
** File description:
** map selections tools
*/

#include "myworld.h"

int	reset_selection(map_t *map)
{
	for (int x = 0, y = 0; y < map->height; x++) {
		if (x == map->width) {
			x = 0;
			y++;
		}
		if (y == map->height)
			break;
		map->isomap[y][x].selected = 0;
	}
	return (0);
}
