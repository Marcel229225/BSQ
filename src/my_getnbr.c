/*
** EPITECH PROJECT, 2020
** My_getnbr
** File description:
** Returns a number, sent to the function as a string
*/

#include "../include/my.h"

int my_getnbr(char const *str)
{
    int m;
    int n = 0;
    int o = 1;

    for (m = 0; str[m] == '-' || str[m] == '+'; m++) {
        if (str[m] == '-')
            o = o * (-1);
    }
    for (; str[m] >= '0' && str[m] <= '9'; m++) {
        n = (n * 10) + (str[m] - 48);
    }
    return (o * n);
}
