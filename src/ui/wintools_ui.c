/*
** EPITECH PROJECT, 2018
** my_world_2017
** File description:
** window tools
*/

#include "myworld.h"

sfRenderWindow	*create_window()
{
	sfRenderWindow	*window;
	sfVideoMode	mode;

	mode.width = WIDTH;
	mode.height = HEIGHT;
	mode.bitsPerPixel = 32;
	window = sfRenderWindow_create(mode, "IsoWorld", sfDefaultStyle, NULL);
	sfRenderWindow_setFramerateLimit(window, 30);
	return (window);
}

int	set_window_editor_name(sfRenderWindow *wd, char *map_name)
{
	char wdflat[] = "IsoWorld : ";
	char wdname[my_strlen(map_name)+my_strlen(wdflat)+1];

	for (int i = 0; wdflat[i] != '\0'; i++)
		wdname[i] = wdflat[i];
	for (int i = 0; map_name[i] != '\0'; i++)
		wdname[my_strlen(wdflat)+i] = map_name[i];
	sfRenderWindow_setTitle(wd, wdname);
	return (0);
}
