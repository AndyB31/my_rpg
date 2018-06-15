/*
** EPITECH PROJECT, 2018
** open_cutscene
** File description:
** open_cutscene
*/

#include "my_rpg.h"

void open_cutscene(frame_t *frame, char *id)
{
	frame->cutscene = set_str_to(frame->cutscene, id);
	set_scene_to(frame, CUTSCENE, true);
}