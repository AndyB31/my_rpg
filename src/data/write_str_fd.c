/*
** EPITECH PROJECT, 2018
** write_str_fd
** File description:
** write_str_fd
*/

#include "my_rpg.h"

int write_str_fd(int fd, char *str)
{
	int size = -1;

	if (fd < 0)
		return (0);
	if (str == NULL) {
		write(fd, &size, sizeof(int));
		return (1);
	}
	size = my_strlen(str);
	write(fd, &size, sizeof(int));
	write(fd, str, my_strlen(str) * sizeof(char));
	return (1);
}
