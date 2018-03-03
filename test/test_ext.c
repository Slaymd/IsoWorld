/*
** EPITECH PROJECT, 2018
** my_world_2017
** File description:
** file extension tests
*/

#include <criterion/criterion.h>
#include "myworld.h"

Test(myworld, extension)
{
	char *filename = "cc";

	cr_assert_eq(is_extension(filename, ".legend"), 0);
}

Test(myworld, extension2)
{
	char *filename = ".legendcc";

	cr_assert_eq(is_extension(filename, ".legend"), 0);
}

Test(myworld, extension3)
{
	char *filename = ".legend";

	cr_assert_eq(is_extension(filename, ".legend"), 1);
}

Test(myworld, extension4)
{
	char *filename = "cc.legend";

	cr_assert_eq(is_extension(filename, ".legend"), 1);
}
