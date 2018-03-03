/*
** EPITECH PROJECT, 2018
** my_world_2017
** File description:
** init editor UI
*/

#include "myworld.h"

void	init_editor_buttons(my_world_t *world, scene_t *scene)
{
	scene->buttons[0] = *create_flat_button((sfIntRect){20,20,38,45},
		sfBlack, sfWhite, ".");
	scene->buttons[0].action = &switch_selection;
	scene->buttons[0].params = world;
	scene->buttons[0].states = init_bt_states(&scene->buttons[0], 2);
	scene->buttons[0].states[1] = (bt_state_t){1, sfTransparent,
		sfTransparent, ":", NULL, NULL, NULL};
	scene->buttons[0].states[2] = (bt_state_t){1, sfTransparent,
		sfTransparent, "*", NULL, NULL, NULL};
	scene->buttons[0].tooltip = create_tooltip(BT_TP_SELECT, 24);
	scene->buttons[1] = *create_flat_button((sfIntRect){20, HEIGHT-65,
	85, 45}, (sfColor){72, 52, 212, 255}, sfWhite, GENERAL_SAVE);
	scene->buttons[1].action = &save_map;
	scene->buttons[1].params = world;
}

scene_t	*init_map_editor(my_world_t *world)
{
	scene_t *scene = create_scene(2, 0, 0);

	if (scene == NULL)
		return (NULL);
	init_editor_buttons(world, scene);
	return (scene);
}
