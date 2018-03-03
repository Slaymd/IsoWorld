/*
** EPITECH PROJECT, 2018
** my_world_2017
** File description:
** map gen
*/

#include <criterion/criterion.h>
#include "myworld.h"

float	**generate_flat_3dmap(int width, int height);

Test(myworld, generation)
{
	float **zmap = generate_flat_3dmap(5, 5);
	int test = zmap[0][0];

	cr_assert_eq(test, 0);
}

Test(myworld, generation2)
{
	float **zmap = generate_flat_3dmap(5, 5);
	int test = zmap[4][4];

	cr_assert_eq(test, 0);
}
