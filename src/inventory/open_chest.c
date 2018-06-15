/*
** EPITECH PROJECT, 2018
** open_inventory
** File description:
** open_inventory
*/

#include "my_rpg.h"

int open_chest(frame_t *frame, char *inv_id)
{
	scene_t *s = NULL;

	if (frame == NULL || inv_id == NULL)
		return (1);
	s = get_scene_by_type(&(frame->scene), frame->curent_scene);
	close_inventory(frame);
	frame->curr_chest = set_str_to(frame->curr_chest, inv_id);
	change_chest_status(frame, s, inv_id);
	return (0);
}
