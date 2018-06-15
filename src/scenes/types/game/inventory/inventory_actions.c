/*
** EPITECH PROJECT, 2018
** inventory_actions
** File description:
** inventory_actions
*/

#include "my_rpg.h"

void click_action_armor(int x, int y, frame_t *frame, button_t *button)
{
	inv_t *inv = open_player_inventory();
	scene_t *s = get_scene_by_type(&(frame->scene), frame->curent_scene);

	if (inv == NULL || s == NULL)
		return;
	if (get_list_length(&(inv->head)) > inv->size_max)
		return;
	if (my_are_equals(button->id_name, "shield"))
		remove_equipment(inv, SHIELD);
	if (my_are_equals(button->id_name, "helmet"))
		remove_equipment(inv, HELMET);
	if (my_are_equals(button->id_name, "boots"))
		remove_equipment(inv, BOOTS);
	if (my_are_equals(button->id_name, "gloves"))
		remove_equipment(inv, GLOVES);
	if (my_are_equals(button->id_name, "chestplate"))
		remove_equipment(inv, CHESTPLATE);
	if (my_are_equals(button->id_name, "sword"))
		remove_equipment(inv, WEAPON);
	update_inventory(frame, s);
}

void click_action_inventory(int x, int y, frame_t *frame, button_t *button)
{
	inv_t *inv = open_player_inventory();
	int slot_id = my_get_nbr(button->id_name);
	item_inf_t *item = NULL;
	item_t *real_item = NULL;
	scene_t *s = get_scene_by_type(&(frame->scene), frame->curent_scene);

	if (inv == NULL || s == NULL)
		return;
	item = get_item_inv_slot(inv, slot_id);
	if (item == NULL)
		return;
	real_item = get_item_by_id(&(frame->item_list), item->id);
	if (set_equipement(inv, real_item, real_item->type, false) == 1)
		delete_item(inv, item, 1, item->slot_id);
	update_inventory(frame, s);
}