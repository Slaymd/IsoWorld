/*
** EPITECH PROJECT, 2018
** UILib
** File description:
** __DESCRIPTION__
*/

#include "my_uilib.h"

void	set_textbox_color(textbox_t *textbox, sfColor fill, sfColor outline)
{
	if (textbox == NULL)
		return;
	sfRectangleShape_setFillColor(textbox->rect, fill);
	sfRectangleShape_setOutlineColor(textbox->rect, outline);
}

void	set_textbox_outline_thickness(textbox_t *textbox, int thickness)
{
	if (textbox == NULL)
		return;
	sfRectangleShape_setOutlineThickness(textbox->rect, thickness);
}

sfColor get_textbox_fill_color(textbox_t *textbox)
{
	if (textbox == NULL)
		return ((sfColor){0, 0, 0, 0});
	return (sfRectangleShape_getFillColor(textbox->rect));
}

sfColor get_textbox_outline_color(textbox_t *textbox)
{
	if (textbox == NULL)
		return ((sfColor){0, 0, 0, 0});
	return (sfRectangleShape_getOutlineColor(textbox->rect));
}
