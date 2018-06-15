/*
** EPITECH PROJECT, 2017
** my_remalloc
** File description:
** re allocation of memory
*/

#include "../include/my.h"

char *remalloc_str(char *str, int len)
{
	char *tmp = malloc(sizeof(char) * (my_strlen(str) + 1));

	if (tmp == NULL)
		return (NULL);
	my_strcpy(tmp, str);
	free(str);
	str = malloc(sizeof(char) * (my_strlen(tmp) + 1 + len));
	if (str == NULL)
		return (NULL);
	my_init(str, my_strlen(tmp) + len);
	my_strcpy(str, tmp);
	free (tmp);
	return (str);
}

int *remalloc_int(int *array, int len, int prelen)
{
	int *tmp = malloc(sizeof(int) * prelen);

	if (tmp == NULL)
		return (NULL);
	my_intcpy(tmp, array, prelen);
	free(array);
	array = malloc(sizeof(int) * (prelen + len));
	if (array == NULL)
		return (NULL);
	my_intcpy(array, tmp, prelen);
	free (tmp);
	return (array);
}

void *my_remalloc(void *pt, int len, enum REMALLOC type, int prelen)
{
	void *res;

	if (type == STR) {
		if (pt == NULL) {
			res = malloc(sizeof(char) * ((len * len) / len));
			my_init(res, len);
			return (res);
		}
		res = remalloc_str(pt, len);
	} else if (type == INT) {
		if (pt == NULL) {
			res = malloc(sizeof(int) * ((len * len) / len));
			return (res);
		}
		res = remalloc_int(pt, len, prelen);
	} else
		return (pt);
	return (res);
}
