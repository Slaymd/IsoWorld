/*
** EPITECH PROJECT, 2018
** my_world_2017
** File description:
** load map
*/

#include "myworld.h"

void load_map_header(int fd, my_world_t *world)
{
	char *line = NULL;
	char **spt = NULL;
	char *name = NULL;
	sfVector2i size = {0, 0};
	int	_nbargs = 0;

	while ((line = get_next_line(fd)) != NULL && size.y == 0) {
		spt = my_str_split(line, ' ');
		_nbargs = my_count_word_array_args(spt);
		if (_nbargs == 0)
			continue;
		if (_nbargs == 2 && my_streqstr(spt[0], "name"))
			name = my_strcpy(NULL, spt[1]);
		if (_nbargs == 3 && my_streqstr(spt[0], "size"))
			size = (sfVector2i){my_getnbr(spt[1]), my_getnbr(spt[2])};
		free_strdarray(spt);
		free(line);
	}
	world->map = init_map(name, size.x, size.y, NULL);
}

/*void load_name_size(my_world_t *world, int fd)
{
	char *buff = NULL;
	char **tab = NULL;

	buff = get_next_line(fd);
	tab = my_str_split(buff, ' ');
	world->map->name = my_strcpy(world->map->name, tab[1]);
	free_strdarray(tab);
	free(buff);
	buff = get_next_line(fd);
	tab = my_str_split(buff, ' ');
	printf("%s %s\n", tab[0], tab[1]);
	world->map->width = my_getnbr(tab[1]);
	world->map->height = my_getnbr(tab[2]);
	free_strdarray(tab);
	free(buff);
	world->map = init_map(world->map->name, \
	world->map->width, world->map->height, NULL);
}*/

int load_map(my_world_t *world, char *filename)
{
	int fd = -1;

	if (!is_extension(filename, ".legend"))
		return (-1);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (-1);
	load_map_header(fd, world);
	world->state = 1;
	world->actual_scene = init_map_editor(world);
	world->settings = init_settings();
	//load_name_size(world, fd);
	/*buff = get_next_line(fd);
	buff = get_next_line(fd);
	world->state = 1;
	world->actual_scene = init_map_editor(world);
	world->settings = init_settings();
	while (buff != NULL) {
		tab = my_str_split(buff, ',');
		printf("%s %s\n", tab[0], tab[1]);
		world->map->map[my_getnbr(tab[1])][my_getnbr(tab[0])] = my_getnbr(tab[2]);
		free_strdarray(tab);
		free(buff);
		buff = get_next_line(fd);
	}*/
	return (0);
}
