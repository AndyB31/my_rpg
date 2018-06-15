/*
** EPITECH PROJECT, 2018
** read_str_fd
** File description:
** read_str_fd
*/

#include "my_rpg.h"

char *read_str_fd(int fd)
{
	int length = 0;
	char *str = NULL;

	if (fd < 0)
		return (NULL);
	if (read(fd, &length, sizeof(int)) == -1)
		return (NULL);
	if (length < 0)
		return (NULL);
	str = malloc((length + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	if (read(fd, str, length * sizeof(char)) == -1)
		return (NULL);
	str[length] = '\0';
	return (str);
}
