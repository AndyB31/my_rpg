/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** spell_effect
*/

#include "my_rpg.h"

int spell_pot(frame_t *frame, button_t *button)
{
	int chance_crit = 9 + rand() % (frame->player->magic / 2 + 1);
	int crit = rand() % 101;
	int add = 0;
	int damage = 0;

	if (frame->player->pa < 4)
		return (NOT_ENOUGHT_PA);
	if (crit < chance_crit) {
		add = rand() % 10 + 5;
		my_printf("coup critique !\n");
	}
	damage = rand() % 21 + 5 + add + frame->player->magic / 2;
	frame->player->pa -= 4;
	if ((frame->player->pv + damage) > frame->player->pv_max)
		damage = frame->player->pv_max - frame->player->pv;
	frame->player->pv += damage;
	frame->mob[0]->pv -= damage;
	my_printf("spell -> POT :\nmob\t-%dpv\nplayer\t+%dpv\n\n",
	damage, damage);
	return (EXIT_SUCCESS);
}

int spell_fist(frame_t *frame, button_t *button)
{
	int chance_crit = 5 + rand() % (frame->player->magic / 2 + 1);
	int crit = rand() % 101;
	int add = 0;
	int damage = 0;

	if (frame->player->pa < 5)
		return (NOT_ENOUGHT_PA);
	if (crit < chance_crit) {
		add = rand() % 50 + 20;
		my_printf("coup critique !\n");
	}
	damage = rand() % 71 + 30 + add + frame->player->magic / 2;
	frame->mob[0]->pv -= damage;
	frame->player->pa -= 5;
	frame->player->pv -= 5;
	my_printf("spell -> FIST :\nmob\t-%dpv\nplayer\t-5pv\n\n",
	damage);
	return (EXIT_SUCCESS);
}

void eye2(frame_t *frame, int add, int add_pa)
{
	int pa_give = rand() % 4 + 2;
	int damage = rand() % 6 + 2 + add + frame->player->magic / 2;
	int pa_dam = rand() % 4 + add_pa;

	frame->mob[0]->pv -= damage;
	frame->player->pv -= 5;
	if ((frame->player->pa + pa_dam) > frame->player->pa_max)
		pa_dam = 0;
	frame->player->pa += pa_dam;
	my_printf("spell -> EYE :\nmob\t-%dpv -%dpa\nplayer\t-5pv +%dpa\n\n",
	damage, pa_dam, pa_give);
}

int spell_eye(frame_t *frame, button_t *button)
{
	int chance_crit = 5 + rand() % (frame->player->magic / 2 + 1);
	int crit = rand() % 101;
	int add = 0;
	int add_pa = 0;

	if (crit < chance_crit) {
		add = rand() % 5 + 2;
		add_pa = rand() % 2 + 1;
		my_printf("coup critique !\n");
	}
	eye2(frame, add, add_pa);
	return (EXIT_SUCCESS);
}