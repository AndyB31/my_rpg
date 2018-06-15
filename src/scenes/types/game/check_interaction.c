/*
** EPITECH PROJECT, 2018
** check_interaction
** File description:
** check_interaction
*/

#include "my_rpg.h"

int check_boss(frame_t *frame)
{
	if (check_boss1(frame) == 1)
		return (1);
	if (check_boss2(frame) == 1)
		return (1);
	if (check_boss3(frame) == 1)
		return (1);
	return (0);
}

int check_interaction(frame_t *frame)
{
	player_t *player = frame->player;

	if (check_chest(frame) == 1) {
			close_inventory(frame);
			open_chest(frame, "test.data");
	}
	if (check_boss(frame) == 1)
		set_scene_to(frame, FIGHT, true);
	return (0);
}
