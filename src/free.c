/*
** EPITECH PROJECT, 2018
** free.c
** File description:
** my_world
*/

#include "myworld.h"

void free_map2d(info_map_t *map, sfVector2f **map2d)
{
	for (int i = 0; i < map->lenght; i++)
		free(map2d[i]);
}

void free_map3d(info_map_t *map)
{
	for (int i = 0; i < map->lenght; i++)
		free(map->map3d[i]);
	free(map->map3d);
}
