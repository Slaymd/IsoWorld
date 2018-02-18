/*
** EPITECH PROJECT, 2018
** my_world_2017
** File description:
** my_uilib
*/

#include <SFML/Graphics.h>
#include <stdlib.h>

#define DEFAULT_FONT "assets/fonts/UbuntuMono-R.ttf"

typedef enum
{
	FLAT=0,
	IMAGE=1,
}button_type_e;

typedef enum
{
	ALL=0,
	ONLY_LET=1,
	ONLY_NUM=2,
}textbox_entry_type_e;

typedef enum
{
	NORMAL=0,
	SUCCESS=1,
	ERROR=2,
}textbox_entry_state_e;

typedef struct tooltip_s {
	char	*str;
}tooltip_t;

typedef struct text_s {
	int		fontsize;
	sfFont	*font;
	sfText	*text;
}text_t;

typedef struct button_s {
	button_type_e type;
	sfRectangleShape *rect;
	struct text_s *text;
	sfSprite *sprite;
	struct tooltip_s *tooltip;
	void (*action)(void*);
	void *params;
}button_t;


typedef struct textbox_s {
	sfRectangleShape 		*rect;
	struct text_s			*text;
	sfColor				outl_color;
	int 					state;
	textbox_entry_type_e	type;
	textbox_entry_state_e	entry_state;
}textbox_t;

typedef struct scene_s {
	int		nb_buttons;
	int		nb_textboxes;
	int		nb_texts;
	button_t	*buttons;
	textbox_t	*textboxes;
	text_t	*texts;
}scene_t;

//Button create
button_t	*create_void_button();
button_t	*create_flat_button(sfIntRect pos, sfColor fill, sfColor outline);

//Button disp
void	disp_button(sfRenderWindow *wd, button_t *button);
void	disp_buttons(sfRenderWindow *wd, button_t *buttons, int nb);

//Button position/size tools
void set_button_size(button_t *button, sfVector2f size);
void set_button_position(button_t *button, sfVector2f pos);
sfVector2f get_button_position(button_t *button);
sfVector2f get_button_size(button_t *button);

//Buttons events
int	click_on_buttons(sfEvent event, button_t *buttons, int nb);
int	hover_on_buttons(sfEvent event, button_t *buttons, int nb);

//****[BUTTON CUSTOMISATION]****
//get fill/outline color:	return FLAT fill/outline color or
//						rgba(0, 0, 0, 0) in case of error
sfColor get_button_fill_color(button_t *button);
sfColor get_button_outline_color(button_t *button);
//set button color:		set button fill and outline color
//					if button is FLAT
void	set_button_color(button_t *button, sfColor fill, sfColor outline);
//set outline thickness:	set button outline border thickness
//					if button is FLAT
void	set_button_outline_thickness(button_t *button, int thickness);
//set button text:		setting button text with UbuntuMono font
//					do nothing when failed
void set_button_text(button_t *button, char *text, sfColor color, int size);
//set button text padding:	set text padding (in the button)
void set_button_text_padding(button_t *button, sfVector2f padding);

//****[BUTTON EVENTS]****
//Check pos:	return 1 if pos is on the gived position
//			if isn't, return 0
int	check_pos_in_button(button_t *button, sfVector2f pos);
//set/rem hover design:	set hover design
//					return 1 if button is FLAT,
//					0 if isn't (and do nothing)
//					WARN: THIS FUNCTION DOESN'T TEST POSITION!
int	set_button_hover_design(button_t *button);
int	rem_button_hover_design(button_t *button);

//****[BUTTON DESTROY]****
//free button: free all instance of button_t
void	free_button(button_t *button);

//****[TEXT]****
//Create
text_t	*create_text(sfVector2f pos, char *str, int size, sfColor color);
//Customization
void	set_text_string(text_t *text, char *str);
char	*get_text_string(text_t *text);
void	set_text_font(text_t *text, char *fontpath);
void	set_text_size(text_t *text, int size);
void set_text_position(text_t *text, sfVector2f pos);
//Disp
void	disp_text(sfRenderWindow *wd, text_t *text);
void	disp_texts(sfRenderWindow *wd, text_t *texts, int nb);
//Destroy
void free_text(text_t *text);

//****[TEXTBOXES]****
//Create
textbox_t	*create_textbox(sfIntRect rect, sfColor fill, sfColor outl);
//position/size tools
void set_textbox_size(textbox_t *textbox, sfVector2f size);
void set_textbox_position(textbox_t *textbox, sfVector2f pos);
sfVector2f get_textbox_position(textbox_t *textbox);
sfVector2f get_textbox_size(textbox_t *textbox);
//textbox colortools
void	set_textbox_color(textbox_t *textbox, sfColor fill, sfColor outline);
void	set_textbox_outline_thickness(textbox_t *textbox, int thickness);
sfColor get_textbox_fill_color(textbox_t *textbox);
sfColor get_textbox_outline_color(textbox_t *textbox);
//effets
int	set_textbox_hover_design(textbox_t *textbox);
int	rem_textbox_hover_design(textbox_t *textbox);
//Events
int	check_pos_in_textbox(textbox_t *textbox, sfVector2f pos);
int	click_on_textboxes(sfEvent event, textbox_t *textboxes, int nb);
int	add_char_in_textboxes(textbox_t *textboxes, int nb, char c);
//Destroy
void	free_textbox(textbox_t *textbox);
//Disps
void	disp_textbox(sfRenderWindow *wd, textbox_t *textbox);
void	disp_textboxes(sfRenderWindow *wd, textbox_t *textboxes, int nb);

//****[EVENTS]****
//Keycode to char
char get_char_from_keycode(sfKeyCode key);

//****[SCENES]****
//Create
scene_t *create_scene(int nb_buttons, int nb_textboxes, int nb_texts);
//Events
int	scene_events_handler(sfRenderWindow *wd, sfEvent event, scene_t *scene);
//Destroy
void	free_scene(scene_t *scene);
//Disp
int	disp_scene(sfRenderWindow *wd, scene_t *scene);
