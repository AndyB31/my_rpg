/*
** EPITECH PROJECT, 2018
** init_game_object.c
** File description:
** inti button sprtite and other objects of the game scene
*/

#include "my_rpg.h"

int init_game_scene_buttons(scene_t *game)
{
	init_plus_button(game);
	init_book_button(game);
	init_bag_button(game);
	init_gear_button(game);
	init_tree_button(game);
	init_dna_button(game);
	return (1);
}

int init_game_scene_sprites(scene_t *game)
{
	sfVector2i back_size = {.x = -1, .y = -1};
	sfVector2i tools_size = {.x = 128, .y = 606};
	sprite_info_t *background = create_sprite(0, back_size, ASSET_OVERLAY);
	sprite_info_t *tools = create_sprite(0, tools_size, ASSET_TOOLS);
	sprite_info_t *dialogue = create_sprite(0, back_size, ASSET_DIA_BOX);
	sprite_info_t *inventory = create_sprite(0, back_size, ASSET_INV);
	sprite_info_t *chest = create_sprite(0, back_size, ASSET_CHEST);

	add_sprite_inf(&(game->sprite_list), dialogue, "dial_box");
	add_sprite_inf(&(game->sprite_list), inventory, "inv");
	add_sprite_inf(&(game->sprite_list), background, "backg");
	add_sprite_inf(&(game->sprite_list), tools, "tools");
	add_sprite_inf(&(game->sprite_list), chest, "chest");
	dialogue->enabled = false;
	sprite_set_pos(tools, 1792.0, 66.0);
	return (1);
}

int init_game_lvl_sprites(scene_t *game)
{
	init_game_lvl_heart(game);
	init_game_lvl_power(game);
	init_game_lvl_xp(game);
	return (1);
}
