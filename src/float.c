/*
** EPITECH PROJECT, 2018
** float.c
** File description:
** my_world
*/

#include "myworld.h"

char *float_to_str(float nb)
{
	int integer = (int)nb;
	int count = 0;

	printf("%f\n", nb);
	while (integer != nb) {
		count++;
		nb = nb * 10;
		integer = (int)nb;
	}
	return (my_get_str_from_float(integer, count));
}

float str_to_float(char *str)
{
	int count = 0;
	int integer = my_getfloat(str, &count);
	float nb = my_getnbr(str + count + 1);

	for (; count != 0; count--) {
		nb = nb / 10;
	}
	return ((float)integer + nb);
}
