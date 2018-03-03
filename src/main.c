/*
** EPITECH PROJECT, 2018
** my_world_boostrap_2017
** File description:
** my world
*/

#include "myworld.h"

int	launch_editor(sfRenderWindow *wd, my_world_t *world)
{
	sfRenderWindow_clear(wd, sfBlack);
	check_event_map_editor(wd, world);
	draw_iso_map(wd, world);
	disp_scene(wd, world->actual_scene);
	sfRenderWindow_display(wd);
	return (0);
}

int	launch_map_creator(sfRenderWindow *wd, scene_t *scene)
{
	sfRenderWindow_clear(wd, (sfColor){52, 73, 94, 255});
	check_event_map_creator(wd, scene);
	disp_scene(wd, scene);
	sfRenderWindow_display(wd);
	return (0);
}

void start_program(my_world_t *world, int state)
{
	sfRenderWindow *wd = create_window();
	scene_t *map_creator = init_map_creator(world, wd);
	world->state = state;
	world->wd = wd;

	while (sfRenderWindow_isOpen(wd)) {
		if (world->state == 1) {
			launch_editor(wd, world);
		} else if (world->state == 2) {
			world->actual_scene = map_creator;
			launch_map_creator(wd, map_creator);
		}
	}
	sfRenderWindow_destroy(wd);
}

int	main(int nbargs, char **args)
{
	my_world_t *world = (my_world_t*)malloc(sizeof(*world));

	if (nbargs > 2) {
		free(world);
		return (84);
	}
	if (nbargs == 2 && my_streqstr(args[1], "-h") == 1) {
		my_putstr("coucou\n");
		free(world);
		return (0);
	}
	if (nbargs == 2) {
		if (load_map(world, args[1]) == -1)
			return (84);
	}
	start_program(world, nbargs == 1 ? 2 : 1);
	if (world->state == 1)
		save_map(world);
	free(world);
	return (0);
}
