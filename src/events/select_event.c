/*
** EPITECH PROJECT, 2018
** my_world_2017
** File description:
** select on map event
*/

#include "myworld.h"

int	manage_selection(sfEvent e, my_world_t *world)
{
	sfVector2f pos = (sfVector2f){e.mouseButton.x, e.mouseButton.y};

	if (e.mouseButton.button == sfMouseLeft) {
		my_printf("select at: %d, %d\n", (int)pos.x, (int)pos.y);
	} else if (e.mouseButton.button == sfMouseRight) {
		my_printf("deselect at: %d, %d\n", (int)pos.x, (int)pos.y);
	}
	return (0);
}
