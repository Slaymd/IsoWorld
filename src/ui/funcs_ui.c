/*
** EPITECH PROJECT, 2018
** my_world_2017
** File description:
** UI funcs
*/

#include "myworld.h"
#include "my.h"

void close_window(void *ptr)
{
	sfRenderWindow *wd = (sfRenderWindow*)ptr;
	sfRenderWindow_close(wd);
}

void	click_map_create(void *ptr)
{
	my_world_t *world = (my_world_t*)ptr;
 	textbox_t *tbname = &world->actual_scene->textboxes[0];
	textbox_t *tbwid = &world->actual_scene->textboxes[1];
	textbox_t *tbhei = &world->actual_scene->textboxes[2];
	char *map_name = get_text_string(tbname->text);
	int	map_width = my_getnbr(get_text_string(tbwid->text));
	int	map_height = my_getnbr(get_text_string(tbhei->text));

	tbwid->entry_state = map_width <= 0 ? ERROR : SUCCESS;
	tbhei->entry_state = map_height <= 0 ? ERROR : SUCCESS;
	tbname->entry_state = my_strlen(map_name) < 1 ? ERROR : SUCCESS;
	if (map_width <= 0 || map_height <= 0 || my_strlen(map_name) < 1)
		return;
	world->map = init_map(map_name, map_width, map_height, NULL);
	world->state = 1;
	world->actual_scene = init_map_editor();
	set_window_editor_name(world->wd, map_name);
}
