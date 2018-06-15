/*
** EPITECH PROJECT, 2018
** init_text_inventory
** File description:
** init_texts_inventory
*/

#include "my_rpg.h"

int init_texts_dial(scene_t *game)
{
	text_info_t *text = NULL;
	sfVector2f pos_dial = {.x = 325, .y = 960};

	text = create_text(ASSET_FONT, "", pos_dial, 60);
	add_text_inf(&(game->text_list), text, "dial");
	return (1);
}
