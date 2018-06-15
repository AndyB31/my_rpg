/*
** EPITECH PROJECT, 2018
** disable lvl.c
** File description:
** disable all sprites
*/
#include "my_rpg.h"

int disable_heart(scene_t *game)
{
	list_t *r0 = get_list_by_name(&(game->sprite_list), "r0");
	list_t *r25 = get_list_by_name(&(game->sprite_list), "r25");
	list_t *r50 = get_list_by_name(&(game->sprite_list), "r50");
	list_t *r75 = get_list_by_name(&(game->sprite_list), "r75");
	list_t *r100 = get_list_by_name(&(game->sprite_list), "r100");

	r0->sprite_inf->enabled = false;
	r25->sprite_inf->enabled = false;
	r50->sprite_inf->enabled = false;
	r75->sprite_inf->enabled = false;
	r100->sprite_inf->enabled = false;
	return (1);
}

int disable_powey(scene_t *game)
{
	list_t *y0 = get_list_by_name(&(game->sprite_list), "y0");
	list_t *y25 = get_list_by_name(&(game->sprite_list), "y25");
	list_t *y50 = get_list_by_name(&(game->sprite_list), "y50");
	list_t *y75 = get_list_by_name(&(game->sprite_list), "y75");
	list_t *y100 = get_list_by_name(&(game->sprite_list), "y100");

	y0->sprite_inf->enabled = false;
	y25->sprite_inf->enabled = false;
	y50->sprite_inf->enabled = false;
	y75->sprite_inf->enabled = false;
	y100->sprite_inf->enabled = false;
	return (1);
}

int disable_xp(scene_t *game)
{
	list_t *b0 = get_list_by_name(&(game->sprite_list), "b0");
	list_t *b25 = get_list_by_name(&(game->sprite_list), "b25");
	list_t *b50 = get_list_by_name(&(game->sprite_list), "b50");
	list_t *b75 = get_list_by_name(&(game->sprite_list), "b75");
	list_t *b100 = get_list_by_name(&(game->sprite_list), "b100");

	b0->sprite_inf->enabled = false;
	b25->sprite_inf->enabled = false;
	b50->sprite_inf->enabled = false;
	b75->sprite_inf->enabled = false;
	b100->sprite_inf->enabled = false;
	return (1);
}
