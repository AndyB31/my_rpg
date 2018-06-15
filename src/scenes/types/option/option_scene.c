/*
** EPITECH PROJECT, 2018
** option_scene
** File description:
** Main menu scene init
*/

#include "my_rpg.h"

void option_key_press_event(sfKeyEvent event, frame_t *frame)
{
	if (event.code == sfKeyEscape)
		set_scene_to(frame, frame->last_scene, true);
}

int init_option_scene(list_t **scene_list, frame_t *frame)
{
	scene_t *option = create_scene(OPTION);
	sfVector2i back_size = {.x = -1, .y = -1};
	sprite_info_t *background = create_sprite(0,
	back_size, ASSET_OPTION_BCK);

	option->event_key_pressed = &option_key_press_event;
	add_sprite_inf(&(option->sprite_list), background, "backg");
	init_menu_button(option, 1483, 950);
	init_up_button(option);
	init_down_button(option);
	init_mute_button(option);
	add_scene(scene_list, option);
	return (1);
}
