/*
** EPITECH PROJECT, 2018
** init_render_states
** File description:
** init_render_states
*/

#include "my_rpg.h"

sfRenderStates *init_render_states(void)
{
	sfRenderStates *states = malloc(sizeof(sfRenderStates));

	if (states == NULL)
		return (NULL);
	states->texture = NULL;
	states->shader = NULL;
	states->transform = sfTransform_Identity;
	states->blendMode = sfBlendAlpha;
	return (states);
}
