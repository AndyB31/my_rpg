/*
** EPITECH PROJECT, 2017
** my_putstr
** File description:
** Day03 task02
*/

#include <unistd.h>

int my_strlen(char const *);

int my_putstr(char const *str)
{
	int len = my_strlen(str);

	write(1, str, len);
	return (0);
}
