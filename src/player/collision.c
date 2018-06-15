/*
** EPITECH PROJECT, 2018
** player
** File description:
** rpg
*/
#include "my_rpg.h"

int check_coli_right(frame_t *frame)
{
	int where = frame->player->where;

	for (int i = 0; frame->map[where].wall[i].id != -1; i++) {
		if (frame->map[where].wall[i].pos.y <=
		frame->player->pos.y + 24 &&
		frame->map[where].wall[i].pos.y + 12 >=
		frame->player->pos.y + 24 &&
		frame->map[where].wall[i].pos.x <= frame->player->pos.x + 24 &&
		frame->map[where].wall[i].pos.x + 24 >=
		frame->player->pos.x + 24 && frame->map[where].wall[i].id != 0)
			return (1);
	}
	return (0);
}

int check_coli_left(frame_t *frame)
{
	int where = frame->player->where;

	for (int i = 0; frame->map[where].wall[i].id != -1; i++) {
		if (frame->map[where].wall[i].pos.y <=
		frame->player->pos.y + 24 &&
		frame->map[where].wall[i].pos.y + 12 >=
		frame->player->pos.y + 24
		&& frame->map[where].wall[i].pos.x - 12 <=
		frame->player->pos.x - 12
		&& frame->map[where].wall[i].pos.x >=
		frame->player->pos.x - 12
		&& frame->map[where].wall[i].id != 0)
			return (1);
	}
	return (0);
}

int check_coli_down(frame_t *frame)
{
	int where = frame->player->where;

	for (int i = 0; frame->map[where].wall[i].id != -1; i++) {
		if (frame->map[where].wall[i].pos.y <=
		frame->player->pos.y + 24 + 12
		&& frame->map[where].wall[i].pos.y + 12 >=
		frame->player->pos.y + 12 + 24
		&& frame->map[where].wall[i].pos.x <= frame->player->pos.x &&
		frame->map[where].wall[i].pos.x + 12 >= frame->player->pos.x &&
		frame->map[where].wall[i].id != 0)
			return (1);
	}
	return (0);
}

int check_coli_up(frame_t *frame)
{
	int where = frame->player->where;

	for (int i = 0; frame->map[where].wall[i].id != -1; i++) {
		if (frame->map[where].wall[i].pos.y <=
		frame->player->pos.y + 24 - 12
		&& frame->map[where].wall[i].pos.y + 12 >=
		frame->player->pos.y + 24 - 12
		&& frame->map[where].wall[i].pos.x <= frame->player->pos.x &&
		frame->map[where].wall[i].pos.x + 12 >= frame->player->pos.x
		&& frame->map[where].wall[i].id != 0)
			return (1);
	}
	return (0);
}