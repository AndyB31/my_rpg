/*
** EPITECH PROJECT, 2018
** set_attribute
** File description:
** set_atribute
*/

#include "my_rpg.h"

int set_attribute(item_t *item, enum attribute_type type, \
int value)
{
	if (item->attribute == NULL)
		item->attribute = create_attribute();
	if (type == HEAL && item->attribute)
		item->attribute->heal = value;
	if (type == PA && item->attribute)
		item->attribute->pa = value;
	if (type == HP_ADD && item->attribute)
		item->attribute->hp_add = value;
	if (type == PA_ADD && item->attribute)
		item->attribute->pa_add = value;
	if (type == WATER_ADD && item->attribute)
		item->attribute->water = value;
	if (type == FIRE_ADD && item->attribute)
		item->attribute->fire = value;
	if (type == WIND_ADD && item->attribute)
		item->attribute->wind = value;
	if (type == DIRT_ADD && item->attribute)
		item->attribute->dirt = value;
	return (1);
}
