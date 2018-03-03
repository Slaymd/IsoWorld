/*
** EPITECH PROJECT, 2018
** save.c
** File description:
** my_world
*/

#include "myworld.h"

/*void resize_map(info_map_t *map, int lenght, int width)
{
	save_map(map);
	free_map3d(map);
	init_map(map, "unknown", lenght, width);
}

void reset_map(info_map_t *map)
{
	for (int i = 0; i < map->width; i++) {
		for (int j = 0; j < map->lenght; j++)
			map->map3d[i][j] = 0;
	}
}
*/

void save_header(int fd, my_world_t *world)
{
	char *name = "name ";
	char *size = "size ";
	char quote = 34;
	char line = '\n';
	char space = ' ';

	write(fd, name, 5);
	write(fd, &quote, 1);
	write(fd, world->map->name, my_strlen(world->map->name));
	write(fd, &quote, 1);
	write(fd, &line, 1);
	write(fd, size, 5);
	write(fd, my_get_str_from_nbr(world->map->width - 1), \
	my_strlen(my_get_str_from_nbr(world->map->width - 1)));
	write(fd, &space, 1);
	write(fd, my_get_str_from_nbr(world->map->height - 1), \
	my_strlen(my_get_str_from_nbr(world->map->height - 1)));
	write(fd, &line, 1);
}

void save_corners(int fd, int x, int y, int z)
{
	char comma = ',';
	char line = '\n';

	if (z == 0)
		return;
	write(fd, &line, 1);
	write(fd, my_get_str_from_nbr(x), \
	my_strlen(my_get_str_from_nbr(x)));
	write(fd, &comma, 1);
	write(fd, my_get_str_from_nbr(y), \
	my_strlen(my_get_str_from_nbr(y)));
	write(fd, &comma, 1);
	write(fd, my_get_str_from_nbr(z), \
	my_strlen(my_get_str_from_nbr(z)));
}

void save_map(void *ptr)
{
	my_world_t *world = (my_world_t*)ptr;
	char *mapname = my_strcpy(NULL, world->map->name);
	char *ext = my_strcpy(NULL, ".legend");
	char *fname = my_strcat(mapname, ext);
	int fd = open_file_or_create_to_write(fname);

	if (fd == -1)
		return;
	save_header(fd, world);
	for (int i = 0; i < world->map->height; i++) {
		for (int j = 0; j < world->map->width; j++) {
			save_corners(fd, j, i, world->map->map[i][j]);
		}
	}
	close(fd);
}
