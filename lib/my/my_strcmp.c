/*
** EPITECH PROJECT, 2017
** my_strcmp
** File description:
** compare two str
*/

int my_strcmp(char const *s1, char const *s2)
{
	while ('\0' != *s1) {
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

int my_strcmp2(char const *s1, char const *s2)
{
	while ('\0' != *s1) {
		if (*s1 != *s2)
			return (0);
		s1++;
		s2++;
	}
	return (1);
}