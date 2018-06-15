/*
** EPITECH PROJECT, 2018
** inventory_manager
** File description:
** inventory_manage
*/

#include "my_rpg.h"

static int create_test_inventory(frame_t *frame)
{
	inv_t *inv = NULL;

	if (is_file_in_dir("test.data", "./data/inventory/") == 0) {
		inv = create_inventory("test.data", 14);
		add_item_to_inv(inv, "sword", 2, frame);
		add_item_to_inv(inv, "basic_helmet", 1, frame);
		add_item_to_inv(inv, "basic_chestplate", 1, frame);
		add_item_to_inv(inv, "basic_boots", 1, frame);
		add_item_to_inv(inv, "basic_gloves", 1, frame);
		write_inventory(inv);
		free_inventory(inv);
		my_putstr("Chest test has been created !\n");
	}
	return (0);
}

int register_inventory(frame_t *frame)
{
	inv_t *inv = NULL;
	item_t *it = NULL;

	if (is_file_in_dir("player_inv.data", "./data/inventory/") == 0) {
		inv = create_inventory("player_inv.data", 14);
		add_item_to_inv(inv, "apple", 64, frame);
		add_item_to_inv(inv, "sword", 5, frame);
		add_item_to_inv(inv, "basic_helmet", 1, frame);
		it = get_item_by_id(&(frame->item_list), "basic_chestplate");
		set_equipement(inv, it, CHESTPLATE, true);
		write_inventory(inv);
		free_inventory(inv);
		my_putstr("The player's inventory has been created !\n");
	}
	create_test_inventory(frame);
	my_putstr("All inventory have been created !\n");
	return (1);
}
