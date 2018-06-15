/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** init fight scene
*/

#include "my_rpg.h"

void esc_hover(int x, int y, frame_t *frame, button_t *button)
{
	scene_t *scene = get_scene_by_type(&frame->scene, FIGHT);
	list_t *desc = get_list_by_name(&scene->sprite_list, "describe");

	sfTexture_destroy(desc->sprite_inf->texture);
	desc->sprite_inf->texture = sfTexture_createFromFile(ESC_D, NULL);
}

void esc_click(int x, int y, frame_t *frame, button_t *button)
{
	frame->player->pv = 0;
	set_scene_to(frame, LOSE, true);
}

void init_esc_button(scene_t *scene)
{
	sfVector2f pos = {.y = 815, .x = 910};
	sfVector2f b_size = {.y = 100, .x = 100};
	sfVector2i size = {.y = 100, .x = 96};
	button_t *escape = create_button(pos, b_size);
	sprite_info_t *mob = create_sprite(4, size, MOB1);

	sprite_set_pos(mob, 200, 200);
	sprite_set_scale(mob, 4, 4);
	mob->tick_max = 3;
	add_sprite_inf(&scene->sprite_list, mob, "mob");
	set_base_texture(escape, ESC_B);
	set_hover_texture(escape, ESC_H);
	set_clicked_texture(escape, ESC_C);
	escape->click_action = &esc_click;
	escape->hover_action = &esc_hover;
	add_button(&scene->button_list, escape, "esc");
}