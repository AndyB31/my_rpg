/*
** EPITECH PROJECT, 2018
** main_menu_actions
** File description:
** main_menu_actions
*/

#include "my_rpg.h"

void menu_button_action(int x, int y, frame_t *frame, button_t *button)
{
	set_scene_to(frame, MAIN_MENU, false);
}

void option_up_button(int x, int y, frame_t *frame, button_t *button)
{
	if (frame->volume_level + 5 < 100)
		frame->volume_level += 5;
	if (frame->curr_sound)
		sfMusic_setVolume(frame->curr_sound, frame->volume_level);
}

void option_down_button(int x, int y, frame_t *frame, button_t *button)
{
	if (frame->volume_level - 5 > 0)
		frame->volume_level -= 5;
	if (frame->curr_sound)
		sfMusic_setVolume(frame->curr_sound, frame->volume_level);
}

void option_mute_button(int x, int y, frame_t *frame, button_t *button)
{
	if (frame->volume_stop == 0) {
		frame->volume_stop = 1;
		if (frame->curr_sound)
			sfMusic_setVolume(frame->curr_sound, 0);
	} else {
		frame->volume_stop = 0;
		if (frame->curr_sound)
			sfMusic_setVolume(frame->curr_sound, \
			frame->volume_level);
	}
}
