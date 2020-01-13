/*
** EPITECH PROJECT, 2020
** mapping.c
** File description:
** Gael Baron's mapping.c made the 01/07/2020
*/

#include "../include/stick.h"

char **fir_tree(int map_size, int i, char **map, int *space_nb)
{
    int stick_nb = 1;
    int tmp = 1;

    if (stick_nb < i)
        for (int j = 1; j < i; j++)
            stick_nb += 2;
    for (int x = 0; x < *space_nb; x++, tmp++) {
        map[i][tmp] = ' ';
        map[i][my_strlen(map[0]) - tmp - 1] = ' ';
    }
    tmp = *space_nb + 1;
    for (int x = 0; x < stick_nb; x++, tmp++)
        map[i][tmp] = '|';
    (*space_nb) -= 1;
    map[i][0] = '*';
    map[i][my_strlen(map[0])] = '\0';
    map[i][my_strlen(map[0]) - 1] = '*';
    return (map);
}

char **mapping(int map_size)
{
    char **map = malloc(sizeof(char *) * (map_size + 3));
    int size = (map_size - 1) * 2 - 1;
    int stick_nb = 0;
    int x = 0;
    int space_nb = 0;

    for (int i = 0; i <= map_size; i++)
        map[i] = malloc(sizeof(char) * (size + 3));
    for (; x < size + 2; x++)
        map[0][x] = '*';
    map[0][x] = '\0';
    x = 0;
    for (; x < size + 2; x++)
        map[map_size][x] = '*';
    map[map_size][x] = '\0';
    space_nb = (my_strlen(map[0]) - 3 )/ 2;
    for (int i = 1; i <= map_size - 1; i++)
        map = fir_tree(map_size, i, map, &space_nb);
    map[map_size + 2] = NULL;
    return (map);
}
