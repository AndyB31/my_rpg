/*
** EPITECH PROJECT, 2018
** remove_equiment
** File description:
** remove_equipment
*/

#include "my_rpg.h"

static int remove_equipment2(inv_t *inv, enum item_type type)
{
	if (type == GLOVES && inv->gloves) {
		add_item_to_inv(inv, inv->gloves, 1, NULL);
		if (inv->gloves)
			free(inv->gloves);
		inv->gloves = NULL;
	}
	if (type == SHIELD && inv->shield) {
		add_item_to_inv(inv, inv->shield, 1, NULL);
		if (inv->shield)
			free(inv->shield);
		inv->shield = NULL;
	}
	if (type == WEAPON && inv->weapon) {
		add_item_to_inv(inv, inv->weapon, 1, NULL);
		if (inv->weapon)
			free(inv->weapon);
		inv->weapon = NULL;
	}
	return (1);
}

int remove_equipment(inv_t *inv, enum item_type type)
{
	if (type == HELMET && inv->helmet) {
		add_item_to_inv(inv, inv->helmet, 1, NULL);
		if (inv->helmet)
			free(inv->helmet);
		inv->helmet = NULL;
	}
	if (type == CHESTPLATE && inv->chestplate) {
		add_item_to_inv(inv, inv->chestplate, 1, NULL);
		if (inv->chestplate)
			free(inv->chestplate);
		inv->chestplate = NULL;
	}
	if (type == BOOTS && inv->boots) {
		add_item_to_inv(inv, inv->boots, 1, NULL);
		if (inv->boots)
			free(inv->boots);
		inv->boots = NULL;
	}
	return (remove_equipment2(inv, type));
}