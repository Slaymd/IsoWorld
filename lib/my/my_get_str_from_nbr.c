/*
** EPITECH PROJECT, 2018
** Libmy
** File description:
** my get str from nbr
*/

#include <stdlib.h>

int	my_get_int_len(int nb)
{
	int	len = 1;

	if (nb < 0) {
		len++;
		nb = -nb;
	}
	while (nb > 9) {
		nb /= 10;
		len++;
	}
	return (len);
}

char *my_get_str_from_nbr(int nb)
{
	char *strnbr = (char*)malloc(sizeof(char) * (my_get_int_len(nb) + 1));
	int index = 0;

	if (strnbr == NULL)
		return (NULL);
	if (nb < 0) {
		strnbr[index] = '-';
		index++;
		nb = -nb;
	}
	if (nb == 0) {
		strnbr[index] = '0';
		strnbr[index + 1] = '\0';
	}
	for (; nb != 0; index++) {
		strnbr[index] = (nb % 10) + '0';
		nb /= 10;
		strnbr[index + 1] = '\0';
	}
	return (strnbr);
}
