/*
** EPITECH PROJECT, 2018
** my_world_boostrap_2017
** File description:
** map gen
*/

#include "myworld.h"


int	**generate_flat_3Dmap(int width, int height)
{
	int **map3d = (int**)malloc(sizeof(int*) * height);

	if (map3d == NULL)
		return (NULL);
	for (int y = 0; y < height; y++) {
		map3d[y] = (int*)malloc(sizeof(int) * width);
		if (map3d[y] == NULL)
			return (NULL);
		for (int x = 0; x < width; x++) {
			map3d[y][x] = 0;
		}
	}
	return (map3d);
}

map_t *init_map(char *name, int width, int height, int **map3D)
{
	map_t *map = (map_t*)malloc(sizeof(*map));

	if (map == NULL)
	return (NULL);
	map->width = width+1;
	map->height = height+1;
	map->scaling = (sfVector3f){2, 2, 2};
	map->angle = (sfVector2f){45, 55};
	map->name = name;
	if (map3D == NULL)
		map->map = generate_flat_3Dmap(map->width, map->height);
	else
		map->map = map3D;
	map->isomap = NULL;
	map->isomap = convert_as_iso_map(map,DEFAULT_ZOOM,(sfVector2f){0,0});
	return (map);
}
