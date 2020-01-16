/*
** EPITECH PROJECT, 2020
** ia.c
** File description:
** Gael Baron's ia.c made the 01/13/2020
*/

#include "../include/stick.h"

int line_nb(char *str)
{
    int nb = 0;

    for (int i = 0; str[i]; i++)
        if (str[i] == '|')
            nb++;
    return (nb);
}

int bigger(char **map, int max)
{
    int tmp = 0;
    int tmp_l = 0;

    for (; max >= 0; max--) {
        for (int i = 0; map[i]; i++)
            if (line_nb(map[i]) > tmp) {
                tmp = line_nb(map[i]);
                tmp_l = i;
            }
        if (tmp >= max)
            return (tmp_l);
    }
    return (-84);
}

int number(char **map, int max)
{
    int tmp = 0;
    int tmp_l = 0;

    for (; max >= 0; max--) {
        for (int i = 0; map[i]; i++)
            if (line_nb(map[i]) > tmp) {
                tmp = line_nb(map[i]);
                tmp_l = i;
            }
        if (tmp >= max)
            return (tmp);
    }
    return (-84);
}

char **ai_turn(char **map, int max)
{
    int line = bigger(map, max);
    int first_stick = 0;
    int stick = number(map, max);

    if (line == -84 || stick == -84)
        return (NULL);
    if (stick > max)
        stick = max;
    for (int i = 0; map[i]; i++) {
        my_putstr(map[i]);
        my_putchar('\n');
    }
    my_putstr("\nAI's turn...\n");
    for (int i = 0; map[line][i]; i++)
        if (map[line][i] == '|')
            first_stick = i;
    for (int i = 0; i < stick; i++)
        map[line][first_stick - i] = ' ';
    my_putstr("AI Removed ");
    my_put_nbr(stick);
    my_putstr(" match(es) from line ");
    my_put_nbr(line);
    my_putchar('\n');
    return (map);
}
