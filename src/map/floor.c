/*
** EPITECH PROJECT, 2017
** frame
** File description:
** frame
*/
#include "my_rpg.h"

char *copy_in_buffer_floor(map_t *map, char *filepath)
{
	char *temp = malloc(sizeof(char) * 2);
	int i = 0;
	int tmp = open(filepath, O_RDONLY);
	char *buffer = NULL;

	for (i = 0; read(tmp, temp, 1); i++) ;
	i++;
	close(tmp);
	tmp = open(filepath, O_RDONLY);
	map->flor = malloc((sizeof(gameobj_t) * i));
	buffer = malloc((sizeof(char) * i));
	read(tmp, buffer, i);
	buffer[i] = '\0';
	close(tmp);
	return buffer;
}

int display_floor (frame_t *frame)
{
	sfVector2f scale = {3, 3};
	sfVector2f scale2 = {1.5, 1.5};
	int where = frame->player->where;

	frame->player->sprite->scale = scale2;
	for (int i = 0; frame->map[where].flor[i].id != -1; i++)
	{
		if (frame->map[where].flor[i].id != 0) {
			sfIntRect rec = {(((frame->map[where].flor[i].id %
			32) -1) * 8), (((frame->map[where].flor[i].id / 32))
			* 8) , 8, 8};
			frame->map[where].flor[i].sprite->scale = scale;
			render_sprite2(frame, frame->map[where].flor[i].sprite,
			rec);
		}
	}
	return (0);
}

void stock_map2(map_t *map, char **all_id, int temp)
{
	sfVector2i size = {24, 24};

	map->flor[temp].id = my_get_nbr(all_id[temp]);
	if (map->flor[temp].id != 0) {
		map->flor[temp].sprite = create_sprite(0, size,
		"./assets/terrain/CB-Temple-B.png");
		sprite_set_pos(map->flor[temp].sprite, map->flor[temp].pos.x,
		map->flor[temp].pos.y);
	} else
		map->flor[temp].sprite = NULL;
}

void stock_map(map_t *map, char *flor)
{
	char *buffer = copy_in_buffer_floor(map, flor);
	int posx = 0;
	int posy = 0;
	int temp = 0;
	char **all_id = my_str_to_word_array(buffer);

	for (int i = 0; i < 55; posy += 24, i++) {
		for (int j = 0; j < 55; posx += 24, temp++, j++) {
			map->flor[temp].pos.x = posx;
			map->flor[temp].pos.y = posy;
			stock_map2(map, all_id, temp);
		}
		posx = 0;
	}
	map->flor[temp].id = -1;
}
