/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** init fight scene
*/

#include "my_rpg.h"

void spell_click(int x, int y, frame_t *frame, button_t *button)
{
	int i = 0;
	scene_t *scene = get_scene_by_type(&(frame->scene),
	frame->curent_scene);
	list_t *sprite = get_list_by_name(&(scene->sprite_list),
	"curr_spell");
	char *path[8] = {S_SWORD, S_WATER, S_EYE, S_WIND, S_FIRE, S_THUNDER,
			S_POTION, S_FIST};
	char *name[8] = {"sword", "water", "eye", "wind", "fire", "thunder",
			"potion", "fist"};

	while (i != 8 && !my_are_equals(button->id_name, name[i]))
		i++;
	if (i != 8) {
		sfTexture_destroy(sprite->sprite_inf->texture);
		sprite->sprite_inf->texture =
		sfTexture_createFromFile(path[i], NULL);
		frame->selected_spell = i;
	}
}

void init_scene_fight2(scene_t *scene)
{
	sfVector2f pos = {.y = 350, .x = 350};
	text_info_t *text = create_text(ASSET_FONT, "-", pos, 100);
	sfColor color = sfRed;
	sfColor colpa = sfBlue;

	color.a = 0;
	colpa.a = 0;
	sfText_setColor(text->text, color);
	add_text_inf(&scene->text_list, text, "mpv");
	pos.y -= 100;
	text = create_text(ASSET_FONT, "-", pos, 100);
	sfText_setColor(text->text, colpa);
	add_text_inf(&scene->text_list, text, "mpa");
	init_life_bar(scene);
	init_pa_bar(scene);
}

void but_f(sfVector2f pos, sfVector2f size, button_t *spell, scene_t *scene)
{
	char *path[8] = {S_SWORD, S_WATER, S_EYE, S_WIND, S_FIRE, S_THUNDER,
			S_POTION, S_FIST};
	char *name[8] = {"sword", "water", "eye", "wind", "fire", "thunder",
			"potion", "fist"};

	for (int i = 0; i < 8; i++) {
		spell = create_button(pos, size);
		set_base_texture(spell, path[i]);
		set_hover_texture(spell, path[i]);
		set_clicked_texture(spell, path[i]);
		spell->click_action = &spell_click;
		spell->hover_action = &spell_hover;
		add_button(&(scene->button_list), spell, name[i]);
		if (pos.x >= 1051 + 87 * 3) {
			pos.y = pos.y + 84;
			pos.x = 1051;
		} else
			pos.x = pos.x + 87;
	}
}

void init_scene_fight(scene_t *scene)
{
	sfVector2f pos = {.y = 200, .x = 200};
	sfVector2f size = {.x = 384, .y = 400};
	sfVector2i s = {.x = -1, .y = -1};
	button_t *mob = create_button(pos, size);
	sprite_info_t *current_spell = create_sprite(0, s, EMPTY);
	sprite_info_t *bar = create_sprite(0, s, BAR_(0));

	sprite_set_scale(bar, 0.5, 0.5);
	sprite_set_pos(bar, 510, 750);
	add_sprite_inf(&scene->sprite_list, bar, "bar");
	set_base_texture(mob, EMPTY);
	set_hover_texture(mob, HOV_MOB);
	set_clicked_texture(mob, EMPTY);
	mob->click_action = &click_on_mob;
	mob->hover_action = &put_color;
	add_button(&(scene->button_list), mob, "mob");
	sprite_set_scale(current_spell, 0.5, 0.5);
	add_sprite_inf(&scene->sprite_list, current_spell, "curr_spell");
	scene->event_mouse_moved = &move_mouse;
}

void init_fight(list_t **scene_list, frame_t *frame)
{
	scene_t *scene = create_scene(FIGHT);
	sfVector2f pos = {.y = 795, .x = 1051};
	sfVector2f size = {.x = 53, .y = 53};
	sfVector2i si = {.x = -1, .y = -1};
	button_t *spell = NULL;
	sprite_info_t *back = create_sprite(0, si, BACK);

	frame->current_spell = -1;
	frame->selected_spell = -1;
	sprite_set_scale(back, 3.99, 3.99);
	sprite_set_pos(back, -300, 0);
	add_sprite_inf(&scene->sprite_list, back, "back");
	scene->event_tick = &update_fight;
	init_scene_fight(scene);
	init_scene_fight2(scene);
	but_f(pos, size, spell, scene);
	scene->event_mouse_button_pressed = &put_empty;
	add_scene(scene_list, scene);
}