/*
** EPITECH PROJECT, 2021
** charge_map
** File description:
** charge the map
*/

#include "../include/my.h"

char ** load_2d_arr_from_file(char  const *filepath,int  nb_rows, int  nb_cols)
{
    int n = 0, m = 0, i = 0;
    struct stat bul;
    stat(filepath, &bul);
    int fd = open(filepath, O_RDONLY);
    char *buffer = malloc(sizeof(char) * (bul.st_size));
    int p = read(fd, buffer, bul.st_size);
    for (i = 0; buffer[i] != '\n'; i++);
    char **load = malloc(sizeof(char *) * ((nb_rows) + 1));
    for (n = 0; n < nb_rows; n++)
        load[n] = malloc(sizeof(char) *(nb_cols + 1));
    for (n = 0; n < nb_rows; n++) {
        for (m = 0; m < nb_cols; m++) {
            load[n][m] = buffer[i];
            i++;
        }
        i++;
        load[n][m] = '\0';
    }
    load[n] = NULL;
    close (p);
    return (load);
}
