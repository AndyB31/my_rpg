/*
** EPITECH PROJECT, 2018
** set_str_to
** File description:
** set_str_to
*/

#include "my_rpg.h"

char *set_str_to(char *src, char *new_str)
{
	if (src)
		free(src);
	src = malloc((my_strlen(new_str) + 1) * sizeof(char));
	if (src == NULL)
		return (NULL);
	src = my_strcpy(src, new_str);
	return (src);
}