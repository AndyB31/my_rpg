/*
** EPITECH PROJECT, 2018
** game_buttons.c
** File description:
** game buttons
*/

#include "my_rpg.h"

void init_plus_button(scene_t *game)
{
	sfVector2f plus_pos = {.x = 1873, .y = 26};
	sfVector2f plus_size = {.x = 32, .y = 32};
	button_t *plus_button = create_button(plus_pos, plus_size);

	plus_button->click_action = &game_plus_button;
	set_base_texture(plus_button, ASSET_PLUS);
	set_hover_texture(plus_button, ASSET_PLUS);
	set_clicked_texture(plus_button, ASSET_PLUS);
	add_button(&(game->button_list), plus_button, "plus_b");
}

void init_book_button(scene_t *game)
{
	sfVector2f book_pos = {.x = 1803, .y = 572};
	sfVector2f book_size = {.x = 100, .y = 100};
	button_t *book_button = create_button(book_pos, book_size);

	book_button->click_action = &book_button_action;
	set_base_texture(book_button, ASSET_BOOK);
	set_hover_texture(book_button, ASSET_BOOK);
	set_clicked_texture(book_button, ASSET_BOOK);
	add_button(&(game->button_list), book_button, "book_b");
}

void init_bag_button(scene_t *game)
{
	sfVector2f bag_pos = {.x = 1803, .y = 221};
	sfVector2f bag_size = {.x = 100, .y = 100};
	button_t *bag_button = create_button(bag_pos, bag_size);

	bag_button->click_action = &bag_button_action;
	set_base_texture(bag_button, ASSET_BAG);
	set_hover_texture(bag_button, ASSET_BAG);
	set_clicked_texture(bag_button, ASSET_BAG);
	add_button(&(game->button_list), bag_button, "bag_b");
}

void init_gear_button(scene_t *game)
{
	sfVector2f gear_pos = {.x = 1803, .y = 87};
	sfVector2f gear_size = {.x = 100, .y = 100};
	button_t *gear_button = create_button(gear_pos, gear_size);

	gear_button->click_action = &gear_button_action;
	set_base_texture(gear_button, ASSET_GEAR);
	set_hover_texture(gear_button, ASSET_GEAR);
	set_clicked_texture(gear_button, ASSET_GEAR);
	add_button(&(game->button_list), gear_button, "gear_b");
}

void init_tree_button(scene_t *game)
{
	sfVector2f tree_pos = {.x = 1803, .y = 442};
	sfVector2f tree_size = {.x = 100, .y = 100};
	button_t *tree_button = create_button(tree_pos, tree_size);

	set_base_texture(tree_button, ASSET_TREE);
	set_hover_texture(tree_button, ASSET_TREE);
	set_clicked_texture(tree_button, ASSET_TREE);
	add_button(&(game->button_list), tree_button, "tree_b");
}
