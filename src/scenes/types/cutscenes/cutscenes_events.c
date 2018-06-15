/*
** EPITECH PROJECT, 2018
** cutscenes_event
** File description:
** cutscenes_events
*/

#include "my_rpg.h"

void cutscene_key_press_event(sfKeyEvent event, frame_t *frame)
{
	if (event.code == sfKeySpace)
		set_scene_to(frame, GAME, true);
	if (event.code == sfKeyEscape)
		set_scene_to(frame, OPTION, true);
}