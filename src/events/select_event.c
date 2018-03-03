/*
** EPITECH PROJECT, 2018
** my_world_2017
** File description:
** select on map event
*/

#include "myworld.h"

int	edit_altitude(map_t *map, int keyUp, int keyDown)
{
	int nbch = 0;

	for (int x = 0, y = 0; y < map->height && (keyUp || keyDown); x++) {
		if (x == map->width) {
			x = 0;
			y++;
		}
		if (y == map->height)
			break;
		if (map->isomap[y][x].selected) {
			map->map[y][x] += keyUp ? 0.1 : (keyDown ? -0.1 : 0);
			nbch++;
		}
	}
	if (nbch != 0)
		return (1);
	return (0);
}

int	manage_edit_selection(sfEvent e, my_world_t *world)
{
	static int	keyUp = 0;
	static int	keyDown = 0;

	if (e.key.code == sfKeyUp) {
		keyDown = 0;
		keyUp = e.type == sfEvtKeyPressed ? 1 : 0;
	} if (e.key.code == sfKeyDown) {
		keyUp = 0;
		keyDown = e.type == sfEvtKeyPressed ? 1 : 0;
	}
	if (edit_altitude(world->map,keyUp,keyDown)) {
		update_iso_map_from_settings(world);
		return (1);
	}
	return (0);
}

int	manage_selection(sfEvent e, my_world_t *world)
{
	sfVector2f	pos = (sfVector2f){0, 0};

	if (e.type == sfEvtMouseButtonPressed) {
		pos = (sfVector2f){e.mouseButton.x, e.mouseButton.y};
		select_nearest_point(world, pos);
	} else if (e.type == sfEvtKeyPressed || e.type == sfEvtKeyReleased)
		return (manage_edit_selection(e, world));
	return (0);
}
