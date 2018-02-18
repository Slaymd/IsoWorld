/*
** EPITECH PROJECT, 2018
** my_world_2017
** File description:
** init editor UI
*/

#include "myworld.h"

scene_t	*init_map_editor(/*my_world_t *world, sfRenderWindow *wd*/void)
{
	scene_t *scene = create_scene(0, 0, 0);

	if (scene == NULL)
		return (NULL);
	return (scene);
}
