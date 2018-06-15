/*
** EPITECH PROJECT, 2018
** get_nbr_of_items
** File description:
** get_nbr_of_items
*/

#include "my_rpg.h"

int get_nbr_of_items(inv_t *inv, char *item_name)
{
	list_t *head = inv->head;

	while (head) {
		if (my_are_equals(head->item_inf->id, item_name) == 1)
			return (head->item_inf->nbr);
		head = head->next;
	}
	return (0);
}
