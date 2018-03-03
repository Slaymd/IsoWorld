/*
** EPITECH PROJECT, 2018
** my_world_2017
** File description:
** map selections tools
*/

#include "myworld.h"

int	select_nearest_tile(my_world_t *wd, sfVector2i fpos)
{
	pos_t *botright = &wd->map->isomap[fpos.y][fpos.x];
	pos_t *botleft = &wd->map->isomap[fpos.y][fpos.x-1];
	pos_t *topright = &wd->map->isomap[fpos.y-1][fpos.x];
	pos_t *topleft = &wd->map->isomap[fpos.y-1][fpos.x-1];

	if (botright->selected == 0 && botright->selected == 0 &&
	topright->selected == 0 && topleft->selected == 0) {
		botright->selected = 1;
		topright->selected = 1;
		botleft->selected = 1;
		topleft->selected = 1;
	} else {
		botright->selected = 0;
		topright->selected = 0;
		botleft->selected = 0;
		topleft->selected = 0;
	}
	return (0);
}

int	select_point_ifnear(my_world_t *wd, sfVector2f pos, sfVector2i fpos)
{
	pos_t *pt = &wd->map->isomap[fpos.y][fpos.x];
	int	distance = sqrt(pow(pt->x-pos.x, 2)+pow(pt->y-pos.y, 2));
	int	sett = wd->settings->select_type;
	int	dlt = sett == 2 ? wd->map->scaling.x*wd->settings->zoom : 0;

	if (distance <= (dlt == 0 ? DEFAULT_DELTA : dlt)) {
		if (sett == 0)
			reset_selection(wd->map);
		if (sett == 2) {
			select_nearest_tile(wd, fpos);
		} else {
			pt->selected = pt->selected == 1 ? 0 : 1;
		}
		return (1);
	}
	return (0);
}

int	select_nearest_point(my_world_t *wd, sfVector2f pos)
{
	int rtn = 0;
	sfVector2i	fpos = {.x = 0, .y = 0};
	map_t	*map = wd->map;

	pos = (sfVector2f){pos.x + 5, pos.y + 5};
	for (int y = map->height-1; y >= 0 && rtn == 0; y--) {
		for (int x = map->width-1; x >= 0 && rtn == 0; x--) {
			fpos = (sfVector2i){x, y};
			rtn = select_point_ifnear(wd, pos, fpos);
		}
	}
	return (rtn);
}

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
