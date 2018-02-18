/*
** EPITECH PROJECT, 2018
** my_world_2017
** File description:
** map iso converter
*/

#include "myworld.h"

pos_t project_iso_point(map_t *map, int x, int y, int z)
{
	pos_t	tdpoint = (pos_t){0, 0, 0};
	double angleX = map->angle.x * M_PI / 180;
 	double angleY = map->angle.y * M_PI / 180;

	tdpoint.x = cos(angleX) * x - cos(angleX) * y;
	tdpoint.y = sin(angleY) * y + sin(angleY) * x - z;
	return (tdpoint);
}

pos_t	**convert_as_iso_map(map_t *map)
{
	int wid = map->width;
	int hei = map->height;
	pos_t	**old = map->isomap;
	pos_t	**tdmap = (pos_t**)malloc(sizeof(pos_t*)*hei);
	sfVector3f pt3D = (sfVector3f) {0, 0, 0};

	for (int j = 0; j < hei; j++) {
		tdmap[j] = (pos_t*)malloc(sizeof(pos_t)*wid);
		for (int i = 0; i < wid; i++) {
			pt3D.x = i * map->scaling.x;
			pt3D.y = j * map->scaling.y;
			pt3D.z = map->map[j][i] * map->scaling.z;
			tdmap[j][i] = project_iso_point(map, pt3D.x, pt3D.y, pt3D.z);
			tdmap[j][i].x = tdmap[j][i].x + WIDTH/2;
			tdmap[j][i].y = tdmap[j][i].y + HEIGHT/hei;
			tdmap[j][i].selected = old != NULL ? old[j][i].selected : 0;
		}
	}
	return (tdmap);
}
