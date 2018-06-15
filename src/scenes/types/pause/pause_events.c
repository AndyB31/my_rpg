/*
** EPITECH PROJECT, 2018
** game_scene_event
** File description:
** game_scene_event
*/

#include "my_rpg.h"

void pause_key_press_event(sfKeyEvent event, frame_t *frame)
{
	if (event.code == sfKeyEscape)
		set_scene_to(frame, GAME, true);
}
