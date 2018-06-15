/*
** EPITECH PROJECT, 2018
** main_menu_buttons
** File description:
** main_menu_buttons
*/

#include "my_rpg.h"

void init_resume_button(scene_t *main_menu, int x, int y)
{
	sfVector2f resume_pos = {.x = x, .y = y};
	sfVector2f resume_size = {.x = 480, .y = 170};
	button_t *resume_button = create_button(resume_pos, resume_size);

	resume_button->click_action = &resume_button_action;
	set_base_texture(resume_button, ASSET_RESUME);
	set_hover_texture(resume_button, ASSET_RESUME_);
	set_clicked_texture(resume_button, ASSET_RESUME1);
	add_button(&(main_menu->button_list), resume_button, "resume_b");
}
