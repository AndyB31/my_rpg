/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** fight utils
*/

#include "my_rpg.h"

int open_fight(frame_t *frame)
{
	set_scene_to(frame, FIGHT, true);
	return (0);
}