/*
** EPITECH PROJECT, 2018
** read_value_file
** File description:
** read_value_file
*/

#include "my_rpg.h"

static int free_2d_tab(char **tab)
{
	for (int i = 0; tab[i]; i++) {
		free(tab[i]);
	}
	free(tab);
	return (0);
}

char *read_value_file(char *path, char *key)
{
	FILE *stream = fopen(path, "r");
	char *str = NULL;
	char **tab = NULL;
	char *tmp = NULL;
	size_t len = 0;

	if (stream == NULL)
		return (NULL);
	while (getline(&str, &len, stream) != -1) {
		str[my_strlen(str) - 1] = '\0';
		tab = my_str_split(str, '=');
		free(str);
		str = NULL;
		if (my_are_equals(tab[0], key)) {
			tmp = malloc((my_strlen(tab[1]) + 1) * sizeof(char));
			tmp = my_strcpy(tmp, tab[1]);
			free_2d_tab(tab);
			fclose(stream);
			return (tmp);
		}
		free_2d_tab(tab);
	}
	fclose(stream);
	return (NULL);
}
