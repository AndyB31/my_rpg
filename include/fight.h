/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** fight.h
*/

#ifndef _FIGHT_
#define _FIGHT_

#include "my_rpg.h"

int check_boss1(frame_t *frame);
int check_boss2(frame_t *frame);
int check_boss3(frame_t *frame);
void init_fight(list_t **scene_list, frame_t *frame);
int spell_sword(frame_t *frame, button_t *button);
int spell_fire(frame_t *frame, button_t *button);
int spell_eye(frame_t *frame, button_t *button);
int spell_wind(frame_t *frame, button_t *button);
int spell_water(frame_t *frame, button_t *button);
int spell_fist(frame_t *frame, button_t *button);
int spell_pot(frame_t *frame, button_t *button);
int spell_thunder(frame_t *frame, button_t *button);
void click_on_mob(int x, int y, frame_t *frame, button_t *button);
void move_mouse(sfMouseMoveEvent event, frame_t *frame);
void put_empty(sfMouseButtonEvent event, frame_t *frame);
void put_color(int x, int y, frame_t *frame, button_t *button);
void spell_click(int x, int y, frame_t *frame, button_t *button);
int open_fight(frame_t *frame);
int init_win_scene(list_t **scene_list, frame_t *frame);
int init_lose_scene(list_t **scene_list, frame_t *frame);
void init_life_bar(scene_t *scene);
void init_pa_bar(scene_t *scene);
void spell_hover(int x, int y, frame_t *frame, button_t *button);
void init_esc_button(scene_t *scene);
void win_scene_tick(frame_t *frame, scene_t *scene);
void lose_scene_tick(frame_t *frame, scene_t *scene);

#define NOT_ENOUGHT_PA -1

#endif