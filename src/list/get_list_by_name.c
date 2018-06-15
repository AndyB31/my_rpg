/*
** EPITECH PROJECT, 2018
** get_list_by_name
** File description:
** get_list_by_name
*/

#include "my_rpg.h"

list_t *get_list_by_name(list_t **head, char *id_name)
{
	list_t *curr = *head;

	while (curr) {
		if (my_are_equals(curr->id_name, id_name))
			return (curr);
		curr = curr->next;
	}
	return (NULL);
}
