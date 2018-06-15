/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** init fight scene
*/

#include "my_rpg.h"

void init_pa_bar(scene_t *scene)
{
	sfVector2i size = {.y = -1, .x = -1};
	sprite_info_t *bar = create_sprite(0, size, PA_E);
	sprite_info_t *bar_full = create_sprite(0, size, PA_F);
	sprite_info_t *describe = create_sprite(0, size, EMPTY);

	init_esc_button(scene);
	sprite_set_pos(bar, 1400, 640);
	sprite_set_pos(describe, 543, 793);
	sprite_set_scale(describe, 0.5, 0.5);
	add_sprite_inf(&scene->sprite_list, describe, "describe");
	sprite_set_pos(bar_full, 1400, 640);
	add_sprite_inf(&scene->sprite_list, bar, "pa_empty");
	add_sprite_inf(&scene->sprite_list, bar_full, "pa_full");
}

void init_player(frame_t *frame)
{
	sfVector2i size = {24, 24};

	frame->player->sprite = create_sprite(9, size, ASSET_PLAYER);
	frame->player->sprite->current_state = 4;
	frame->player->sprite->tick_max = 10000;
	frame->mob = malloc(sizeof(mob_t *));
	frame->mob[0] = malloc(sizeof(mob_t));
	frame->mob[0]->texture = MOB1;
	frame->mob[0]->pv = 400;
	frame->mob[0]->pv_max = 400;
	frame->mob[0]->pa = 8;
	frame->mob[0]->px_get = 10;
}

void spell_hover(int x, int y, frame_t *frame, button_t *button)
{
	char *path[8] = {D_SWORD, D_WATER, D_EYE, D_WIND, D_FIRE, D_THUNDER,
			D_POTION, D_FIST};
	char *name[8] = {"sword", "water", "eye", "wind", "fire", "thunder",
			"potion", "fist"};
	scene_t *scene = get_scene_by_type(&frame->scene, FIGHT);
	int i = 0;
	list_t *desc = get_list_by_name(&scene->sprite_list, "describe");

	while (name[i] && !my_strcmp2(name[i], button->id_name))
		i++;
	if (name[i] == NULL)
		return;
	sfTexture_destroy(desc->sprite_inf->texture);
	desc->sprite_inf->texture = sfTexture_createFromFile(path[i], NULL);
}
