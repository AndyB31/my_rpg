/*
** EPITECH PROJECT, 2018
** free_player
** File description:
** free_player
*/

#include "my_rpg.h"

int free_player(player_t *player)
{
	free_sprite_inf(player->sprite);
	free(player);
	return (0);
}