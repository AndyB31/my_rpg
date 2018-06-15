/*
** EPITECH PROJECT, 2018
** add_item_to_inv2
** File description:
** add_item_to_inv2
*/

#include "my_rpg.h"

int get_slot_id(inv_t *inv)
{
	item_inf_t *item = NULL;

	for (int i = 1; i <= inv->size_max; i++) {
		item = get_item_inv_slot(inv, i);
		if (item == NULL)
			return (i);
	}
	return (-1);
}

item_inf_t *can_add_item(inv_t *inv, char *id, int nbr, frame_t *f)
{
	list_t *curr = NULL;
	int stack_size = 0;
	item_t *item = NULL;

	if (inv == NULL || f == NULL)
		return (NULL);
	curr = inv->head;
	while (curr) {
		stack_size = curr->item_inf->nbr;
		item = get_item_by_id(&(f->item_list), id);
		if (my_are_equals(curr->item_inf->id, id)) {
			if (stack_size >= item->stack_size) {
				curr = curr->next;
				continue;
			}
			return (curr->item_inf);
		}
		curr = curr->next;
	}
	return (NULL);
}