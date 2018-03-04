/*
** EPITECH PROJECT, 2018
** my_world_boostrap_2017
** File description:
** map disp
*/

#include "myworld.h"

void draw_iso_map_angle1(sfRenderWindow *, map_t *map, tile_t);
void draw_iso_map_angle2(sfRenderWindow *, map_t *map, tile_t);
void draw_iso_map_angle3(sfRenderWindow *, map_t *map, tile_t);
void draw_iso_map_angle4(sfRenderWindow *, map_t *map, tile_t);

int	draw_selection(sfRenderWindow *wd, pos_t *pos)
{
	sfCircleShape	*circ = NULL;

	if (pos->selected == 1) {
		circ = sfCircleShape_create();
		sfCircleShape_setPointCount(circ, 10);
		sfCircleShape_setPosition(circ,(sfVector2f){pos->x-6,pos->y-6});
		sfCircleShape_setRadius(circ, 6);
		sfCircleShape_setFillColor(circ, (sfColor){255,159,243,255});
		sfRenderWindow_drawCircleShape(wd, circ, NULL);
		return (1);
	}
	return (0);
}

int	draw_iso_tile(sfRenderWindow *wd, tile_t tile)
{
	pos_t *tilepos[] = {tile.topleft, tile.topright,
		tile.botright, tile.botleft, tile.topleft};
	sfVertexArray	*line = NULL;

	sfRenderWindow_drawVertexArray(wd, create_tile(&tile), NULL);
	for (int i = 0; i < 4; i++) {
		line = create_line(tilepos[i], tilepos[i+1]);
		sfRenderWindow_drawVertexArray(wd, line, NULL);
		draw_selection(wd, tilepos[i]);
	}

	return (0);
}

int	draw_iso_map(sfRenderWindow *wd, my_world_t *world)
{
	map_t *map = world->map;
	tile_t tile = (tile_t){0, 0, 0, 0};

	if (map->angle.x < 90) {
		draw_iso_map_angle1(wd, map, tile);
	} else if (map->angle.x < 180) {
		draw_iso_map_angle2(wd, map, tile);
	} else if (map->angle.x < 270) {
		draw_iso_map_angle3(wd, map, tile);
	} else {
		draw_iso_map_angle4(wd, map, tile);
	}
	return (0);
}
