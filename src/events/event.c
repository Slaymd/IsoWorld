/*
** EPITECH PROJECT, 2018
** event.c
** File description:
** my_world
*/

#include "myworld.h"

void	check_event_map_creator(sfRenderWindow *wd, scene_t *map_creator)
{
	sfEvent event;

	while (sfRenderWindow_pollEvent(wd, &event))
		scene_events_handler(wd, event, map_creator);
}

void check_event_map_editor(sfRenderWindow *wd, my_world_t *world)
{
	sfEvent event;
	int rtn = 0;

	while(sfRenderWindow_pollEvent(wd, &event)) {
		scene_events_handler(wd, event, world->actual_scene);
		if (event.type == sfEvtMouseWheelScrolled)
			manage_wheel_scroll(event, world);
		rtn = manage_selection(event, world);
		if (rtn != 1)
			manage_move(event, world);
	}
}
