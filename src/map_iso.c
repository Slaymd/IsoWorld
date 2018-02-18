/*
** EPITECH PROJECT, 2018
** my_world_2017
** File description:
** map iso converter
*/

#include "myworld.h"

sfVector2f project_iso_point(map_t *map, int x, int y, int z)
{
	sfVector2f tdpoint = (sfVector2f){0, 0};
	double angleX = map->angle.x * M_PI / 180;
 	double angleY = map->angle.y * M_PI / 180;

	tdpoint.x = cos(angleX) * x - cos(angleX) * y;
	tdpoint.y = sin(angleY) * y + sin(angleY) * x - z;
	return (tdpoint);
}

sfVector2f	**convert_as_iso_map(map_t *map)
{
	int wid = map->width;
	int hei = map->height;
	sfVector2f **tdmap = (sfVector2f**)malloc(sizeof(sfVector2f*)*hei);
	sfVector3f pt3D = (sfVector3f) {0, 0, 0};

	for (int j = 0; j < hei; j++) {
		tdmap[j] = (sfVector2f*)malloc(sizeof(sfVector2f)*wid);
		for (int i = 0; i < wid; i++) {
			pt3D.x = i * map->scaling.x;
			pt3D.y = j * map->scaling.y;
			pt3D.z = map->map[j][i] * map->scaling.z;
			tdmap[j][i] = project_iso_point(map, pt3D.x, pt3D.y, pt3D.z);
			tdmap[j][i].x = tdmap[j][i].x + WIDTH/2;
			tdmap[j][i].y = tdmap[j][i].y + HEIGHT/hei;
		}
	}
	return (tdmap);
}
