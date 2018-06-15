/*
** EPITECH PROJECT, 2018
** set_equipement
** File description:
** set_equipement
*/

#include "my_rpg.h"

int set_shield(inv_t *inv, item_t *item, bool force)
{
	if (inv == NULL || item == NULL)
		return (0);
	if (item->type != SHIELD && force == false)
		return (0);
	if (inv->shield) {
		add_item_to_inv(inv, inv->shield, 1, NULL);
		free(inv->shield);
	}
	inv->shield = malloc((my_strlen(item->id) + 1) * sizeof(char));
	inv->shield = my_strcpy(inv->shield, item->id);
	return (1);
}

int set_equipement(inv_t *inv, item_t *item, enum item_type type, bool force)
{
	if (type == WEAPON)
		return (set_weapon(inv, item, force));
	if (type == HELMET)
		return (set_helmet(inv, item, force));
	if (type == BOOTS)
		return (set_boots(inv, item, force));
	if (type == CHESTPLATE)
		return (set_chestplate(inv, item, force));
	if (type == GLOVES)
		return (set_gloves(inv, item, force));
	if (type == SHIELD)
		return (set_shield(inv, item, force));
	return (0);
}
