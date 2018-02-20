/*
** EPITECH PROJECT, 2018
** my_world_2017
** File description:
** move event
*/

#include "myworld.h"

int	edit_angle(my_world_t *world, sfVector2f offset)
{
	int newangleY = world->map->angle.y + offset.y;

	world->map->angle.x += offset.x;
	if (newangleY > 2 && newangleY < 75)
		world->map->angle.y += offset.y;
	update_iso_map_from_settings(world);
	return (0);
}

int	edit_offset(my_world_t *world, sfVector2f offset)
{
	int	offsetX = world->settings->offset.x+offset.x;
	int	offsetY = world->settings->offset.y+offset.y;

	//if (offsetX > 0 && offsetX < world->map->width)
	world->settings->offset.x = offsetX;
	//if (offsetY > 0 && offsetY < world->map->height)
	world->settings->offset.y = offsetY;
	update_iso_map_from_settings(world);
	return (0);
}

int	manage_angle_move(sfKeyCode key, my_world_t *world)
{
	switch (key) {
	case sfKeyUp:
		edit_angle(world, (sfVector2f){0, 2});
		return (1);
	case sfKeyDown:
		edit_angle(world, (sfVector2f){0, -2});
		return (1);
	case sfKeyLeft:
		edit_angle(world, (sfVector2f){-2, 0});
		return (1);
	case sfKeyRight:
		edit_angle(world, (sfVector2f){2, 0});
		return (1);
	default:
		return (0);
	}
	return (0);
}

int	manage_offset_move(sfKeyCode key, my_world_t *world)
{
	switch(key) {
	case sfKeyQ:
		edit_offset(world, (sfVector2f){-1, 0});
		return (1);
	case sfKeyD:
		edit_offset(world, (sfVector2f){1, 0});
		return (1);
	case sfKeyZ:
		edit_offset(world, (sfVector2f){0, -1});
		return (1);
	case sfKeyS:
		edit_offset(world, (sfVector2f){0, 1});
		return (1);
	default:
		return (0);
	}
	return (0);
}

int	manage_move(sfEvent e, my_world_t *world)
{
	int rtn = 0;
	int rtn2 = 0;

	if (e.type == sfEvtKeyPressed) {
		rtn = manage_angle_move(e.key.code, world);
		rtn2 = manage_offset_move(e.key.code, world);
	}
	return (rtn || rtn2 ? 1 : 0);
}
