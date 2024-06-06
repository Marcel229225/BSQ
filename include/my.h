/*
** EPITECH PROJECT, 2020
** My.h
** File description:
** My.h
*/

#ifndef MY_H_
#define MY_H_

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct dataw{
    int standard;
    int carre;
    int line;
    int colonne;
}data;

int my_strlen(char const *str);
int my_put_nbr(int nb);
void my_putchar(char c);
int my_putstr(char const *str);
int my_getnbr(char const *str);
int square_of_size(char **map , int row , int col , int  square_size);
int main(int ac, char **av);
int square_of_size(char **map , int row , int col , int  square_size);
int found_square(char **map, int row, int col);
char ** load_2d_arr_from_file(char const *filepath,
int  nb_rows, int  nb_cols);
data big_square(char **map);

#endif
