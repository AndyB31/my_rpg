/*
** EPITECH PROJECT, 2018
** game_actions.c
** File description:
** game action
*/

#include "my_rpg.h"

void gear_button_action(int x, int y, frame_t *frame, button_t *button)
{
	set_scene_to(frame, OPTION, false);
}

void book_button_action(int x, int y, frame_t *frame, button_t *button)
{
	set_scene_to(frame, QUEST, false);
}
