/*
** EPITECH PROJECT, 2018
** get_inv_carac
** File description:
** get_inv_carac
*/

#include "my_rpg.h"

static int get_inv_hp2(frame_t *frame, inv_t *inv, int hp)
{
	item_t *curr = NULL;

	curr = get_item_by_id(&(frame->item_list), inv->weapon);
	if (curr && curr->attribute)
		hp += curr->attribute->hp_add;
	free_inventory(inv);
	return (hp);
}

int get_inv_hp(frame_t *frame)
{
	inv_t *inv = read_inventory("player_inv.data");
	item_t *curr = NULL;
	int hp = 0;

	curr = get_item_by_id(&(frame->item_list), inv->helmet);
	if (curr && curr->attribute)
		hp += curr->attribute->hp_add;
	curr = get_item_by_id(&(frame->item_list), inv->chestplate);
	if (curr && curr->attribute)
		hp += curr->attribute->hp_add;
	curr = get_item_by_id(&(frame->item_list), inv->shield);
	if (curr && curr->attribute)
		hp += curr->attribute->hp_add;
	curr = get_item_by_id(&(frame->item_list), inv->boots);
	if (curr && curr->attribute)
		hp += curr->attribute->hp_add;
	curr = get_item_by_id(&(frame->item_list), inv->gloves);
	if (curr && curr->attribute)
		hp += curr->attribute->hp_add;
	return (get_inv_hp2(frame, inv, hp));
}

static int get_inv_pa2(frame_t *frame, inv_t *inv, int pa)
{
	item_t *curr = NULL;

	curr = get_item_by_id(&(frame->item_list), inv->weapon);
	if (curr && curr->attribute)
		pa += curr->attribute->pa_add;
	free_inventory(inv);
	return (pa);
}

int get_inv_pa(frame_t *frame)
{
	inv_t *inv = read_inventory("player_inv.data");
	item_t *curr = NULL;
	int pa = 0;

	curr = get_item_by_id(&(frame->item_list), inv->helmet);
	if (curr && curr->attribute)
		pa += curr->attribute->pa_add;
	curr = get_item_by_id(&(frame->item_list), inv->chestplate);
	if (curr && curr->attribute)
		pa += curr->attribute->pa_add;
	curr = get_item_by_id(&(frame->item_list), inv->shield);
	if (curr && curr->attribute)
		pa += curr->attribute->pa_add;
	curr = get_item_by_id(&(frame->item_list), inv->boots);
	if (curr && curr->attribute)
		pa += curr->attribute->pa_add;
	curr = get_item_by_id(&(frame->item_list), inv->gloves);
	if (curr && curr->attribute)
		pa += curr->attribute->pa_add;
	return (get_inv_pa2(frame, inv, pa));
}