/*
** EPITECH PROJECT, 2018
** get_item_in_env
** File description:
** get_item_in_env
*/

#include "my_rpg.h"

item_inf_t *get_item_inv_id(inv_t *inv, char *item_name)
{
	list_t *head = inv->head;

	while (head) {
		if (my_are_equals(head->item_inf->id, item_name) == 1)
			return (head->item_inf);
		head = head->next;
	}
	return (NULL);
}

item_inf_t *get_item_inv_slot(inv_t *inv, int id)
{
	list_t *head = NULL;

	if (inv == NULL)
		return (NULL);
	head = inv->head;
	while (head) {
		if (head->item_inf->slot_id == id)
			return (head->item_inf);
		head = head->next;
	}
	return (NULL);
}
