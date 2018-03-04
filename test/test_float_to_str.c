/*
** EPITECH PROJECT, 2018
** my_world_2017
** File description:
** float tests
*/

#include <criterion/criterion.h>
#include "myworld.h"

Test(myworld, floattostr)
{
	cr_assert_str_eq(float_to_str(1.5), "1.5");
}

Test(myworld, floattostr1)
{
	cr_assert_str_eq(float_to_str(-1.5), "-1.5");
}

Test(myworld, floattostr2)
{
	cr_assert_str_eq(float_to_str(0.0), "0");
}

Test(myworld, floattostr3)
{
	cr_assert_str_eq(float_to_str(13.75), "13.75");
}
