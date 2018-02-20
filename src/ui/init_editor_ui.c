/*
** EPITECH PROJECT, 2018
** my_world_2017
** File description:
** init editor UI
*/

#include "myworld.h"

scene_t	*init_map_editor(my_world_t *world)
{
	scene_t *scene = create_scene(1, 0, 0);

	if (scene == NULL)
		return (NULL);
	scene->buttons[0] = *create_flat_button((sfIntRect){20, 20, 38, 45},
		sfBlack, sfWhite, ".");
	scene->buttons[0].action = &switch_selection;
	scene->buttons[0].params = world;
	scene->buttons[0].states = init_bt_states(&scene->buttons[0], 1);
	scene->buttons[0].states[1] = (bt_state_t){1, sfTransparent,
		sfTransparent, ":", NULL, NULL, NULL};
	return (scene);
}
