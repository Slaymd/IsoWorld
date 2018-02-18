/*
** EPITECH PROJECT, 2018
** UILib
** File description:
** text tools
*/

#include "my_uilib.h"

int	my_strlen_but_text(char *str)
{
	int len = 0;

	for (int i = 0; str[i] != '\0'; i++)
		len++;
	return (len);
}

void set_button_text(button_t *button, char *text, sfColor color, int size)
{
	sfVector2f butpos = get_button_position(button);

	if (button->text != NULL)
		free_text(button->text);
	butpos.x += 10;
	button->text = create_text(butpos, text, size, color);
}

void set_button_text_padding(button_t *button, sfVector2f padding)
{
	sfVector2f butpos = (sfVector2f) {0, 0};

	if (button == NULL || button->text == NULL)
		return;
	butpos = get_button_position(button);
	padding.x += butpos.x;
	padding.y += butpos.y;
	set_text_position(button->text, padding);
}
