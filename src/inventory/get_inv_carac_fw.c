/*
** EPITECH PROJECT, 2018
** get_inv_carac
** File description:
** get_inv_carac
*/

#include "my_rpg.h"

static int get_inv_water2(frame_t *frame, inv_t *inv, int water)
{
	item_t *curr = NULL;

	curr = get_item_by_id(&(frame->item_list), inv->weapon);
	if (curr && curr->attribute)
		water += curr->attribute->water;
	free_inventory(inv);
	return (water);
}

int get_inv_water(frame_t *frame)
{
	inv_t *inv = read_inventory("player_inv.data");
	item_t *curr = NULL;
	int water = 0;

	curr = get_item_by_id(&(frame->item_list), inv->helmet);
	if (curr && curr->attribute)
		water += curr->attribute->water;
	curr = get_item_by_id(&(frame->item_list), inv->chestplate);
	if (curr && curr->attribute)
		water += curr->attribute->water;
	curr = get_item_by_id(&(frame->item_list), inv->shield);
	if (curr && curr->attribute)
		water += curr->attribute->water;
	curr = get_item_by_id(&(frame->item_list), inv->boots);
	if (curr && curr->attribute)
		water += curr->attribute->water;
	curr = get_item_by_id(&(frame->item_list), inv->gloves);
	if (curr && curr->attribute)
		water += curr->attribute->water;
	return (get_inv_water2(frame, inv, water));
}

static int get_inv_fire2(frame_t *frame, inv_t *inv, int fire)
{
	item_t *curr = NULL;

	curr = get_item_by_id(&(frame->item_list), inv->weapon);
	if (curr && curr->attribute)
		fire += curr->attribute->fire;
	free_inventory(inv);
	return (fire);
}

int get_inv_fire(frame_t *frame)
{
	inv_t *inv = read_inventory("player_inv.data");
	item_t *curr = NULL;
	int fire = 0;

	curr = get_item_by_id(&(frame->item_list), inv->helmet);
	if (curr && curr->attribute)
		fire += curr->attribute->fire;
	curr = get_item_by_id(&(frame->item_list), inv->chestplate);
	if (curr && curr->attribute)
		fire += curr->attribute->fire;
	curr = get_item_by_id(&(frame->item_list), inv->shield);
	if (curr && curr->attribute)
		fire += curr->attribute->fire;
	curr = get_item_by_id(&(frame->item_list), inv->boots);
	if (curr && curr->attribute)
		fire += curr->attribute->fire;
	curr = get_item_by_id(&(frame->item_list), inv->gloves);
	if (curr && curr->attribute)
		fire += curr->attribute->fire;
	return (get_inv_fire2(frame, inv, fire));
}