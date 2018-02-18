/*
** EPITECH PROJECT, 2018
** UILib
** File description:
** __DESCRIPTION__
*/

#include "my_uilib.h"

void	set_button_color(button_t *button, sfColor fill, sfColor outline)
{
	if (button == NULL || button->type != FLAT)
		return;
	sfRectangleShape_setFillColor(button->rect, fill);
	sfRectangleShape_setOutlineColor(button->rect, outline);
}

void	set_button_outline_thickness(button_t *button, int thickness)
{
	if (button == NULL || button->type != FLAT)
		return;
	sfRectangleShape_setOutlineThickness(button->rect, thickness);
}

sfColor get_button_fill_color(button_t *button)
{
	if (button == NULL || button->type != FLAT)
		return ((sfColor){0, 0, 0, 0});
	return (sfRectangleShape_getFillColor(button->rect));
}

sfColor get_button_outline_color(button_t *button)
{
	if (button == NULL || button->type != FLAT)
		return ((sfColor){0, 0, 0, 0});
	return (sfRectangleShape_getOutlineColor(button->rect));
}
