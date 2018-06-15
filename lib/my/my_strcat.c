/*
** EPITECH PROJECT, 2017
** my_strcat
** File description:
** thomas.foubert@epitech.eu
*/

#include "my.h"

char *my_strcat(char *dest, char const *src)
{
	int len = 0;
	int j = 0;
	char *tmp = NULL;

	if (dest == NULL || src == NULL)
		return (NULL);
	len = my_strlen(dest);
	tmp = malloc((len + my_strlen(src) + 1) * sizeof(char));
	if (tmp == NULL)
		return (NULL);
	for (int i = 0; dest[i] != '\0'; i++)
		tmp[j++] = dest[i];
	for (int i = 0; src[i] != '\0'; i++)
		tmp[j++] = src[i];
	tmp[j] = '\0';
	return (tmp);
}
