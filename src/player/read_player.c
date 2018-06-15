/*
** EPITECH PROJECT, 2018
** read_player
** File description:
** read_player
*/

#include "my_rpg.h"

static player_t *read_player2(player_t *player, int fd)
{
	player->pa = read_nbr_fd(fd);
	player->pv = read_nbr_fd(fd);
	player->pa_max = read_nbr_fd(fd);
	player->pv_max = read_nbr_fd(fd);
	player->where = read_nbr_fd(fd);
	player->where_old = read_nbr_fd(fd);
	close(fd);
	return (player);
}

player_t *read_player(void)
{
	int fd = -1;
	player_t *player = NULL;

	fd = open("./data/player.data", O_RDWR | O_CREAT, \
	S_IRWXU | S_IRWXG | S_IRWXO);
	if (fd < 0)
		return (NULL);
	player = create_player();
	if (player == NULL)
		return (NULL);
	player->pos.x = read_nbr_fd(fd);
	player->pos.y = read_nbr_fd(fd);
	player->dirt = read_nbr_fd(fd);
	player->wind = read_nbr_fd(fd);
	player->fire = read_nbr_fd(fd);
	player->water = read_nbr_fd(fd);
	player->magic = read_nbr_fd(fd);
	player->xp = read_nbr_fd(fd);
	player->lvl = read_nbr_fd(fd);
	return (read_player2(player, fd));
}