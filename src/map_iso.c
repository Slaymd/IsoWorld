/*
** EPITECH PROJECT, 2018
** my_world_2017
** File description:
** map iso converter
*/

#include "myworld.h"

pos_t project_iso_point(map_t *map, int zoom, sfVector2f off, int pt[3])
{
	pos_t	tdpoint = (pos_t){0, 0, 0, sfRed};
	double angleX = -map->angle.x * M_PI / 180;
 	double angleY = map->angle.y * M_PI / 180;
	int a = (map->width/2)*map->scaling.x*zoom;
	int b = (map->height/2)*map->scaling.y*zoom;

	tdpoint.x = a+cos(angleX)*(pt[0]-a)-sin(angleX)*(pt[1]-b);
	tdpoint.y = b+sin(angleX)*(pt[0]-a)+cos(angleX)*(pt[1]-b);

	tdpoint.y = cos(angleY)*(tdpoint.y)-sin(angleY)*(pt[2]);

	tdpoint.x += WIDTH/2 - a + off.x*map->scaling.x*zoom;
	tdpoint.y += HEIGHT/2 - b /2 + off.y*map->scaling.y*zoom;
	return (tdpoint);
}

pos_t	**convert_as_iso_map(map_t *map, int zoom, sfVector2f offset)
{
	int wid = map->width;
	int hei = map->height;
	pos_t	**od = map->isomap;
	pos_t	**tdm = (pos_t**)malloc(sizeof(pos_t*)*hei);
	sfVector3f pt3D = (sfVector3f) {0, 0, 0};

	for (int j = 0; j < hei; j++) {
		tdm[j] = (pos_t*)malloc(sizeof(pos_t)*wid);
		for (int i = 0; i < wid; i++) {
			pt3D.x = i * map->scaling.x*zoom;
			pt3D.y = j * map->scaling.y*zoom;
			pt3D.z = map->map[j][i] * map->scaling.z*zoom;
			tdm[j][i] = project_iso_point(map, zoom,
				offset, (int[3]){pt3D.x,pt3D.y,pt3D.z});
			tdm[j][i].x = tdm[j][i].x;
			tdm[j][i].y = tdm[j][i].y;
			tdm[j][i].selected = od != NULL ? od[j][i].selected : 0;
		}
	}
	return (tdm);
}

int	update_iso_map_from_settings(my_world_t *world)
{
	settings_t *stn = world->settings;

	world->map->isomap = convert_as_iso_map(world->map,
		stn->zoom, stn->offset);
	return (1);
}
