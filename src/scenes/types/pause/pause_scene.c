/*
** EPITECH PROJECT, 2018
** pause_menu_scene
** File description:
** Main menu scene init
*/
#include "my_rpg.h"

int init_pause_scene(list_t **scene_list, frame_t *frame)
{
	scene_t *pause_menu = create_scene(PAUSE);
	sfVector2i back_size = {.x = -1, .y = -1};
	sprite_info_t *background = create_sprite(0,
	back_size, ASSET_PAUSE_BCK);

	add_sprite_inf(&(pause_menu->sprite_list), background, "backg");
	pause_menu->event_key_pressed = &pause_key_press_event;
	init_resume_button(pause_menu, 730, 50);
	init_option_button(pause_menu, 730, 270);
	init_menu_button(pause_menu, 780, 800);
	init_exit_button(pause_menu, 780, 950);
	add_scene(scene_list, pause_menu);
	return (1);
}
