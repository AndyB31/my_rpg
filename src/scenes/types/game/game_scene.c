/*
** EPITECH PROJECT, 2018
** game_scene
** File description:
** game_scene
*/

#include "my_rpg.h"

static int init_armor_buttons2(scene_t *inventory)
{
	sfVector2f pos_legggings = {.x = 484, .y = 450};
	sfVector2f pos_boots = {.x = 913, .y = 443};
	sfVector2f pos_shield = {.x = 1054, .y = 443};
	sfVector2f size = {.x = 99, .y = 99};
	button_t *boots = create_button(pos_legggings, size);
	button_t *gloves = create_button(pos_boots, size);
	button_t *shield = create_button(pos_shield, size);

	set_bhc_texture(boots, ASSET_N);
	boots->click_action = &click_action_armor;
	add_button(&(inventory->button_list), boots, "boots");
	set_bhc_texture(gloves, ASSET_N);
	gloves->click_action = &click_action_armor;
	add_button(&(inventory->button_list), gloves, "gloves");
	set_bhc_texture(shield, ASSET_N);
	shield->click_action = &click_action_armor;
	add_button(&(inventory->button_list), shield, "shield");
	return (1);
}

int init_armor_buttons(scene_t *inventory)
{
	sfVector2f pos_helmet = {.x = 485, .y = 304};
	sfVector2f pos_chestplate = {.x = 916, .y = 304};
	sfVector2f pos_sword = {.x = 1054, .y = 304};
	sfVector2f size = {.x = 99, .y = 99};
	button_t *helmet = create_button(pos_helmet, size);
	button_t *chestp = create_button(pos_chestplate, size);
	button_t *sword = create_button(pos_sword, size);

	set_bhc_texture(helmet, ASSET_N);
	helmet->click_action = &click_action_armor;
	add_button(&(inventory->button_list), helmet, "helmet");
	set_bhc_texture(chestp, ASSET_N);
	chestp->click_action = &click_action_armor;
	add_button(&(inventory->button_list), chestp, "chestplate");
	set_bhc_texture(sword, ASSET_N);
	sword->click_action = &click_action_armor;
	add_button(&(inventory->button_list), sword, "sword");
	init_armor_buttons2(inventory);
	return (0);
}

int init_inventory_buttons(scene_t *inventory)
{
	sfVector2f size = {.x = 99, .y = 99};
	sfVector2f pos_slot = {.x = 487, .y = 596};
	button_t *slot = NULL;
	char *tmp = NULL;

	for (int i = 1; i <= 14; i++) {
		slot = create_button(pos_slot, size);
		slot->click_action = &click_action_inventory;
		slot->hover_action = &show_info_inventory;
		tmp = my_nbr_to_str(i);
		set_bhc_texture(slot, ASSET_N);
		add_button(&(inventory->button_list), slot, tmp);
		free(tmp);
		pos_slot.x += 141;
		if (i == 7) {
			pos_slot.x = 487;
			pos_slot.y = 735;
		}
	}
	return (0);
}

void game_init_event(frame_t *frame, scene_t *scene)
{
	if (frame->is_new_player == 2) {
		frame->is_new_player = 0;
		open_cutscene(frame, "how_to_play.conf");
	}
	if (frame->is_new_player == 1) {
		frame->is_new_player = 2;
		open_cutscene(frame, "intro_story.conf");
	}
}

int init_game_scene(list_t **scene_list, frame_t *frame)
{
	scene_t *game = create_scene(GAME);

	game->background_music = sfMusic_createFromFile(MAIN_MUSIC);
	game->event_key_pressed = &game_key_press_event;
	game->event_tick = &update_game;
	game->event_init_post = &game_init_event;
	init_game_scene_buttons(game);
	init_game_scene_sprites(game);
	init_game_lvl_sprites(game);
	init_texts_inventory(game);
	init_texts_dial(game);
	init_inventory_buttons(game);
	init_armor_buttons(game);
	init_chest_buttons(game);
	change_inventory_status(NULL, game);
	change_chest_status(frame, game, NULL);
	init_chest_buttons(game);
	add_scene(scene_list, game);
	return (1);
}
