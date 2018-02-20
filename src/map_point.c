/*
** EPITECH PROJECT, 2018
** my_world_2017
** File description:
** map point
*/

#include "myworld.h"

int	select_point_ifnear(my_world_t *wd, pos_t *pt, sfVector2f pos, int dlt)
{
	int	distance = sqrt(pow(pt->x-pos.x, 2)+pow(pt->y-pos.y, 2));
	int	oldsel = pt->selected;

	if (distance <= dlt) {
		if (wd->settings->select_type)
			reset_selection(wd->map);
		pt->selected = oldsel == 1 ? 0 : 1;
		return (1);
	}
	return (0);
}

int	select_nearest_point(my_world_t *wd, sfVector2f pos, int dlt)
{
	int rtn = 0;
	map_t	*map = wd->map;

	for (int y = map->height-1; y >= 0 && rtn == 0; y--) {
		for (int x = map->width-1; x >= 0 && rtn == 0; x--) {
			rtn = select_point_ifnear(wd, &map->isomap[y][x], pos, dlt);
		}
	}
	return (rtn);
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
