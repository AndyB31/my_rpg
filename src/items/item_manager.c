/*
** EPITECH PROJECT, 2018
** item_manager
** File description:
** item_manager
*/


#include "my_rpg.h"

static int register_items3(frame_t *frame)
{
	return (0);
}

static int register_items2(frame_t *frame)
{
	item_t *item = NULL;

	item = create_item("apple", FOOD, 64, TEX_APPLE);
	add_item(&(frame->item_list), item);
	item = create_item("sword", WEAPON, 1, TEX_SWORD);
	set_attribute(item, FIRE_ADD, 3);
	add_item(&(frame->item_list), item);
	item = create_item("basic_boots", BOOTS, 1, TEX_BASIC_BOOTS);
	set_attribute(item, WATER_ADD, 2);
	set_attribute(item, FIRE_ADD, 2);
	set_attribute(item, WIND_ADD, 2);
	set_attribute(item, DIRT_ADD, 2);
	add_item(&(frame->item_list), item);
	item = create_item("basic_gloves", GLOVES, 1, TEX_BASIC_GLOVES);
	set_attribute(item, WATER_ADD, 2);
	set_attribute(item, FIRE_ADD, 2);
	set_attribute(item, WIND_ADD, 2);
	set_attribute(item, DIRT_ADD, 2);
	add_item(&(frame->item_list), item);
	return (register_items3(frame));
}

int register_items(frame_t *frame)
{
	item_t *item = NULL;

	if (frame == NULL)
		return (0);
	frame->item_list = NULL;
	item = create_item("basic_helmet", HELMET, 1, TEX_BASIC_HELMET);
	set_attribute(item, WATER_ADD, 2);
	set_attribute(item, FIRE_ADD, 2);
	set_attribute(item, WIND_ADD, 2);
	set_attribute(item, DIRT_ADD, 2);
	add_item(&(frame->item_list), item);
	item = create_item("basic_chestplate", CHESTPLATE, 1, TEX_BASIC_CHES);
	set_attribute(item, WATER_ADD, 2);
	set_attribute(item, FIRE_ADD, 2);
	set_attribute(item, WIND_ADD, 2);
	set_attribute(item, DIRT_ADD, 2);
	add_item(&(frame->item_list), item);
	return (register_items2(frame));
}
