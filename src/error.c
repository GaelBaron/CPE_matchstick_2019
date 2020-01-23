/*
** EPITECH PROJECT, 2020
** error.c
** File description:
** Gael Baron's error.c made the 01/13/2020
*/

#include "../include/stick.h"

int too_small_line(stick_t *mst, char *buff, int line)
{
    int possible = 0;
    int nb = my_atoi(buff);

    for (int i = 0; mst->map[line][i]; i++)
        if (mst->map[line][i] == '|')
            possible++;
    if (possible < nb)
        return (0);
    return (1);
}

int are_sticks_all_ok(stick_t *mst, char *buff, int line)
{
    if (!is_a_number(buff))
        return (NOT_A_NB);
    if (!too_small_line(mst, buff, line))
        return (TOO_SMALL);
    if (my_atoi(buff) <= 0)
        return (NOT_A_NB);
    if (my_atoi(buff) > mst->max_stick_taken)
        return (NOT_A_NB);
    return (0);
}

int split_rec(stick_t *mst, int *line, int *stick_nb)
{
    int err_sec = 1;

    my_putstr("Matches: ");
    *stick_nb = stick_errors(mst, *line);
    if (*stick_nb == -85)
        return (-85);
    if (*stick_nb == -84) {
        my_putstr("Error: invalid input (positive number expected)\n");
        recursive_asking(mst, line, stick_nb);
        return (0);
    }
}

int recursive_asking(stick_t *mst, int *line, int *stick_nb)
{
    int err = 1;

    my_putstr("Line: ");
    *line = lines_errors(mst);
    if (*line == -85)
        return (-85);
    if (*line == -84) {
        my_putstr("Error: invalid input (positive number expected)\n");
        recursive_asking(mst, line, stick_nb);
        return (0);
    }
    return (split_rec(mst, line, stick_nb));
}

int stick_errors(stick_t *mst, int line)
{
    char *buff = NULL;
    size_t len = 0;
    int err = 0;

    if (getline(&buff, &len, stdin) <= -1)
        return (-85);
    buff = delete_n(buff);
    err = are_sticks_all_ok(mst, buff, line);
    if (err != 0)
        return (-84);
    return (my_atoi(buff));
}
