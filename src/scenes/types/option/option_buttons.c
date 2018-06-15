/*
** EPITECH PROJECT, 2018
** option_buttons
** File description:
** option_buttons
*/

#include "my_rpg.h"

void init_menu_button(scene_t *option, int x, int y)
{
	sfVector2f menu_pos = {.x = x, .y = y};
	sfVector2f menu_size = {.x = 480, .y = 170};
	button_t *menu_button = create_button(menu_pos, menu_size);

	menu_button->click_action = &menu_button_action;
	set_base_texture(menu_button, ASSET_MENU);
	set_hover_texture(menu_button, ASSET_MENU_);
	set_clicked_texture(menu_button, ASSET_MENU1);
	add_button(&(option->button_list), menu_button, "menu_b");
}

void init_up_button(scene_t *option)
{
	sfVector2f up_pos = {.x = 1268, .y = 80};
	sfVector2f up_size = {.x = 270, .y = 270};
	button_t *up_button = create_button(up_pos, up_size);

	up_button->click_action = &option_up_button;
	set_base_texture(up_button, ASSET_DOWN);
	set_hover_texture(up_button, ASSET_DOWN_);
	set_clicked_texture(up_button, ASSET_DOWN1);
	add_button(&(option->button_list), up_button, "up_b");
}

void init_down_button(scene_t *option)
{
	sfVector2f down_pos = {.x = 356, .y = 80};
	sfVector2f down_size = {.x = 270, .y = 270};
	button_t *down_button = create_button(down_pos, down_size);

	down_button->click_action = &option_down_button;
	set_base_texture(down_button, ASSET_UP);
	set_hover_texture(down_button, ASSET_UP_);
	set_clicked_texture(down_button, ASSET_UP1);
	add_button(&(option->button_list), down_button, "down_b");
}

void init_mute_button(scene_t *option)
{
	sfVector2f mute_pos = {.x = 812, .y = 80};
	sfVector2f mute_size = {.x = 270, .y = 270};
	button_t *mute_button = create_button(mute_pos, mute_size);

	mute_button->click_action = &option_mute_button;
	set_base_texture(mute_button, ASSET_MUTE);
	set_hover_texture(mute_button, ASSET_MUTE_);
	set_clicked_texture(mute_button, ASSET_MUTE1);
	add_button(&(option->button_list), mute_button, "mute_b");
}
