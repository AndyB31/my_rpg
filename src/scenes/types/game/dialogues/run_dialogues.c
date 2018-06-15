/*
** EPITECH PROJECT, 2018
** run_dialogues.c
** File description:
** run_dialogues
*/

#include "my_rpg.h"

int run_dialogues(frame_t *frame, scene_t *game)
{
	list_t *dial_box = get_list_by_name(&(game->sprite_list), "dial_box");
	char *nbr = NULL;
	int nbr_text = 0;

	if (frame->path == NULL)
		return (1);
	nbr = read_value_file(frame->path, "nbr_text");
	nbr_text = my_getnbr(nbr);
	if (frame->dial_nbr == nbr_text + 1) {
		frame->dial_nbr = 1;
		destroy_dialogues(frame, game);
		return (0);
	}
	dial_box->sprite_inf->enabled = true;
	display_dial(game, frame->path, frame->dial_nbr);
	free(nbr);
	return (0);
}

int update_game(frame_t *frame, scene_t *game)
{
	static int tick = 0;
	static int x = 0;
	static int y = 0;

	run_dialogues(frame, game);
	update_lvl(frame, game);
	if (frame->player->pv < frame->player->pv_max)
		frame->player->pv += 1;
	if (frame->player->pv > frame->player->pv_max)
		frame->player->pv = frame->player->pv_max;
	if (x == frame->player->sprite->pos.x \
	&& y == frame->player->sprite->pos.y) {
		if (++tick >= 2) {
			frame->player->sprite->current_state = 1;
			tick = 0;
		}
	}
	x = frame->player->sprite->pos.x;
	y = frame->player->sprite->pos.y;
	return (0);
}

int display_dial(scene_t *game, char *path, int i)
{
	list_t *dial = get_list_by_name(&(game->text_list), "dial");
	char *text = NULL;
	char *str = NULL;

	str = my_nbr_to_str(i);
	text = read_value_file(path, str);
	sfText_setColor(dial->text_inf->text, sfBlack);
	sfText_setString(dial->text_inf->text, text);
	free(text);
	free(str);
	return (0);
}

int destroy_dialogues(frame_t *frame, scene_t *game)
{
	list_t *dial = get_list_by_name(&(game->text_list), "dial");
	list_t *dial_box = get_list_by_name(&(game->sprite_list), "dial_box");

	dial_box->sprite_inf->enabled = false;
	frame->path = NULL;
	sfText_setString(dial->text_inf->text, "");
}
