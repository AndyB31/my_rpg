/*
** EPITECH PROJECT, 2018
** init_player
** File description:
** init_player
*/

#include "my_rpg.h"

static player_t *create_player2(player_t *player)
{
	player->pos.y = 402;
	player->pos.x = 1008;
	player->sprite = NULL;
	player->where = 0;
	player->where_old = 0;
	return (player);
}

player_t *create_player(void)
{
	player_t *player = malloc(sizeof(player_t));

	if (player == NULL)
		return (NULL);
	player->wind = 1;
	player->water = 1;
	player->fire = 1;
	player->inventory = NULL;
	player->lvl = 1;
	player->magic = 1;
	player->pa = 6;
	player->pa_max = 6;
	player->pv = 100;
	player->pv_max = 100;
	player->round = -1;
	player->dirt = 1;
	player->xp = 0;
	return (create_player2(player));
}

int init_pos_player(frame_t *frame)
{

	for (int i = 0; frame->map[0].flor[i].id != -1; i++) {
		if (frame->map[0].flor[i].id == 100) {
			frame->player->pos.x = frame->map[0].flor[i].pos.x;
			frame->player->pos.y = frame->map[0].flor[i].pos.y;
			return (1);
		}
	}
	return (0);
}

int player_manager(frame_t *frame)
{
	if (is_file_in_dir("player.data", "./data/") == 0) {
		frame->player = create_player();
		init_pos_player(frame);
		write_player(frame->player);
		frame->player->inventory = open_player_inventory();
		frame->is_new_player = 1;
	} else {
		frame->player = read_player();
	}
	return (0);
}
