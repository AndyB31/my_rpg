/*
** EPITECH PROJECT, 2018
** write_nbr_fd
** File description:
** write_nbr_fd
*/

#include "my_rpg.h"

int write_nbr_fd(int fd, int nbr)
{
	if (fd < 0)
		return (0);
	write(fd, &nbr, sizeof(int));
	return (1);
}
