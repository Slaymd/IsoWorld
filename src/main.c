/*
** EPITECH PROJECT, 2018
** my_world_boostrap_2017
** File description:
** my world
*/

#include "myworld.h"

/*int init_tools(my_world_t *world)
{
	tools_t *toolbar = (tools_t*)malloc(sizeof(*toolbar));

	toolbar->move = 1;
	toolbar->zoom = 1;
	toolbar->rotate = 0;
	toolbar->select_corner = 0;
	toolbar->select_tile = 0;
	world->toolbar = toolbar;
	return (0);
}*/

/*void init_map(info_map_t *map, char *str, int lenght, int width)
{
	my_printf("Initializing map with name: %s\n", str);
	map->lenght = lenght;
	map->width = width;
	map->angle_x = 45;
	map->angle_y = 35;
	map->scaling_x = (WIDTH - 200) / map->width;
	map->scaling_y = (HEIGHT - 200) / map->lenght;
	map->scaling_z = 20;
	map->coord_map_x = WIDTH / 2;
	map->coord_map_y = HEIGHT / map->lenght;
	if (generate_map(map) == 84)
		map->map3d = NULL;
	load_map(map);
}*/

int	launch_editor(sfRenderWindow *wd, my_world_t *world)
{
	sfRenderWindow_clear(wd, sfBlack);
	check_event_map_editor(wd, world);
	//draw_2d_map(world->map, wd, map2d);
	draw_iso_map(wd, world->map);
	disp_scene(wd, world->actual_scene);
	sfRenderWindow_display(wd);
	//free_map2d(world->map, map2d);
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
	//init_tools(world);
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
	//free(world->toolbar);
	sfRenderWindow_destroy(wd);
}

int	main(int nbargs, char **args)
{
	my_world_t *world = (my_world_t*)malloc(sizeof(*world));

	(void)args;
	// load map if necesarry
	start_program(world, nbargs == 1 ? 2 : 1);
	/*if (world->state != 2) {
		save_map(world->map);
		free_map3d(world->map);
	}
	free(map);*/
	free(world);
	return (0);
}
