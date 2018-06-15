/*
** EPITECH PROJECT, 2018
** read_nbr_fd
** File description:
** read_nbr_fd
*/

#include "my_rpg.h"

int read_nbr_fd(int fd)
{
	int nbr = 0;

	if (fd < 0)
		return (0);
	if (read(fd, &nbr, sizeof(int)) == -1)
		return (0);
	return (nbr);
}
