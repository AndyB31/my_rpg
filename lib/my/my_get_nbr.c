/*
** EPITECH PROJECT, 2017
** my_getnbr
** File description:
** my_getnbr
*/

#include "my.h"

int my_get_nbr(char const *str)
{
	int neg = 1;
	int result = 0;
	int to_stop = 0;
	int size = 0;
	int mult = 1;

	if (str == NULL || my_is_nbr(str) == 0)
		return (0);
	size = my_strlen(str);
	if (str[0] == '-') {
		neg = -1;
		to_stop = 1;
	}
	for (int i = size - 1; i >= to_stop; i--) {
		result = result + (mult * (str[i] - '0'));
		mult = mult * 10;
	}
	result = result * neg;
	return (result);
}