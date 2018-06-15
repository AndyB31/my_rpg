/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** bar_from_number
*/

#include "my_rpg.h"

char *bar_from_number(int x)
{
	char *tab[12] = {BAR_0, BAR_1, BAR_2, BAR_3, BAR_4, BAR_5, BAR_6,
			BAR_7, BAR_8, BAR_9, BAR_10, 0};

	if (x > 10 || x < 0)
		return (NULL);
	return (tab[x]);
}