/*
** EPITECH PROJECT, 2018
** game_scene_event
** File description:
** game_scene_event
*/

#include "my_rpg.h"

void quest_key_press_event(sfKeyEvent event, frame_t *frame)
{
	scene_t *s = get_scene_by_type(&(frame->scene), frame->curent_scene);
	list_t *sprite = get_list_by_name(&(s->sprite_list), "fire");

	if (event.code == sfKeyEscape)
		set_scene_to(frame, GAME, true);
	if (event.code == sfKeyP)
		sprite->sprite_inf->enabled = true;
}
