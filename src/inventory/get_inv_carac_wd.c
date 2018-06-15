/*
** EPITECH PROJECT, 2018
** get_inv_carac
** File description:
** get_inv_carac
*/

#include "my_rpg.h"

static int get_inv_wind2(frame_t *frame, inv_t *inv, int wind)
{
	item_t *curr = NULL;

	curr = get_item_by_id(&(frame->item_list), inv->weapon);
	if (curr && curr->attribute)
		wind += curr->attribute->wind;
	free_inventory(inv);
	return (wind);
}

int get_inv_wind(frame_t *frame)
{
	inv_t *inv = read_inventory("player_inv.data");
	item_t *curr = NULL;
	int wind = 0;

	curr = get_item_by_id(&(frame->item_list), inv->helmet);
	if (curr && curr->attribute)
		wind += curr->attribute->wind;
	curr = get_item_by_id(&(frame->item_list), inv->chestplate);
	if (curr && curr->attribute)
		wind += curr->attribute->wind;
	curr = get_item_by_id(&(frame->item_list), inv->shield);
	if (curr && curr->attribute)
		wind += curr->attribute->wind;
	curr = get_item_by_id(&(frame->item_list), inv->boots);
	if (curr && curr->attribute)
		wind += curr->attribute->wind;
	curr = get_item_by_id(&(frame->item_list), inv->gloves);
	if (curr && curr->attribute)
		wind += curr->attribute->wind;
	return (get_inv_wind2(frame, inv, wind));
}

static int get_inv_dirt2(frame_t *frame, inv_t *inv, int dirt)
{
	item_t *curr = NULL;

	curr = get_item_by_id(&(frame->item_list), inv->weapon);
	if (curr && curr->attribute)
		dirt += curr->attribute->dirt;
	free_inventory(inv);
	return (dirt);
}

int get_inv_dirt(frame_t *frame)
{
	inv_t *inv = read_inventory("player_inv.data");
	item_t *curr = NULL;
	int dirt = 0;

	curr = get_item_by_id(&(frame->item_list), inv->helmet);
	if (curr && curr->attribute)
		dirt += curr->attribute->dirt;
	curr = get_item_by_id(&(frame->item_list), inv->chestplate);
	if (curr && curr->attribute)
		dirt += curr->attribute->dirt;
	curr = get_item_by_id(&(frame->item_list), inv->shield);
	if (curr && curr->attribute)
		dirt += curr->attribute->dirt;
	curr = get_item_by_id(&(frame->item_list), inv->boots);
	if (curr && curr->attribute)
		dirt += curr->attribute->dirt;
	curr = get_item_by_id(&(frame->item_list), inv->gloves);
	if (curr && curr->attribute)
		dirt += curr->attribute->dirt;
	return (get_inv_dirt2(frame, inv, dirt));
}