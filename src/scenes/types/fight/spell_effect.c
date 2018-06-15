/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** spell_effect
*/

#include "my_rpg.h"

int spell_sword(frame_t *frame, button_t *button)
{
	int chance_crit = 9 + rand() % (frame->player->dirt / 2 + 1) +
	frame->player->dirt / 2;
	int crit = rand() % 101;
	int add = 0;
	int damage = 0;

	if (frame->player->pa < 2)
		return (NOT_ENOUGHT_PA);
	if (crit < chance_crit) {
		add = rand() % 7 + 4;
		my_printf("coup critique !\n");
	}
	damage = rand() % 3 + 1 + add + frame->player->dirt / 2;
	frame->mob[0]->pv -= damage;
	frame->player->pa -= 2;
	my_printf("spell -> SWORD :\nmob\t-%dpv\n\n", damage);
	return (EXIT_SUCCESS);
}

int spell_fire(frame_t *frame, button_t *button)
{
	int chance_crit = 9 + rand() % (frame->player->fire / 2 + 1) +
	frame->player->fire / 2;
	int crit = rand() % 101;
	int add = 0;
	int damage = 0;

	if (frame->player->pa < 3)
		return (NOT_ENOUGHT_PA);
	if (crit < chance_crit) {
		add = rand() % 15 + 8;
		my_printf("coup critique !\n");
	}
	damage = rand() % 8 + 6 + add + frame->player->fire / 2;
	frame->mob[0]->pv -= damage;
	frame->player->pa -= 3;
	my_printf("spell -> FIRE :\nmob\t-%dpv\n\n", damage);
	return (EXIT_SUCCESS);
}

int spell_water(frame_t *frame, button_t *button)
{
	int chance_crit = 9 + rand() % (frame->player->water / 2 + 1) +
	frame->player->water / 2;
	int crit = rand() % 101;
	int add = 0;
	int damage = 0;

	if (frame->player->pa < 3)
		return (NOT_ENOUGHT_PA);
	if (crit < chance_crit) {
		add = rand() % 10 + 5;
		my_printf("coup critique !\n");
	}
	damage = rand() % 5 + 3 + add + frame->player->water / 2;
	frame->mob[0]->pv -= damage;
	frame->player->pa -= 3;
	my_printf("spell -> WATER :\nmob\t-%dpv\n\n", damage);
	return (EXIT_SUCCESS);
}

int spell_thunder(frame_t *frame, button_t *button)
{
	int chance_crit = 5 + rand() % (frame->player->wind / 2 + 1);
	int crit = rand() % 101;
	int add = 0;
	int damage = 0;

	if (frame->player->pa < 3)
		return (NOT_ENOUGHT_PA);
	if (crit < chance_crit) {
		add = rand() % 20 + 10;
		my_printf("coup critique !\n");
	}
	damage = rand() % 20 + 8 + add + frame->player->wind / 2;
	frame->mob[0]->pv -= damage;
	frame->player->pa -= 3;
	frame->player->pv -= 1;
	my_printf("spell -> THUNDER :\nmob\t-%dpv\nplayer\t-1pv\n\n", damage);
	return (EXIT_SUCCESS);
}

int spell_wind(frame_t *frame, button_t *button)
{
	int chance_crit = rand() % 40 + 10;
	int crit = rand() % 101;
	int add = 0;
	int damage = 0;

	if (frame->player->pa < 2)
		return (NOT_ENOUGHT_PA);
	if (crit < chance_crit) {
		add = rand() % 80 + 30;
		my_printf("coup critique !\n");
	}
	damage = rand() % 5 + 1 + add + frame->player->wind / 2;
	frame->mob[0]->pv -= damage;
	frame->player->pa -= 2;
	my_printf("spell -> WIND :\nmob\t-%dpv\n\n", damage);
	return (EXIT_SUCCESS);
}