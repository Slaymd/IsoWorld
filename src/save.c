/*
** EPITECH PROJECT, 2018
** save.c
** File description:
** my_world
*/

#include "myworld.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

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

void load_map(info_map_t *map)
{
	int fd = open(".legend", O_RDWR);
	char *str = NULL;
	char **tab = NULL;

	if (fd == -1)
		return;
	for (int i = 0; i < map->width; i++) {
		str = get_next_line(fd);
		if (str == NULL)
			return;
		tab = my_str_split(str, ' ');
		for (int j = 0; tab[j] != NULL && j < map->lenght; j++) {
			map->map3d[i][j] = my_getnbr(tab[j]);
		}
		free_strdarray(tab);
		free(str);
	}
}

int save_map(info_map_t *map)
{
	int fd = open(".legend", O_CREAT, S_IRWXU);
	char *str;

	if (fd == -1)
		return (-1);
	close(fd);
	fd = open(".legend", O_WRONLY | O_TRUNC);
	if (fd == -1)
		return (-1);
	for (int i = 0; i < map->lenght; i++) {
		for (int j = 0; j < map->width; j++) {
			str = my_get_str_from_nbr(map->map3d[i][j]);
			write(fd, str, my_strlen(str));
			write(fd, " ", 1);
			free(str);
		}
		write(fd, "\n", 1);
	}
	close(fd);
	return (0);
}*/
