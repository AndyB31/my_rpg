/*
** EPITECH PROJECT, 2018
** init_intro_scene
** File description:
** init_intro_scene
*/

#include "my_rpg.h"

static int change_scene(frame_t *frame, scene_t *scene, char *id_str)
{
	if (my_get_nbr(frame->curr_cutscene) + 1 > my_get_nbr(id_str)) {
		free(id_str);
		set_scene_to(frame, GAME, true);
		return (1);
	}
	return (0);
}

static void cutscenes_scene_tick2(frame_t *frame, scene_t *scene, \
char *new_path)
{
	list_t *list = get_list_by_name(&(scene->sprite_list), "img");
	sprite_info_t *sprite_inf = list->sprite_inf;
	char *id_str = read_value_file(new_path, "nbr");
	char *new_nbr = NULL;

	if (change_scene(frame, scene, id_str) == 1)
		return;
	new_nbr = my_nbr_to_str(my_get_nbr(frame->curr_cutscene) + 1);
	frame->curr_cutscene = set_str_to(frame->curr_cutscene, new_nbr);
	free(id_str);
	id_str = read_value_file(new_path, new_nbr);
	free(new_nbr);
	free(new_path);
	if (sprite_inf->texture)
		sfTexture_destroy(sprite_inf->texture);
	if (id_str == NULL)
		return;
	sprite_inf->texture = sfTexture_createFromFile(id_str, NULL);
	free(id_str);
}

void cutscenes_scene_tick(frame_t *frame, scene_t *scene)
{
	char *new_path = my_strcat("./data/cutscenes/", frame->cutscene);
	char *to_wait = my_strcat(frame->curr_cutscene, "t");
	char *to_wait2 = read_value_file(new_path, to_wait);
	static int tick = 0;

	tick++;
	if (tick >= my_get_nbr(to_wait2))
		tick = 0;
	else
		return;
	cutscenes_scene_tick2(frame, scene, new_path);
}

void cutscenes_scene_init(frame_t *frame, scene_t *scene)
{
	list_t *list = get_list_by_name(&(scene->sprite_list), "img");
	sprite_info_t *sprite_inf = list->sprite_inf;
	char *new_path = my_strcat("./data/cutscenes/", frame->cutscene);
	char *path = read_value_file(new_path, "1");

	frame->curr_cutscene = set_str_to(frame->curr_cutscene, "1");
	if (sprite_inf->texture)
		sfTexture_destroy(sprite_inf->texture);
	sprite_inf->texture = sfTexture_createFromFile(path, NULL);
	free(path);
	path = read_value_file(new_path, "music");
	if (path != NULL) {
		scene->background_music = sfMusic_createFromFile(path);
		free(path);
		sfMusic_setVolume(scene->background_music, \
		frame->volume_level);
		if (frame->volume_stop == 0)
			sfMusic_play(scene->background_music);
	}
	free(new_path);
}

int init_cutscenes_scene(list_t **scene_list, frame_t *frame)
{
	scene_t *cutscene = create_scene(CUTSCENE);
	sfVector2i size = {.x = -1, .y = -1};
	sprite_info_t *sprite = create_sprite(0, size, ASSET_INTRO);

	cutscene->event_init = &cutscenes_scene_init;
	cutscene->event_tick = &cutscenes_scene_tick;
	cutscene->event_key_pressed = &cutscene_key_press_event;
	add_sprite_inf(&(cutscene->sprite_list), sprite, "img");
	add_scene(scene_list, cutscene);
	return (1);
}
