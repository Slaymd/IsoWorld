/*
** EPITECH PROJECT, 2018
** my_world_boostrap_2017
** File description:
** map disp
*/

#include "myworld.h"

sfRenderWindow	*create_window()
{
	sfRenderWindow	*window;
	sfVideoMode	mode;

	mode.width = WIDTH;
	mode.height = HEIGHT;
	mode.bitsPerPixel = 32;
	window = sfRenderWindow_create(mode, "My World", sfDefaultStyle, NULL);
	sfRenderWindow_setFramerateLimit(window, 30);
	return (window);
}

sfVertexArray *create_line(sfVector2f *point1, sfVector2f *point2)
{
	sfVertexArray *vertex_array = sfVertexArray_create();

	sfVertex vertex1 = {.position = *point1, .color = sfWhite};
	sfVertex vertex2 = {.position = *point2, .color = sfWhite};
	sfVertexArray_append(vertex_array, vertex1);
	sfVertexArray_append(vertex_array, vertex2);
	sfVertexArray_setPrimitiveType(vertex_array, sfLinesStrip);
	return (vertex_array);
}

int draw_iso_map(sfRenderWindow *wd, map_t *map)
{
	sfVertexArray	*line1 = NULL;
	sfVertexArray	*line2 = NULL;
	sfVector2f	**isomap = map->isomap;

	for (int y = 0; y < map->height; y++) {
		for (int x = 0; x < map->width; x++) {
			if (x+1 < map->width)
				line1 = create_line(&isomap[y][x], &isomap[y][x+1]);
			if (y+1 < map->height)
				line2 = create_line(&isomap[y][x], &isomap[y+1][x]);
			if (line1 != NULL)
				sfRenderWindow_drawVertexArray(wd, line1, NULL);
			if (line2 != NULL)
				sfRenderWindow_drawVertexArray(wd, line2, NULL);
			line1 = NULL;
			line2 = NULL;
		}
	}
	return (0);
}


/*void draw_2d_map(info_map_t *map, sfRenderWindow *wd, sfVector2f **map2d)
{
	sfVertexArray *line;
	int i;
	int j;

	for (i = 0; i < map->width; i++) {
		for (j = 0;j < map->lenght - 1; j++) {
			line = create_line(&map2d[i][j], &map2d[i][j + 1]);
			sfRenderWindow_drawVertexArray(wd, line, NULL);
		}
	}
	for (j = 0; j < map->lenght; j++) {
		for (i = 0; i < map->width - 1; i++) {
			line = create_line(&map2d[i][j], &map2d[i + 1][j]);
			sfRenderWindow_drawVertexArray(wd, line, NULL);
		}
	}
}*/
