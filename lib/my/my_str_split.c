/*
** EPITECH PROJECT, 2018
** my_str_split
** File description:
** my_str_split
*/

#include "my.h"

static int my_strlen_separator(char const *str, char c, int pass)
{
	int length = my_strlen(str);
	int size = 0;

	for (int i = 0; i < length; i++) {
		if (str[i] == c)
			pass--;
		if (pass > 0)
			continue;
		if (pass < 0)
			break;
		size++;
	}
	return (size);
}

char **my_str_split(char const *str, char c)
{
	int nbr = my_count_char(str, c);
	char **tab = malloc((nbr + 2) * sizeof(char *));
	int x = 0;
	int j = 0;
	int y = 0;

	if (tab == NULL)
		return (NULL);
	for (y = 0; y <= nbr && j < my_strlen(str); y++) {
		if (str[j] == c)
			j++;
		tab[y] = malloc((my_strlen_separator(str, c, y) + 1) \
		* sizeof(char));
		for (x = 0; x < my_strlen_separator(str, c, y) \
		&& str[j] != c; x++)
			tab[y][x] = str[j++];
		tab[y][x] = '\0';
	}
	tab[y] = NULL;
	return (tab);
}
