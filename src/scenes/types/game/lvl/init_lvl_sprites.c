/*
** EPITECH PROJECT, 2018
** inti_lvl_sprites
** File description:
** init lvl sprites
*/

#include "my_rpg.h"

int init_game_lvl_heart(scene_t *game)
{
	sfVector2i heart_size = {.x = 554, .y = 36};
	sprite_info_t *r0 = create_sprite(0, heart_size, R0);
	sprite_info_t *r25 = create_sprite(0, heart_size, R25);
	sprite_info_t *r50 = create_sprite(0, heart_size, R50);
	sprite_info_t *r75 = create_sprite(0, heart_size, R75);
	sprite_info_t *r100 = create_sprite(0, heart_size, R100);

	sprite_set_pos(r0, 72, 15.0);
	sprite_set_pos(r25, 72.0, 15.0);
	sprite_set_pos(r50, 72.0, 15.0);
	sprite_set_pos(r75, 72.0, 15.0);
	sprite_set_pos(r100, 72.0, 15.0);
	add_sprite_inf(&(game->sprite_list), r0, "r0");
	add_sprite_inf(&(game->sprite_list), r25, "r25");
	add_sprite_inf(&(game->sprite_list), r50, "r50");
	add_sprite_inf(&(game->sprite_list), r75, "r75");
	add_sprite_inf(&(game->sprite_list), r100, "r100");
	return (1);
}

int init_game_lvl_power(scene_t *game)
{
	sfVector2i heart_size = {.x = 554, .y = 36};
	sprite_info_t *y0 = create_sprite(0, heart_size, Y0);
	sprite_info_t *y25 = create_sprite(0, heart_size, Y25);
	sprite_info_t *y50 = create_sprite(0, heart_size, Y50);
	sprite_info_t *y75 = create_sprite(0, heart_size, Y75);
	sprite_info_t *y100 = create_sprite(0, heart_size, Y100);

	sprite_set_pos(y0, 696, 15.0);
	sprite_set_pos(y25, 696.0, 15.0);
	sprite_set_pos(y50, 696.0, 15.0);
	sprite_set_pos(y75, 696.0, 15.0);
	sprite_set_pos(y100, 696.0, 15.0);
	add_sprite_inf(&(game->sprite_list), y0, "y0");
	add_sprite_inf(&(game->sprite_list), y25, "y25");
	add_sprite_inf(&(game->sprite_list), y50, "y50");
	add_sprite_inf(&(game->sprite_list), y75, "y75");
	add_sprite_inf(&(game->sprite_list), y100, "y100");
	return (1);
}

int init_game_lvl_xp(scene_t *game)
{
	sfVector2i heart_size = {.x = 504, .y = 36};
	sprite_info_t *b0 = create_sprite(0, heart_size, B0);
	sprite_info_t *b25 = create_sprite(0, heart_size, B25);
	sprite_info_t *b50 = create_sprite(0, heart_size, B50);
	sprite_info_t *b75 = create_sprite(0, heart_size, B75);
	sprite_info_t *b100 = create_sprite(0, heart_size, B100);

	sprite_set_pos(b0, 1336, 15.0);
	sprite_set_pos(b25, 1336.0, 15.0);
	sprite_set_pos(b50, 1336.0, 15.0);
	sprite_set_pos(b75, 1336.0, 15.0);
	sprite_set_pos(b100, 1336.0, 15.0);
	add_sprite_inf(&(game->sprite_list), b0, "b0");
	add_sprite_inf(&(game->sprite_list), b25, "b25");
	add_sprite_inf(&(game->sprite_list), b50, "b50");
	add_sprite_inf(&(game->sprite_list), b75, "b75");
	add_sprite_inf(&(game->sprite_list), b100, "b100");
	return (1);
}