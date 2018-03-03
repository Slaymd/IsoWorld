/*
** EPITECH PROJECT, 2018
** my_world_2017
** File description:
** initializing UI
*/

#include "../../include/myworld.h"

button_t *init_newmap_butts(my_world_t *wld, sfRenderWindow *wd, int nb)
{
	button_t *bts = (button_t*)malloc(sizeof(button_t)*nb);
	sfIntRect quit_rect = (sfIntRect){WIDTH-105, HEIGHT-80, 85, 45};
	sfIntRect crea_rect = (sfIntRect){WIDTH-260, HEIGHT-80, 115, 45};
	sfColor lgray = (sfColor){50, 50, 50, 255};

	if (bts == NULL)
		return (NULL);
	bts[0] = *create_flat_button(quit_rect,sfBlack,sfWhite,GENERAL_EXIT);
	bts[0].action = &close_window;
	bts[0].params = wd;
	bts[1] = *create_flat_button(crea_rect,lgray,sfWhite,GENERAL_CREA);
	bts[1].states = init_bt_states(&bts[1], 1);
	bts[1].states[1] = (bt_state_t){1,sfBlue,sfWhite,
		"OK ?", NULL, &click_map_create, wld};
	bts[1].action = NULL;
	bts[1].params = NULL;
	return (bts);
}

text_t *init_map_creator_texts(int nb)
{
	text_t *texts = (text_t*)malloc(sizeof(text_t)*nb);
	sfColor yellow = (sfColor){249, 202, 36, 255};

	if (texts == NULL)
		return (NULL);
	texts[0] = *create_text((sfVector2f){30,25},SOFT_TITLE,72,sfWhite);
	set_text_font(&texts[0], "assets/fonts/Ubuntu-M.ttf");
	texts[1] = *create_text((sfVector2f){32,95},SOFT_SUBTITLE,32,sfWhite);
	texts[2] = *create_text((sfVector2f){32,150},NO_MAP_MSG,24,yellow);
	texts[3] = *create_text((sfVector2f){32,230},CREA_MAPNAME,28,sfWhite);
	texts[4] = *create_text((sfVector2f){32,340},CREA_MAPSIZE,28,sfWhite);
	texts[5] = *create_text((sfVector2f){120,380},GENERAL_MULT,24,sfWhite);
	return (texts);
}

scene_t	*init_map_creator(my_world_t *world, sfRenderWindow *wd)
{
	scene_t *scene = create_scene(2, 3, 6);
	sfIntRect tb1_rect = (sfIntRect){36, 270, 350, 40};
	sfIntRect tb2_rect = (sfIntRect){36, 380, 70, 40};
	sfIntRect tb3_rect = (sfIntRect){146, 380, 70, 40};

	if (scene == NULL)
		return (NULL);
	scene->buttons = init_newmap_butts(world, wd, scene->nb_buttons);
	scene->texts = init_map_creator_texts(scene->nb_texts);
	scene->textboxes[0] = *create_textbox(tb1_rect, sfBlack, sfWhite);
	scene->textboxes[1] = *create_textbox(tb2_rect, sfBlack, sfWhite);
	scene->textboxes[1].type = ONLY_NUM;
	scene->textboxes[2] = *create_textbox(tb3_rect, sfBlack, sfWhite);
	scene->textboxes[2].type = ONLY_NUM;
	return (scene);
}
