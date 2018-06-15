/*
** EPITECH PROJECT, 2018
** my_count_char
** File description:
** my_count_char
*/

#include "my.h"

int my_count_char(char const *str, char c)
{
	int nbr = 0;

	for (int i = 0; str[i] != '\0'; i++)
		if (str[i] == c)
			nbr++;
	return (nbr);
}
