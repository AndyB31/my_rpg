/*
** EPITECH PROJECT, 2017
** frame
** File description:
** frame
*/
#include "my_rpg.h"

char *copy_in_buffer_behind(map_t *map, char *filepath)
{
	char *temp = malloc(sizeof(char) * 2);
	int i = 0;
	int tmp = open(filepath, O_RDONLY);
	char *buffer = NULL;

	for (i = 0; read(tmp, temp, 1); i++) ;
	i++;
	close(tmp);
	tmp = open(filepath, O_RDONLY);
	map->behind = malloc((sizeof(gameobj_t) * i));
	buffer = malloc((sizeof(char) * i));
	read(tmp, buffer, i);
	buffer[i] = '\0';
	close(tmp);
	return buffer;

}

int display_behind (frame_t *frame)
{
	sfVector2f scale = {3, 3};
	sfVector2f scale2 = {1.5, 1.5};
	frame->player->sprite->scale = scale2;
	int where = frame->player->where;

	for (int i = 0; frame->map[where].behind[i].id != -1; i++)
	{
		if (frame->map[where].behind[i].id != 0) {
			sfIntRect rec = {(((frame->map[where].behind[i].id
			% 32) - 1) * 8), (((frame->map[where].behind[i].id /
			32))* 8) , 8, 8};
			frame->map[where].behind[i].sprite->scale = scale;
			render_sprite2(frame,
			frame->map[where].behind[i].sprite, rec);
		}
	}
	return (0);
}

void stock_behind2(map_t *map, char **all_id, int temp)
{
	sfVector2i size = {24, 24};

	map->behind[temp].id = my_get_nbr(all_id[temp]);
	if (map->behind[temp].id != 0) {
		map->behind[temp].sprite = create_sprite(0, size,
		"./assets/terrain/CB-Temple-B.png");
		sprite_set_pos(map->behind[temp].sprite,
		map->behind[temp].pos.x, map->behind[temp].pos.y);
	} else
		map->behind[temp].sprite = NULL;
}

void stock_behind(map_t *map, char *behind)
{
	int fd = open (behind, O_RDONLY);
	char *buffer = copy_in_buffer_behind(map, behind);
	int posx = 0;
	int posy = 0;
	int temp = 0;
	char **all_id = my_str_to_word_array(buffer);

	for (int i = 0; i < 55; posy += 24, i++) {
		for (int j = 0; j < 55; posx += 24, temp++, j++) {
			map->behind[temp].pos.x = posx;
			map->behind[temp].pos.y = posy;
			stock_behind2(map, all_id, temp);
		}
		posx = 0;
	}
	map->behind[temp].id = -1;
	close(fd);
}
