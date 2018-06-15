/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** init fight scene
*/

#include "my_rpg.h"

void init_life_bar(scene_t *scene)
{
	sfVector2i size = {.y = -1, .x = -1};
	sfVector2i size2 = {.y = 24, .x = 24};
	sprite_info_t *bar = create_sprite(0, size, LIFE_E);
	sprite_info_t *bar_full = create_sprite(0, size, LIFE_F);
	sprite_info_t *player = create_sprite(1, size2, ASSET_PLAYER);

	player->vertical_state = 3;
	sprite_set_pos(player, 1400, 450);
	sprite_set_scale(player, 4.7, 4.7);
	add_sprite_inf(&scene->sprite_list, player, "player");
	sprite_set_pos(bar, 350, 600);
	sprite_set_pos(bar_full, 350, 600);
	add_sprite_inf(&scene->sprite_list, bar, "bar_empty");
	add_sprite_inf(&scene->sprite_list, bar_full, "bar_full");
	bar = create_sprite(0, size, LIFE_E);
	bar_full = create_sprite(0, size, LIFE_F);
	sprite_set_pos(bar, 1400, 600);
	sprite_set_pos(bar_full, 1400, 600);
	add_sprite_inf(&scene->sprite_list, bar, "life_empty");
	add_sprite_inf(&scene->sprite_list, bar_full, "life_full");
}

void click_on_mob(int x, int y, frame_t *frame, button_t *button)
{
	int (*spell_effect[8])(frame_t *frame, button_t *button) = {
		&spell_sword, &spell_water, &spell_eye, &spell_wind,
		&spell_fire, &spell_thunder, &spell_pot, &spell_fist
	};
	int ret = 0;

	if (frame->current_spell == -1)
		return;
	ret = (*spell_effect[frame->current_spell])(frame, button);
	if (ret == NOT_ENOUGHT_PA)
		my_printf("Not enought pa !\n\n");
	my_printf("pv mob: %d\n\n", frame->mob[0]->pv);
	frame->current_spell = -1;
}

void put_color(int x, int y, frame_t *frame, button_t *button)
{
	if (frame->selected_spell != -1)
		frame->current_spell = frame->selected_spell;
}

void put_empty(sfMouseButtonEvent event, frame_t *frame)
{
	scene_t *scene = get_scene_by_type(&(frame->scene),
	frame->curent_scene);
	list_t *sprite = get_list_by_name(&(scene->sprite_list),
	"curr_spell");

	sfTexture_destroy(sprite->sprite_inf->texture);
	sprite->sprite_inf->texture = sfTexture_createFromFile(EMPTY, NULL);
	frame->selected_spell = -1;
}

void move_mouse(sfMouseMoveEvent event, frame_t *frame)
{
	scene_t *scene = get_scene_by_type(&(frame->scene),
	frame->curent_scene);
	list_t *sprite = get_list_by_name(&(scene->sprite_list),
	"curr_spell");

	sprite_set_pos(sprite->sprite_inf, event.x, event.y);
}