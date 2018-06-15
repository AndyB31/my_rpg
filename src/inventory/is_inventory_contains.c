/*
** EPITECH PROJECT, 2018
** is_inventory_contains
** File description:
** is_inventory_contains
*/

#include "my_rpg.h"

bool is_inventory_contains(inv_t *inv, char *item_name)
{
	list_t *head = inv->head;

	while (head) {
		if (my_are_equals(head->item_inf->id, item_name) == 1)
			return (true);
		head = head->next;
	}
	return (false);
}
