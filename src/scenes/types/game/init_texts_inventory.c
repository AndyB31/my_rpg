/*
** EPITECH PROJECT, 2018
** init_text_inventory
** File description:
** init_texts_inventory
*/

#include "my_rpg.h"

static int init_texts_inventory2(scene_t *game)
{
	text_info_t *text = NULL;
	sfVector2f pos_name = {.x = 1225, .y = 305};
	sfVector2f pos_desc = {.x = 1225, .y = 330};

	text = create_text(ASSET_FONT, "", pos_name, 35);
	add_text_inf(&(game->text_list), text, "name");
	text = create_text(ASSET_FONT, "", pos_desc, 35);
	add_text_inf(&(game->text_list), text, "desc");
	return (1);
}

int init_texts_inventory(scene_t *game)
{
	sfVector2f pos = {.x = 520, .y = 685};
	text_info_t *text = NULL;
	char *tmp = NULL;

	for (int i = 0; i < 14; i++) {
		text = create_text(ASSET_FONT, "0", pos, 35);
		sfText_setColor(text->text, sfYellow);
		tmp = my_nbr_to_str(66 + i);
		add_text_inf(&(game->text_list), text, tmp);
		free(tmp);
		pos.x += 141;
		if (i == 6) {
			pos.x = 520;
			pos.y = 824;
		}
	}
	init_texts_inventory2(game);
	return (1);
}