/*
** EPITECH PROJECT, 2021
** search
** File description:
** search
*/

#include "../include/my.h"

int square_of_size(char **map , int row,int col , int square_size)
{
    int n, m;

    for (n = row; ((n < square_size + row) && (map[n] != NULL)); n++) {
        for (m = col; ((m < square_size + col) && (map[n][m] != '\0')); m++) {
            if (map[n][m] != '.')
                return (0);
        }
        if (map[n][m] == '\0' || m < col + square_size)
            return (0);
    }
    if (map[n] == NULL || n < row + square_size)
        return (0);
    return (1);
}

int found_square(char **map, int row, int col)
{
    int square_size = 1;
    for ( ; (square_of_size(map, row, col, square_size) != 0); square_size++);

    return (square_size - 1);
}

data big_square(char **map)
{
    int i = 0, j = 0;
    data data_c;
    data_c.carre = 0;
    data_c.line = 0;
    data_c.colonne = 0;
    for (; map[i] != NULL; i++) {
        for (j = 0; map[i][j] != '\0'; j++) {
            data_c.standard = found_square(map, i, j);
            if (data_c.standard >= data_c.carre){
                data_c.carre = data_c.standard;
                data_c.line = i;
                data_c.colonne = j;
            }
        }
    }
    return (data_c);
}

int main(int ac, char **av)
{
    int n;
    struct stat bul;
    stat(av[1], &bul);
    int fd = open(av[1], O_RDONLY);
    char *buffer = malloc(sizeof(char) * (bul.st_size));
    int p = read(fd, buffer, bul.st_size);
    int x = my_getnbr(buffer);
    char **str;
    str = load_2d_arr_from_file(av[1], x, x);
    data coodonne = big_square(str);
    for (int i = coodonne.line; i < coodonne.line + coodonne.carre; i++)
        for (int j = coodonne.colonne; j < coodonne.colonne +
           coodonne.carre; j++)
            str[i][j] = 'x';
    for (n = 0; str[n] != NULL; n++) {
        write(1, str[n], my_strlen(str[n]));
    }
    free (buffer);
    free (str);
}
