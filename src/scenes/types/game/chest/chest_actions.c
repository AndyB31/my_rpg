/*
** EPITECH PROJECT, 2018
** chest_action
** File description:
** chest_action
*/

#include "my_rpg.h"

void click_action_chest_l(int x, int y, frame_t *frame, button_t *button)
{
	int slot_id = my_get_nbr(button->id_name) - 20;
	item_inf_t *item = NULL;
	inv_t *inv = open_player_inventory();
	scene_t *s = get_scene_by_type(&(frame->scene), frame->curent_scene);
	inv_t *chest = read_inventory(frame->curr_chest);

	if (inv == NULL || chest == NULL)
		return;
	item = get_item_inv_slot(chest, slot_id);
	if (item == NULL) {
		free_inventory(chest);
		return;
	}
	if (get_list_length(&(inv->head)) < inv->size_max) {
		add_item_to_inv(inv, item->id, item->nbr, frame);
		delete_item(chest, item, item->nbr, item->slot_id);
	}
	write_inventory(chest);
	free_inventory(chest);
	update_chest(frame, s, frame->curr_chest);
}

void click_action_chest_r(int x, int y, frame_t *frame, button_t *button)
{
	int slot_id = my_get_nbr(button->id_name) - 40;
	item_inf_t *item = NULL;
	inv_t *inv = open_player_inventory();
	scene_t *s = get_scene_by_type(&(frame->scene), frame->curent_scene);
	inv_t *chest = read_inventory(frame->curr_chest);

	if (inv == NULL || chest == NULL)
		return;
	item = get_item_inv_slot(inv, slot_id);
	if (item == NULL) {
		free_inventory(chest);
		return;
	}
	if (get_list_length(&(chest->head)) < chest->size_max) {
		add_item_to_inv(chest, item->id, item->nbr, frame);
		delete_item(inv, item, item->nbr, item->slot_id);
	}
	write_inventory(chest);
	free_inventory(chest);
	update_chest(frame, s, frame->curr_chest);
}

void show_info_chest(int x, int y, frame_t *frame, button_t *button)
{

}