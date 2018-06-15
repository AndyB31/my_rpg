/*
** EPITECH PROJECT, 2018
** quest_menu_scene
** File description:
** Main menu scene init
*/
#include "my_rpg.h"

int init_quest_scene(list_t **scene_list, frame_t *frame)
{
	scene_t *quest_menu = create_scene(QUEST);
	sfVector2i back_size = {.x = -1, .y = -1};
	sfVector2i fire_size = {.x = 456, .y = 496};
	sprite_info_t *fire = create_sprite(13, fire_size, ASSET_FIRE);
	sprite_info_t *background = create_sprite(0,
	back_size, ASSET_QUEST_BCK);

	quest_menu->event_tick = &run_particuls;
	quest_menu->event_key_pressed = &quest_key_press_event;
	add_sprite_inf(&(quest_menu->sprite_list), background, "backg");
	add_sprite_inf(&(quest_menu->sprite_list), fire, "fire");
	fire->enabled = false;
	init_resume_button(quest_menu, 730, 50);
	add_scene(scene_list, quest_menu);
	return (1);
}
