/*
** EPITECH PROJECT, 2018
** init_item_inf
** File description:
** init_item_inf
*/

#include "my_rpg.h"

item_inf_t *init_item_inf(char *id, int stack_size, int slot_id)
{
	item_inf_t *item_inf = malloc(sizeof(item_inf_t));

	if (item_inf == NULL)
		return (0);
	item_inf->id = malloc((my_strlen(id) + 1) * sizeof(char));
	if (item_inf->id == NULL) {
		free(item_inf);
		return (NULL);
	}
	item_inf->id = my_strcpy(item_inf->id, id);
	item_inf->nbr = stack_size;
	item_inf->slot_id = slot_id;
	return (item_inf);
}