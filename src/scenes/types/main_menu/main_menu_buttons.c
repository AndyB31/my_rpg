/*
** EPITECH PROJECT, 2018
** main_menu_buttons
** File description:
** main_menu_buttons
*/

#include "my_rpg.h"

void init_play_button(scene_t *main_menu)
{
	sfVector2f play_pos = {.x = 800, .y = 340};
	sfVector2f play_size = {.x = 480, .y = 170};
	button_t *play_button = create_button(play_pos, play_size);

	play_button->click_action = &main_menu_play_button;
	set_base_texture(play_button, ASSET_PLAY);
	set_hover_texture(play_button, ASSET_PLAY_);
	set_clicked_texture(play_button, ASSET_PLAY1);
	add_button(&(main_menu->button_list), play_button, "play_b");
}

void init_option_button(scene_t *main_menu, int x, int y)
{
	sfVector2f option_pos = {.x = x, .y = y};
	sfVector2f option_size = {.x = 480, .y = 170};
	button_t *option_button = create_button(option_pos, option_size);

	option_button->click_action = &main_menu_option_button;
	set_base_texture(option_button, ASSET_OPTION);
	set_hover_texture(option_button, ASSET_OPTION_);
	set_clicked_texture(option_button, ASSET_OPTION1);
	add_button(&(main_menu->button_list), option_button, "opt_b");
}

void init_exit_button(scene_t *main_menu, int x, int y)
{
	sfVector2f exit_pos = {.x = x, .y = y};
	sfVector2f exit_size = {.x = 480, .y = 170};
	button_t *exit_button = create_button(exit_pos, exit_size);

	exit_button->click_action = &main_menu_exit_button;
	set_base_texture(exit_button, ASSET_EXIT);
	set_hover_texture(exit_button, ASSET_EXIT_);
	set_clicked_texture(exit_button, ASSET_EXIT1);
	add_button(&(main_menu->button_list), exit_button, "exit_b");
}
