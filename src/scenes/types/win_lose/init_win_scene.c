/*
** EPITECH PROJECT, 2018
** init_intro_scene
** File description:
** init_intro_scene
*/

#include "my_rpg.h"

void win_scene_tick2(frame_t *frame, scene_t *scene)
{
	list_t *list = get_list_by_name(&(scene->sprite_list), "img");
	sprite_info_t *img = list->sprite_inf;
	sfColor color = sfSprite_getColor(img->sprite);

	if (color.a > 0) {
		color.a -= 10;
		sfSprite_setColor(img->sprite, color);
	}
	if (sfSprite_getColor(img->sprite).a <= 10) {
		scene->event_tick = &win_scene_tick;
		set_scene_to(frame, GAME, true);
	}
}

void win_scene_tick(frame_t *frame, scene_t *scene)
{
	list_t *list = get_list_by_name(&(scene->sprite_list), "img");
	sprite_info_t *img = list->sprite_inf;
	sfColor color = sfSprite_getColor(img->sprite);

	if (sfSprite_getColor(img->sprite).a >= 240) {
		scene->event_tick = &win_scene_tick2;
		return;
	}
	if (color.a < 255) {
		color.a += 10;
		sfSprite_setColor(img->sprite, color);
	}
}

int init_win_scene(list_t **scene_list, frame_t *frame)
{
	scene_t *intro = create_scene(WIN);
	sfVector2i size = {.x = -1, .y = -1};
	sprite_info_t *sprite = create_sprite(0, size, WIN_ASSET);
	sfColor color = sfSprite_getColor(sprite->sprite);

	intro->background_music = sfMusic_createFromFile(MAIN_MUSIC);
	sprite_set_scale(sprite, 2, 2);
	intro->event_tick = &win_scene_tick;
	color.a = 0;
	sprite_set_pos(sprite, 385, 150);
	sfSprite_setColor(sprite->sprite, color);
	add_sprite_inf(&(intro->sprite_list), sprite, "img");
	add_scene(scene_list, intro);
	return (1);
}
