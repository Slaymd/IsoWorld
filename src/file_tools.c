/*
** EPITECH PROJECT, 2018
** my_world_2017
** File description:
** file tools
*/

#include "myworld.h"

int	open_file_or_create_to_write(char *path)
{
	int fd = open(path, O_WRONLY);

	if (fd == -1) {
		fd = open(path, O_CREAT);
		if (fd == -1)
			return (-1);
		return (open_file_or_create_to_write(path));
	}
	return (fd);
}

int	open_file_or_create_to_read(char *path)
{
	int fd = open(path, O_CREAT | O_RDONLY);

	if (fd == -1)
		return (-1);
	return (fd);
}

int is_extension(char *path, char *ext)
{
	int idx = my_strlen(ext)-1;

	for (int i = my_strlen(path)-1; i >= 0; i--) {
		if (path[i] == '.')
			return (1);
		if (path[i] == ext[idx])
			idx--;
		else
			return (0);
	}
	return (0);
}
