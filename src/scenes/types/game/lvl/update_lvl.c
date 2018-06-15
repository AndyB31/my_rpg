/*
** EPITECH PROJECT, 2018
** update_lvl.c
** File description:
** update lvls
*/

#include "my_rpg.h"

int update_lvl(frame_t *frame, scene_t *game)
{
	if (frame->player->pa < frame->player->pa_max)
		frame->player->pa += 1;
	if (frame->player->pa > frame->player->pa_max)
		frame->player->pa = frame->player->pa_max;
	update_heart(frame, game);
	update_power(frame, game);
	update_xp(frame, game);
	return (1);
}

int update_heart(frame_t *frame, scene_t *game)
{
	int lvl = ((float)frame->player->pv / (float)frame->player->pv_max) \
	* 100;
	list_t *r0 = get_list_by_name(&(game->sprite_list), "r0");
	list_t *r25 = get_list_by_name(&(game->sprite_list), "r25");
	list_t *r50 = get_list_by_name(&(game->sprite_list), "r50");
	list_t *r75 = get_list_by_name(&(game->sprite_list), "r75");
	list_t *r100 = get_list_by_name(&(game->sprite_list), "r100");

	disable_heart(game);
	if (lvl >= 0 && lvl <= 5)
		r0->sprite_inf->enabled = true;
	if (lvl > 5 && lvl <= 25)
		r25->sprite_inf->enabled = true;
	if (lvl > 25 && lvl <= 50)
		r50->sprite_inf->enabled = true;
	if (lvl > 50 && lvl <= 75)
		r75->sprite_inf->enabled = true;
	if (lvl > 75 && lvl <= 100)
		r100->sprite_inf->enabled = true;
	return (1);
}

int update_power(frame_t *frame, scene_t *game)
{
	int lvl = ((float)frame->player->pa / (float)frame->player->pa_max) \
	* 100;
	list_t *y0 = get_list_by_name(&(game->sprite_list), "y0");
	list_t *y25 = get_list_by_name(&(game->sprite_list), "y25");
	list_t *y50 = get_list_by_name(&(game->sprite_list), "y50");
	list_t *y75 = get_list_by_name(&(game->sprite_list), "y75");
	list_t *y100 = get_list_by_name(&(game->sprite_list), "y100");

	disable_powey(game);
	if (lvl >= 0 && lvl <= 5)
		y0->sprite_inf->enabled = true;
	if (lvl > 5 && lvl <= 25)
		y25->sprite_inf->enabled = true;
	if (lvl > 25 && lvl <= 50)
		y50->sprite_inf->enabled = true;
	if (lvl > 50 && lvl <= 75)
		y75->sprite_inf->enabled = true;
	if (lvl > 75 && lvl <= 100)
		y100->sprite_inf->enabled = true;
	return (1);
}

int update_xp(frame_t *frame, scene_t *game)
{
	int lvl = ((float)frame->player->xp / 100) * 100;
	list_t *b0 = get_list_by_name(&(game->sprite_list), "b0");
	list_t *b25 = get_list_by_name(&(game->sprite_list), "b25");
	list_t *b50 = get_list_by_name(&(game->sprite_list), "b50");
	list_t *b75 = get_list_by_name(&(game->sprite_list), "b75");
	list_t *b100 = get_list_by_name(&(game->sprite_list), "b100");

	disable_xp(game);
	if (lvl >= 0 && lvl <= 5)
		b0->sprite_inf->enabled = true;
	if (lvl > 5 && lvl <= 25)
		b25->sprite_inf->enabled = true;
	if (lvl > 25 && lvl <= 50)
		b50->sprite_inf->enabled = true;
	if (lvl > 50 && lvl <= 75)
		b75->sprite_inf->enabled = true;
	if (lvl > 75 && lvl <= 100)
		b100->sprite_inf->enabled = true;
	return (1);
}
