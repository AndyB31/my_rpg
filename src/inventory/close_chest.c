/*
** EPITECH PROJECT, 2018
** close_chest
** File description:
** close_chest
*/

#include "my_rpg.h"

int close_chest(frame_t *frame)
{
	scene_t *s = NULL;

	if (frame == NULL)
		return (1);
	s = get_scene_by_type(&(frame->scene), frame->curent_scene);
	if (s == NULL)
		return (1);
	if (is_chest_open(true, false, false))
		change_chest_status(frame, s, frame->curr_chest);
	return (0);
}