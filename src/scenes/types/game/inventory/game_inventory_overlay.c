/*
** EPITECH PROJECT, 2018
** game_inventory_overlay
** File description:
** game_inventory_overlay
*/

#include "my_rpg.h"

static int reset_inv_b_s(scene_t *scene, list_t *tmp)
{
	char *id = NULL;
	list_t *slot = NULL;

	for (int i = 1; i <= 14; i++) {
		id = my_nbr_to_str(i);
		slot = get_list_by_name(&(scene->button_list), id);
		free(id);
		if (slot == NULL)
			continue;
		set_bhc_texture(slot->button, ASSET_N);
	}
	for (int i = 0; i < 14; i++) {
		id = my_nbr_to_str(66 + i);
		tmp = get_list_by_name(&(scene->text_list), id);
		free(id);
		if (tmp == NULL)
			continue;
		sfText_setString(tmp->text_inf->text, "");
	}
	return (1);
}

static int modify_button_texture(list_t *item, list_t *b, scene_t *scene, \
item_t *item2)
{
	char *id = NULL;
	list_t *tmp = NULL;

	id = my_nbr_to_str(item->item_inf->slot_id);
	b = get_list_by_name(&(scene->button_list), id);
	if (item2 == NULL || b == NULL)
		return (1);
	id = my_nbr_to_str(65 + item->item_inf->slot_id);
	tmp = get_list_by_name(&(scene->text_list), id);
	free(id);
	id = my_nbr_to_str(item->item_inf->nbr);
	sfText_setString(tmp->text_inf->text, id);
	free(id);
	set_bhc_texture(b->button, item2->texture_path);
	return (0);
}

int update_inventory(frame_t *frame, scene_t *scene)
{
	inv_t *inv = open_player_inventory();
	list_t *item = NULL;
	item_t *it2 = NULL;
	list_t *tmp = NULL;

	if (inv == NULL)
		return (1);
	reset_inv_b_s(scene, tmp);
	reset_armor_inv(scene, inv, frame);
	item = inv->head;
	for (int i = 0; item && i < get_list_length(&(inv->head));) {
		it2 = get_item_by_id(&(frame->item_list), item->item_inf->id);
		if (modify_button_texture(item, tmp, scene, it2) == 1) {
			item = item->next;
			continue;
		}
		i++;
		item = item->next;
	}
	return (1);
}
