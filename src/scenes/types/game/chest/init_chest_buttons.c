/*
** EPITECH PROJECT, 2018
** init_chest_button
** File description:
** init_chest_buttons
*/

#include "my_rpg.h"

static int init_chest_buttons_l1(scene_t *game)
{
	sfVector2f size = {.x = 99, .y = 99};
	sfVector2f pos_slot = {.x = 525, .y = 235 + 128};
	button_t *slot = NULL;
	char *tmp = NULL;

	for (int i = 1; i <= 12; i++) {
		slot = create_button(pos_slot, size);
		slot->click_action = &click_action_chest_l;
		slot->hover_action = &show_info_chest;
		tmp = my_nbr_to_str(22 + i);
		set_bhc_texture(slot, ASSET_N);
		add_button(&(game->button_list), slot, tmp);
		free(tmp);
		pos_slot.x += 117;
		if (i != 0 && i % 3 == 0) {
			pos_slot.x = 525;
			pos_slot.y += 128;
		}
	}
	return (0);
}

static int init_chest_buttons_l2(scene_t *game)
{
	sfVector2f size = {.x = 99, .y = 99};
	sfVector2f pos_slot = {.x = 525, .y = 235};
	button_t *slot = NULL;
	char *tmp = NULL;

	for (int i = 1; i <= 2; i++) {
		slot = create_button(pos_slot, size);
		slot->click_action = &click_action_chest_l;
		slot->hover_action = &show_info_chest;
		tmp = my_nbr_to_str(20 + i);
		set_bhc_texture(slot, ASSET_N);
		add_button(&(game->button_list), slot, tmp);
		free(tmp);
		pos_slot.x += (117 * 2);
	}
	return (0);
}

static int init_chest_buttons_r1(scene_t *game)
{
	sfVector2f size = {.x = 99, .y = 99};
	sfVector2f pos_slot = {.x = 1055, .y = 235 + 128};
	button_t *slot = NULL;
	char *tmp = NULL;

	for (int i = 1; i <= 12; i++) {
		slot = create_button(pos_slot, size);
		slot->click_action = &click_action_chest_r;
		slot->hover_action = &show_info_chest;
		tmp = my_nbr_to_str(42 + i);
		set_bhc_texture(slot, ASSET_N);
		add_button(&(game->button_list), slot, tmp);
		free(tmp);
		pos_slot.x += 117;
		if (i != 0 && i % 3 == 0) {
			pos_slot.x = 1055;
			pos_slot.y += 128;
		}
	}
	return (0);
}

static int init_chest_buttons_r2(scene_t *game)
{
	sfVector2f size = {.x = 99, .y = 99};
	sfVector2f pos_slot = {.x = 1055, .y = 235};
	button_t *slot = NULL;
	char *tmp = NULL;

	for (int i = 1; i <= 2; i++) {
		slot = create_button(pos_slot, size);
		slot->click_action = &click_action_chest_r;
		slot->hover_action = &show_info_chest;
		tmp = my_nbr_to_str(40 + i);
		set_bhc_texture(slot, ASSET_N);
		add_button(&(game->button_list), slot, tmp);
		free(tmp);
		pos_slot.x += (117 * 2);
	}
	return (0);
}

int init_chest_buttons(scene_t *game)
{
	init_chest_buttons_l1(game);
	init_chest_buttons_l2(game);
	init_chest_buttons_r1(game);
	init_chest_buttons_r2(game);
	return (0);
}