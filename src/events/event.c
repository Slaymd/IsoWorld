/*
** EPITECH PROJECT, 2018
** event.c
** File description:
** my_world
*/

#include "myworld.h"

/*void check_event(sfRenderWindow *wd, tools_t *toolbar, info_map_t *map)
{
	sfEvent event;

	while (sfRenderWindow_pollEvent(wd, &event)) {
		if (event.type == sfEvtClosed)
			sfRenderWindow_close(wd);
		if (event.type == sfEvtKeyPressed)
			check_keys(event, toolbar, map);
		//if (event.type == sfEvtMouseButtonPressed)
			//manage_mouse_click(event.mouseButton, toolbar->ui);
	}
}*/

void	check_event_map_creator(sfRenderWindow *wd, scene_t *map_creator)
{
	sfEvent event;

	while (sfRenderWindow_pollEvent(wd, &event))
		scene_events_handler(wd, event, map_creator);
}

void check_event_map_editor(sfRenderWindow *wd, my_world_t *world)
{
	sfEvent event;

	while(sfRenderWindow_pollEvent(wd, &event)) {
		scene_events_handler(wd, event, world->actual_scene);
		if (event.type == sfEvtMouseWheelScrolled) {
			manage_wheel_scroll(event, world);
		} else if (event.type == sfEvtMouseButtonPressed) {
			manage_selection(event, world);
		}
	}
}
