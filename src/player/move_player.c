/*
** EPITECH PROJECT, 2018
** player
** File description:
** rpg
*/
#include "my_rpg.h"

int check_teleport(frame_t *frame)
{
	int where = frame->player->where;

	for (int i = 0; frame->map[where].behind[i].id != -1; i++) {
		if (frame->map[where].behind[i].pos.y <=
		frame->player->pos.y + 24 - 12
		&& frame->map[where].behind[i].pos.y + 12 >=
		frame->player->pos.y + 24 - 12
		&& frame->map[where].behind[i].pos.x <= frame->player->pos.x &&
		frame->map[where].behind[i].pos.x + 12 >= frame->player->pos.x
		&& frame->map[where].behind[i].id > 0
		&& frame->map[where].behind[i].id < 15) {
			frame->player->where_old = frame->player->where + 1;
			frame->player->where = frame->map[where].behind[i].id
			- 1;
			return (1);
		}
	}
	return (0);
}

int check_chest(frame_t *frame)
{
	int where = frame->player->where;

	for (int i = 0; frame->map[where].wall[i].id != -1; i++) {
		if (frame->map[where].wall[i].id == 551 &&
		frame->map[where].wall[i].pos.x - 26 <=
		frame->player->pos.x + 36 &&
		frame->map[where].wall[i].pos.x + 26 >=
		frame->player->pos.x &&
		frame->map[where].wall[i].pos.y - 26 <=
		frame->player->pos.y + 36 &&
		frame->map[where].wall[i].pos.y + 52 >=
		frame->player->pos.y + 36) {
			return (1);
		}
	}
	return (0);
}

int check_npc(frame_t *frame)
{
	int where = frame->player->where;

	for (int i = 0; frame->map[where].wall[i].id != -1; i++) {
		if (frame->map[where].wall[i].id == 33 &&
		frame->map[where].wall[i].pos.x - 12 <=
		frame->player->pos.x &&
		frame->map[where].wall[i].pos.x + 36 >=
		frame->player->pos.x &&
		frame->map[where].wall[i].pos.y - 12 <=
		frame->player->pos.y &&
		frame->map[where].wall[i].pos.y + 36 >=
		frame->player->pos.y) {
			return (1);
		}
	}
	return (0);
}

int check_new_pos(frame_t *frame)
{
	int where = frame->player->where;

	for (int i = 0; frame->map[where].behind[i].id != -1; i++) {
		if (frame->map[where].behind[i].id ==
		frame->player->where_old + 2000) {
			frame->player->pos.x = frame->map[where].flor[i].pos.x;
			frame->player->pos.y = frame->map[where].flor[i].pos.y;
			return (1);
		}
	}
	return (0);
}

void move_player(frame_t *frame)
{
	static int on = 0;
	if (frame->event.type == sfEvtKeyPressed) {
		if (frame->event.key.code == sfKeyRight &&
		check_coli_right(frame) == 0) {
			frame->player->pos.x += 12;
			on = 1;
		} else if (frame->event.key.code == sfKeyLeft &&
		check_coli_left(frame) == 0) {
			frame->player->pos.x -= 12;
			on = 2;
		}
		if (frame->event.key.code == sfKeyDown &&
		check_coli_down(frame) == 0) {
			frame->player->pos.y += 12;
			on = 3;
		} else if (frame->event.key.code == sfKeyUp &&
		check_coli_up(frame) == 0) {
			frame->player->pos.y -= 12;
			on = 4;
		}
	}
	if (check_teleport(frame) == 1)
		check_new_pos(frame);
}
