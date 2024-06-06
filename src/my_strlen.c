/*
** EPITECH PROJECT, 2020
** my_strlen
** File description:
** counts and returns the number of characters found in the string
*/

int my_strlen(char const *str)
{
    int n = 0;

    while (str[n] != '\0') {
        n++;
    }
    return (n);
}
