/*
** EPITECH PROJECT, 2018
** game_actions.c
** File description:
** game action
*/

#include "my_rpg.h"

void bag_button_action(int x, int y, frame_t *frame, button_t *button)
{
	scene_t *s = get_scene_by_type(&(frame->scene), frame->curent_scene);

	change_inventory_status(frame, s);
}

void game_plus_button(int x, int y, frame_t *frame, button_t *button)
{
	scene_t *scene = get_scene_by_type(&(frame->scene),
	frame->curent_scene);
	list_t *gear = get_list_by_name(&(scene->button_list), "gear_b");
	list_t *bag = get_list_by_name(&(scene->button_list), "bag_b");
	list_t *dna = get_list_by_name(&(scene->button_list), "dna_b");
	list_t *tree = get_list_by_name(&(scene->button_list), "tree_b");
	list_t *book = get_list_by_name(&(scene->button_list), "book_b");
	list_t *tools = get_list_by_name(&(scene->sprite_list), "tools");

	change_status_button(gear->button);
	change_status_button(bag->button);
	change_status_button(dna->button);
	change_status_button(tree->button);
	change_status_button(book->button);
	change_status_sprite(tools->sprite_inf);
	change_texture(button);
}

void change_texture(button_t *button)
{
	static int active = 1;

	active *= -1;
	if (active == 1) {
		set_base_texture(button, ASSET_PLUS);
		set_clicked_texture(button, ASSET_PLUS);
		set_hover_texture(button, ASSET_PLUS);
	} else {
		set_base_texture(button, ASSET_MINUS);
		set_clicked_texture(button, ASSET_MINUS);
		set_hover_texture(button, ASSET_MINUS);
	}
}

void change_status_button(button_t *button)
{
	if (button->enabled == true)
		button->enabled = false;
	else
		button->enabled = true;
}

void change_status_sprite(sprite_info_t *sprite)
{
	if (sprite->enabled == true)
		sprite->enabled = false;
	else
		sprite->enabled = true;
}
