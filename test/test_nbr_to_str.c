/*
** EPITECH PROJECT, 2018
** my_world_2017
** File description:
** nbr to str convert
*/

#include <criterion/criterion.h>
#include "myworld.h"

Test(myworld, nbrtostr)
{
	cr_assert_str_eq(my_get_str_from_nbr(42), "42");
}

Test(myworld, nbrtostr2)
{
	cr_assert_str_eq(my_get_str_from_nbr(-42), "-42");
}

Test(myworld, nbrtostr3)
{
	cr_assert_str_eq(my_get_str_from_nbr(0), "");
}
