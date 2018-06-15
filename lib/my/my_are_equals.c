/*
** EPITECH PROJECT, 2018
** my_are_equals
** File description:
** my_are_equals
*/

#include "my.h"

int my_are_equals(const char *str1, const char *str2)
{
	int size1 = my_strlen(str1);
	int size2 = my_strlen(str2);

	if (str1 == NULL || str2 == NULL)
		return (-1);
	if (size1 != size2)
		return (0);
	for (int i = 0; i < size1; i++) {
		if (str1[i] != str2[i])
			return (0);
	}
	return (1);
}
