/*
** EPITECH PROJECT, 2018
** player
** File description:
** rpg
*/

#include "my_rpg.h"

int condition_id(frame_t *frame, int id, int where, int i)
{
	if (frame->map[where].wall[i].id == id &&
	frame->map[where].wall[i].pos.x - 40 <=
	frame->player->pos.x &&
	frame->map[where].wall[i].pos.x + 50 >=
	frame->player->pos.x &&
	frame->map[where].wall[i].pos.y - 40 <=
	frame->player->pos.y &&
	frame->map[where].wall[i].pos.y + 50 >=
	frame->player->pos.y) {
		return (1);
	} else {
		return (0);
	}
}

int check_boss1(frame_t *frame)
{
	int where = frame->player->where;

	for (int i = 0; frame->map[where].wall[i].id != -1; i++) {
		if (condition_id(frame, 975, where, i) == 1)
			return (1);
		if (condition_id(frame, 976, where, i) == 1)
			return (1);
		if (condition_id(frame, 977, where, i) == 1)
			return (1);
		if (condition_id(frame, 978, where, i) == 1)
			return (1);
		if (condition_id(frame, 979, where, i) == 1)
			return (1);
		if (condition_id(frame, 980, where, i) == 1)
			return (1);
		if (condition_id(frame, 1007, where, i) == 1)
			return (1);
	}
	return (0);
}

int check_boss2(frame_t *frame)
{
	int where = frame->player->where;

	for (int i = 0; frame->map[where].wall[i].id != -1; i++) {
		if (condition_id(frame, 1012, where, i) == 1)
			return (1);
		if (condition_id(frame, 1039, where, i) == 1)
			return (1);
		if (condition_id(frame, 1044, where, i) == 1)
			return (1);
		if (condition_id(frame, 1071, where, i) == 1)
			return (1);
		if (condition_id(frame, 1076, where, i) == 1)
			return (1);
		if (condition_id(frame, 1103, where, i) == 1)
			return (1);
		if (condition_id(frame, 1104, where, i) == 1)
			return (1);
	}
	return (0);
}

int check_boss3(frame_t *frame)
{
	int where = frame->player->where;

	for (int i = 0; frame->map[where].wall[i].id != -1; i++) {
		if (condition_id(frame, 1105, where, i) == 1)
			return (1);
		if (condition_id(frame, 1106, where, i) == 1)
			return (1);
		if (condition_id(frame, 1107, where, i) == 1)
			return (1);
		if (condition_id(frame, 1108, where, i) == 1)
			return (1);
	}
	return (0);
}