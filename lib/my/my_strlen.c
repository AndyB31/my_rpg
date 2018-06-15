/*
** EPITECH PROJECT, 2017
** my_strlen
** File description:
** thomas.foubert@epitech.eu
*/

#include "my.h"

int my_strlen(char const *str)
{
	int i = 0;

	if (str == NULL)
		return (0);
	for (i = 0; str[i] != '\0'; i++);
	return (i);
}
