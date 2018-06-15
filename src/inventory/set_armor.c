/*
** EPITECH PROJECT, 2018
** set_armor
** File description:
** set_armor
*/

#include "my_rpg.h"

int set_weapon(inv_t *inv, item_t *item, bool force)
{
	if (inv == NULL || item == NULL)
		return (0);
	if (item->type != WEAPON && force == false)
		return (0);
	if (inv->weapon) {
		add_item_to_inv(inv, inv->weapon, 1, NULL);
		free(inv->weapon);
	}
	inv->weapon = malloc((my_strlen(item->id) + 1) * sizeof(char));
	inv->weapon = my_strcpy(inv->weapon, item->id);
	return (1);
}

int set_helmet(inv_t *inv, item_t *item, bool force)
{
	if (inv == NULL || item == NULL)
		return (0);
	if (item->type != HELMET && force == false)
		return (0);
	if (inv->helmet) {
		add_item_to_inv(inv, inv->helmet, 1, NULL);
		free(inv->helmet);
	}
	inv->helmet = malloc((my_strlen(item->id) + 1) * sizeof(char));
	inv->helmet = my_strcpy(inv->helmet, item->id);
	return (1);
}

int set_boots(inv_t *inv, item_t *item, bool force)
{
	if (inv == NULL || item == NULL)
		return (0);
	if (item->type != BOOTS && force == false)
		return (0);
	if (inv->boots) {
		add_item_to_inv(inv, inv->boots, 1, NULL);
		free(inv->boots);
	}
	inv->boots = malloc((my_strlen(item->id) + 1) * sizeof(char));
	inv->boots = my_strcpy(inv->boots, item->id);
	return (1);
}

int set_chestplate(inv_t *inv, item_t *item, bool force)
{
	if (inv == NULL || item == NULL)
		return (0);
	if (item->type != CHESTPLATE && force == false)
		return (0);
	if (inv->chestplate) {
		add_item_to_inv(inv, inv->chestplate, 1, NULL);
		free(inv->chestplate);
	}
	inv->chestplate = malloc((my_strlen(item->id) + 1) * sizeof(char));
	inv->chestplate = my_strcpy(inv->chestplate, item->id);
	return (1);
}

int set_gloves(inv_t *inv, item_t *item, bool force)
{
	if (inv == NULL || item == NULL)
		return (0);
	if (item->type != GLOVES && force == false)
		return (0);
	if (inv->gloves) {
		add_item_to_inv(inv, inv->gloves, 1, NULL);
		free(inv->gloves);
	}
	inv->gloves = malloc((my_strlen(item->id) + 1) * sizeof(char));
	inv->gloves = my_strcpy(inv->gloves, item->id);
	return (1);
}
