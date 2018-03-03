/*
** EPITECH PROJECT, 2018
** my_world_2017
** File description:
** visibility tests
*/

#include <criterion/criterion.h>
#include "myworld.h"

my_world_t *init_world_test(void);

Test(myworld, visibility)
{
	my_world_t *world = init_world_test();
	pos_t pos = {0, 0, 0, sfRed};

	cr_assert_eq(point_is_visible(world, pos), 1);
}
