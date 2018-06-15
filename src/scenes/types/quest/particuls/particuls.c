/*
** EPITECH PROJECT, 2018
** particuls.c
** File description:
** particuls
*/

#include "my_rpg.h"

int run_particuls(frame_t *frame, scene_t *scene)
{
	list_t *sprite = get_list_by_name(&(scene->sprite_list), "fire");

	if (sprite->sprite_inf->enabled == true &&
	sprite->sprite_inf->current_state ==
	sprite->sprite_inf->total_states - 1) {
		sprite->sprite_inf->enabled = false;
		sprite->sprite_inf->current_state = 0;
	}
	return (0);
}
