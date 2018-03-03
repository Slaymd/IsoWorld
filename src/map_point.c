/*
** EPITECH PROJECT, 2018
** my_world_2017
** File description:
** map point
*/

#include "myworld.h"

sfVector2i	get_nearest_camera_point(my_world_t *wd)
{
	sfVector2i	nearest_coords = {.x = 0, .y = 0};
	pos_t		*_nearest = &wd->map->isomap[0][0];
	pos_t		*_tmp = NULL;

	for (int x = 0, y = 0; y < wd->map->height; x++) {
		if (x == wd->map->width) {
			x = 0;
			y++;
		}
		if (y == wd->map->height)
			break;
		_tmp = &wd->map->isomap[y][x];
		if (_tmp->y > _nearest->y) {
			_nearest = _tmp;
			nearest_coords = (sfVector2i){x, y};
		}
	}
	return (nearest_coords);
}

int	point_is_visible(my_world_t *wd, pos_t pos)
{
	if (pos.x < 0-(wd->map->scaling.x*wd->settings->zoom))
		return (0);
	else if (pos.x > WIDTH+(wd->map->scaling.x*wd->settings->zoom))
		return (0);
	if (pos.y < 0-(wd->map->scaling.y*wd->settings->zoom))
		return (0);
	else if (pos.y > HEIGHT+(wd->map->scaling.y*wd->settings->zoom))
		return (0);
	return (1);
}

int tile_is_visible(my_world_t *wd, tile_t tile)
{
	int a = point_is_visible(wd, *tile.topleft);
	int b = point_is_visible(wd, *tile.topleft);
	int c = point_is_visible(wd, *tile.topleft);
	int d = point_is_visible(wd, *tile.topleft);

	if (a || b || c || d)
		return (1);
	return (0);
}
