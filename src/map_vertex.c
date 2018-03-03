/*
** EPITECH PROJECT, 2018
** my_world_2017
** File description:
** vertex
*/

#include "myworld.h"

sfVector2f to_sf(pos_t pos)
{
	return ((sfVector2f){pos.x, pos.y});
}

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

sfVertexArray *create_tile(tile_t *tile)
{
	sfVertexArray *vertex_array = sfVertexArray_create();
	sfColor color = tile->topleft->color;

	sfVertex vertex1 = {.position = to_sf(*tile->topleft), .color = color};
	sfVertex vertex2 = {.position = to_sf(*tile->topright), .color = color};
	sfVertex vertex3 = {.position = to_sf(*tile->botright), .color = color};
	sfVertex vertex4 = {.position = to_sf(*tile->botleft), .color = color};
	sfVertexArray_append(vertex_array, vertex1);
	sfVertexArray_append(vertex_array, vertex2);
	sfVertexArray_append(vertex_array, vertex3);
	sfVertexArray_append(vertex_array, vertex4);
	sfVertexArray_setPrimitiveType(vertex_array, sfQuads);
	return (vertex_array);
}
