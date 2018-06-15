/*
** EPITECH PROJECT, 2018
** close_inventory
** File description:
** close_inventory
*/

#include "my_rpg.h"

int close_inventory(frame_t *frame)
{
	scene_t *s = NULL;

	if (frame == NULL)
		return (1);
	s = get_scene_by_type(&(frame->scene), frame->curent_scene);
	if (s == NULL)
		return (1);
	if (is_inv_open(true, false, false))
		change_inventory_status(frame, s);
	return (0);
}