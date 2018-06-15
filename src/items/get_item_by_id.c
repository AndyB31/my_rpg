/*
** EPITECH PROJECT, 2018
** get_item_by_id
** File description:
** get_item_by_id
*/

#include "my_rpg.h"

item_t *get_item_by_id(list_t **head, char *id)
{
	list_t *curr = *head;

	while (curr) {
		if (my_are_equals(curr->item->id, id) == 1)
			return (curr->item);
		curr = curr->next;
	}
	return (NULL);
}
