/*
** EPITECH PROJECT, 2018
** my_world_2017
** File description:
** str to float
*/

#include <criterion/criterion.h>
#include "myworld.h"

Test(myworld, str_to_float)
{
	cr_assert_float_eq(str_to_float("1.5"), 1.5, 0);
}

Test(myworld, str_to_float2)
{
	cr_assert_float_eq(str_to_float("-1.5"), -1.5, 0);
}

Test(myworld, str_to_float3)
{
	cr_assert_float_eq(str_to_float("13.75"), 13.75, 0);
}

Test(myworld, str_to_float4)
{
	cr_assert_float_eq(str_to_float("0.0"), 0, 0);
}
