/*
** EPITECH PROJECT, 2017
** my_world_2017
** File description:
** map disp angle
*/

#include "myworld.h"

int	draw_iso_tile(sfRenderWindow *wd, tile_t tile);

void draw_iso_map_angle1(sfRenderWindow *wd, map_t *map, tile_t tile)
{
	for (int x = map->width-2, y = 0; y < map->height-1; x--) {
		if (x == -1) {
			x = map->width-2;
			y++;
		}
		if (y == map->height-1)
			break;
		tile.topleft = &map->isomap[y][x+1];
		tile.topright = &map->isomap[y][x];
		tile.botleft = &map->isomap[y+1][x+1];
		tile.botright = &map->isomap[y+1][x];
		draw_iso_tile(wd, tile);
	}
}

void draw_iso_map_angle2(sfRenderWindow *wd, map_t *map, tile_t tile)
{
	int y = map->height-2;

	for (int x = map->width-2; map->angle.x < 360; x--) {
		if (x == -1) {
			x = map->width-2;
			y--;
		}
		if (y == -1)
			break;
		tile.topleft = &map->isomap[y+1][x+1];
		tile.topright = &map->isomap[y+1][x];
		tile.botleft = &map->isomap[y][x+1];
		tile.botright = &map->isomap[y][x];
		draw_iso_tile(wd, tile);
	}
}

void draw_iso_map_angle3(sfRenderWindow *wd, map_t *map, tile_t tile)
{
	for (int x = 0, y = map->height-2; map->angle.x < 360; x++) {
		if (x == map->width-1) {
			x = 0;
			y--;
		}
		if (y == -1)
			break;
		tile.topleft = &map->isomap[y+1][x];
		tile.topright = &map->isomap[y][x];
		tile.botleft = &map->isomap[y+1][x+1];
		tile.botright = &map->isomap[y][x+1];
		draw_iso_tile(wd, tile);
	}
}
void draw_iso_map_angle4(sfRenderWindow *wd, map_t *map, tile_t tile)
{
	for (int x = 0, y = 0; y < map->height-1; x++) {
		if (x == map->width-1) {
			x = 0;
			y++;
		}
		if (y == map->height-1)
			break;
		tile.topleft = &map->isomap[y][x];
		tile.topright = &map->isomap[y][x+1];
		tile.botleft = &map->isomap[y+1][x];
		tile.botright = &map->isomap[y+1][x+1];
		draw_iso_tile(wd, tile);
	}
}
