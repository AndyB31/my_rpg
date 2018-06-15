/*
** EPITECH PROJECT, 2018
** main_menu_scene
** File description:
** Main menu scene init
*/

#include "my_rpg.h"

int init_main_menu_scene(list_t **scene_list, frame_t *frame)
{
	scene_t *main_menu = create_scene(MAIN_MENU);

	init_main_menu_sprite(main_menu);
	init_play_button(main_menu);
	init_option_button(main_menu, 720, 500);
	init_exit_button(main_menu, 800, 680);
	add_scene(scene_list, main_menu);
	main_menu->event_tick = &update_walk;
	return (1);
}

int init_main_menu_sprite(scene_t *main_menu)
{
	sfVector2i back_size = {.x = -1, .y = -1};
	sprite_info_t *background = create_sprite(0, back_size, \
	ASSET_MENU_BCK);
	sfVector2i walk_size = {.x = 21, .y = 43};
	sprite_info_t *walk = create_sprite(3, walk_size, ASSET_WALK);
	sprite_info_t *background_ = create_sprite(0, back_size, \
	ASSET_MENU_BCK_);

	sprite_set_scale(walk, 2.8, 2.8);
	walk->pos.y = 890;
	sprite_set_pos(walk, 1400.0, 890.0);
	walk->tick_max = 5;
	add_sprite_inf(&(main_menu->sprite_list), background, "backg");
	add_sprite_inf(&(main_menu->sprite_list), walk, "walk");
	add_sprite_inf(&(main_menu->sprite_list), background_, "backg_");
	return (0);
}

void update_walk(frame_t *frame, scene_t *scene)
{
	sfVector2f curr_pos;
	list_t *sprite = get_list_by_name(&(scene->sprite_list), "walk");

	curr_pos = sfSprite_getPosition(sprite->sprite_inf->sprite);
	if (curr_pos.x < 460)
		sprite_set_pos(sprite->sprite_inf, 1400.0, 890.0);
	else
		sprite_set_pos(sprite->sprite_inf, \
		curr_pos.x - 2, 890.0);
}
