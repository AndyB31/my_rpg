/*
** EPITECH PROJECT, 2018
** main_menu_actions
** File description:
** main_menu_actions
*/

#include "my_rpg.h"

void main_menu_play_button(int x, int y, frame_t *frame, button_t *button)
{
	set_scene_to(frame, GAME, true);
}

void main_menu_option_button(int x, int y, frame_t *frame, button_t *button)
{
	set_scene_to(frame, OPTION, false);
}

void main_menu_exit_button(int x, int y, frame_t *frame, button_t *button)
{
	sfRenderWindow_close(frame->window);
}
