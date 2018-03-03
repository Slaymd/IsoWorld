/*
** EPITECH PROJECT, 2018
** my_world_2017
** File description:
** settings init
*/

#include "myworld.h"

settings_t	*init_settings(void)
{
	settings_t *stn = (settings_t*)malloc(sizeof(*stn));

	stn->select_type = 0;
	stn->zoom = DEFAULT_ZOOM;
	stn->offset = (sfVector2f){0,0};
	return (stn);
}
