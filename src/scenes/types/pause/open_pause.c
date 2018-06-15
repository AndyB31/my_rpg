/*
** EPITECH PROJECT, 2018
** open_inventory
** File description:
** open_inventory
*/

#include "my_rpg.h"

int open_pause_menu(frame_t *frame)
{
	set_scene_to(frame, PAUSE, true);
	return (1);
}

int open__menu(frame_t *frame)
{
	set_scene_to(frame, GAME, true);
	return (1);
}
