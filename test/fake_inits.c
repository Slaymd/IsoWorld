/*
** EPITECH PROJECT, 2018
** my_world_2017
** File description:
** fake inits for tests purposes
*/

#include "myworld.h"

my_world_t *init_world_test(void)
{
	my_world_t *world = (my_world_t*)malloc(sizeof(my_world_t*));

	world->map = init_map("testmap", 10, 10, NULL);
	world->state = 1;
	world->actual_scene = NULL;
	world->settings = init_settings();
	return (world);
}
