/*
** EPITECH PROJECT, 2018
** open_player_inventory
** File description:
** open_player_inventory
*/

#include "my_rpg.h"

inv_t *open_player_inventory(void)
{
	static inv_t *inventory = NULL;

	if (inventory == NULL)
		inventory = read_inventory("player_inv.data");
	return (inventory);
}