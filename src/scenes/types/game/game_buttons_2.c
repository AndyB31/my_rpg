/*
** EPITECH PROJECT, 2018
** game_buttons.c
** File description:
** game buttons
*/

#include "my_rpg.h"

void init_dna_button(scene_t *game)
{
	sfVector2f dna_pos = {.x = 1803, .y = 324};
	sfVector2f dna_size = {.x = 100, .y = 100};
	button_t *dna_button = create_button(dna_pos, dna_size);

	set_base_texture(dna_button, ASSET_DNA);
	set_hover_texture(dna_button, ASSET_DNA);
	set_clicked_texture(dna_button, ASSET_DNA);
	add_button(&(game->button_list), dna_button, "dna_b");
}
