/*
** EPITECH PROJECT, 2018
** write_player
** File description:
** write_player
*/

#include "my_rpg.h"

static int write_player2(player_t *player, int fd)
{
	write_nbr_fd(fd, player->pa_max);
	write_nbr_fd(fd, player->pv_max);
	write_nbr_fd(fd, player->where);
	write_nbr_fd(fd, player->where_old);
	close(fd);
	return (0);
}

int write_player(player_t *player)
{
	int fd = -1;

	if (player == NULL)
		return (1);
	fd = open("./data/player.data", O_RDWR | O_CREAT | O_TRUNC, \
	S_IRWXU | S_IRWXG | S_IRWXO);
	if (fd < 0)
		return (1);
	write_nbr_fd(fd, player->pos.x);
	write_nbr_fd(fd, player->pos.y);
	write_nbr_fd(fd, player->dirt);
	write_nbr_fd(fd, player->wind);
	write_nbr_fd(fd, player->fire);
	write_nbr_fd(fd, player->water);
	write_nbr_fd(fd, player->magic);
	write_nbr_fd(fd, player->xp);
	write_nbr_fd(fd, player->lvl);
	write_nbr_fd(fd, player->pa);
	write_nbr_fd(fd, player->pv);
	return (write_player2(player, fd));
}