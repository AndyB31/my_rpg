/*
** EPITECH PROJECT, 2018
** delete_item
** File description:
** delete_item
*/

#include "my_rpg.h"

static int delete_bad_items(inv_t *inv)
{
	list_t *curr = inv->head;

	if (curr->item_inf->nbr <= 0) {
		inv->head = curr->next;
		return (1);
	}
	for (int i = 0; curr != NULL; i++) {
		if (curr->next && curr->next->item_inf->nbr <= 0) {
			curr->next = curr->next->next;
			return (1);
		}
		curr = curr->next;
	}
	return (1);
}

int delete_item(inv_t *inv, item_inf_t *id, int nbr, int slot_id)
{
	item_inf_t *item = NULL;

	if (slot_id < 0)
		item = get_item_inv_id(inv, id->id);
	else
		item = get_item_inv_slot(inv, slot_id);
	if (item == NULL)
		return (0);
	item->nbr -= nbr;
	if (item->nbr < 0)
		delete_item(inv, item, (-1 * item->nbr), -1);
	delete_bad_items(inv);
	return (1);
}
