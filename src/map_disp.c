/*
** EPITECH PROJECT, 2018
** my_world_boostrap_2017
** File description:
** map disp
*/

#include "myworld.h"

sfColor	get_line_color(pos_t *pt1, pos_t *pt2)
{
	sfColor color = (sfColor){255,159,243,255};

	if (pt1->selected && pt2->selected)
		return (color);
	return (sfWhite);
}

sfVertexArray *create_line(pos_t *pt1, pos_t *pt2)
{
	sfVertexArray *vertex_array = sfVertexArray_create();
	sfColor linecolor = get_line_color(pt1, pt2);
	sfVector2f point1 = (sfVector2f){pt1->x, pt1->y};
	sfVector2f point2 = (sfVector2f){pt2->x, pt2->y};

	sfVertex vertex1 = {.position = point1, .color = linecolor};
	sfVertex vertex2 = {.position = point2, .color = linecolor};
	sfVertexArray_append(vertex_array, vertex1);
	sfVertexArray_append(vertex_array, vertex2);
	sfVertexArray_setPrimitiveType(vertex_array, sfLinesStrip);
	return (vertex_array);
}

int	draw_selection(sfRenderWindow *wd, pos_t *pos)
{
	sfCircleShape	*circ = NULL;

	if (pos->selected == 1) {
		circ = sfCircleShape_create();
		sfCircleShape_setPointCount(circ, 10);
		sfCircleShape_setPosition(circ, (sfVector2f){pos->x-6, pos->y-6});
		sfCircleShape_setRadius(circ, 6);
		sfCircleShape_setFillColor(circ, (sfColor){255,159,243,255});
		sfRenderWindow_drawCircleShape(wd, circ, NULL);
		return (1);
	}
	return (0);
}

//PAS A LA NORME
int draw_iso_map(sfRenderWindow *wd, map_t *map)
{
	sfVertexArray	*line1 = NULL;
	sfVertexArray	*line2 = NULL;
	pos_t	**isomap = map->isomap;

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
			draw_selection(wd, &isomap[y][x]);
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
