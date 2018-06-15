/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** update_fight
*/

#include "my_rpg.h"

void display_bar(frame_t *frame, unsigned int sec)
{
	sfTexture *texture = NULL;
	sfSprite *sprite = NULL;
	scene_t *s = get_scene_by_type(&(frame->scene), frame->curent_scene);
	list_t *sprite_list = get_list_by_name(&(s->sprite_list), "bar");

	sfTexture_destroy(sprite_list->sprite_inf->texture);
	sprite_list->sprite_inf->texture = sfTexture_createFromFile(
	BAR_(10 - sec), NULL);
}

void mob_round(frame_t *frame, scene_t *scene)
{
	int damage = rand() % (2 * frame->mob[0]->pa + 1) + frame->mob[0]->pa;
	int crit = rand() % 101 + 1;
	int add = 0;

	if (crit <= 10) {
		add = rand() % (frame->mob[0]->pa + 1) + 10;
		my_printf("critical: +%d\n");
	}
	damage += add;
	my_printf("MOB : attack : DAMAGE = %d\n\n", damage);
	frame->player->pv -= damage;
}

void end_of_fight(frame_t *frame, scene_t *scene)
{
	my_putstr("end\n");
	if (frame->player->pv > 0) {
		my_putstr("player win\n");
		frame->player->xp += frame->mob[0]->px_get;
		frame->mob[0]->pv = frame->mob[0]->pv_max;
		set_scene_to(frame, WIN, false);
	} else {
		my_putstr("mob win\n");
		set_scene_to(frame, LOSE, false);
	}
}

void manage_fight(frame_t *frame, unsigned int *sec, scene_t *scene)
{
	list_t *button = get_list_by_name(&scene->button_list, "mob");
	float life = ((float)frame->mob[0]->pv / (float)frame->mob[0]->pv_max);

	sprite_set_scale(get_list_by_name(&scene->sprite_list,
	"bar_full")->sprite_inf, life, 1);
	life = ((float)frame->player->pv / (float)frame->player->pv_max);
	sprite_set_scale(get_list_by_name(&scene->sprite_list,
	"life_full")->sprite_inf, life, 1);
	if (frame->player->round == true) {
		display_bar(frame, *sec);
		button->button->click_action = &click_on_mob;
	} else {
		if (*sec < 10)
			mob_round(frame, scene);
		*sec = 10;
		frame->player->pa = frame->player->pa_max;
		button->button->click_action = &put_empty;
	}
}

void update_fight(frame_t *frame, scene_t *scene)
{
	static unsigned int sec = 0;
	list_t *button = get_list_by_name(&scene->button_list, "mob");
	float life = ((float)frame->player->pa / (float)frame->player->pa_max);

	sprite_set_scale(get_list_by_name(&scene->sprite_list,
	"pa_full")->sprite_inf, life, 1);
	frame->player->round = (frame->player->round == -1) ?
	rand() % 2 : frame->player->round;
	if (frame->mob[0]->pv <= 0 || frame->player->pv <= 0) {
		end_of_fight(frame, scene);
		return;
	} else if (scene->current_tick == 0)
		sec++;
	if (sec == 11) {
		frame->player->round = (frame->player->round == false) ?
		true : false;
		sec = 0;
		frame->player->lvl += 1;
	}
	manage_fight(frame, &sec, scene);
}
