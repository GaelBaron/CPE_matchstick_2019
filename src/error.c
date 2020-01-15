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

int stick_errors(stick_t *mst, int line)
{
    char *buff = NULL;
    size_t len = 0;
    int err = 0;

    if (getline(&buff, &len, stdin) == -1)
        return (-84);
    buff = delete_n(buff);
    err = are_sticks_all_ok(mst, buff, line);
    if (err != 0)
        while (err != 0) {
            my_putstr("Error: Invalid input (Positive number expected)");
            my_putstr("\nMatch: ");
            getline(&buff, &len, stdin);
            buff = delete_n(buff);
            err = are_sticks_all_ok(mst, buff, line);
        }
    return (my_atoi(buff));
}
