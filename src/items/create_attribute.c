/*
** EPITECH PROJECT, 2018
** create_attribute
** File description:
** create_attribute
*/

#include "my_rpg.h"

attributes_t *create_attribute(void)
{
	attributes_t *attribute = malloc(sizeof(attributes_t));

	if (attribute == NULL)
		return (NULL);
	attribute->heal = 0;
	attribute->pa = 0;
	attribute->hp_add = 0;
	attribute->pa_add = 0;
	attribute->water = 0;
	attribute->fire = 0;
	attribute->wind = 0;
	attribute->dirt = 0;
	return (attribute);
}
