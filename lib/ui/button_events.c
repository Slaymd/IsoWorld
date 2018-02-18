/*
** EPITECH PROJECT, 2018
** UILib
** File description:
** button events
*/

#include "my_uilib.h"

int	check_pos_in_button(button_t *button, sfVector2f pos)
{
	sfVector2f bpos = get_button_position(button);
	sfVector2f bsize = get_button_size(button);

	if (button != NULL && pos.x >= bpos.x && pos.y >= bpos.y)
		if (pos.x <= bpos.x+bsize.x && pos.y <= bpos.y+bsize.y)
			return (1);
	return (0);
}

int	click_on_buttons(sfEvent event, button_t *buttons, int nb)
{
	sfVector2f pos = {event.mouseButton.x, event.mouseButton.y};
	void *params = NULL;

	for (int i = 0; i < nb; i++) {
		params = buttons[i].params;
		if (check_pos_in_button(&buttons[i], pos) && params != NULL) {
			buttons[i].action(params);
		} else if (check_pos_in_button(&buttons[i], pos))
			buttons[i].action(NULL);
	}
	return (0);
}

int	hover_on_buttons(sfEvent event, button_t *buttons, int nb)
{
	sfVector2f pos = {event.mouseMove.x, event.mouseMove.y};

	for (int i = 0; i < nb; i++) {
		if (check_pos_in_button(&buttons[i], pos))
			set_button_hover_design(&buttons[i]);
		else
			rem_button_hover_design(&buttons[i]);
	}
	return (0);
}
