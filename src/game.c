/*
** EPITECH PROJECT, 2020
** game.c
** File description:
** Gael Baron's game.c made the 01/13/2020
*/

#include "../include/stick.h"

char *delete_n(char *buff)
{
    int i = 0;
    char *str = malloc(sizeof(char) * my_strlen(buff));

    for (; buff[i] != '\n' && buff[i]; i++)
        str[i] = buff[i];
    str[i] = '\0';
    return (str);
}

int is_a_number(char *buff)
{
    for (int i = 0; buff[i]; i++)
        if (buff[i] < '0' || buff[i] > '9')
            return (0);
    return (1);
}

int is_possible(char *buff)
{
    int nb = my_atoi(buff);

    if (nb <= 0)
        return (0);
    return (1);
}

int are_they_all_ok(stick_t *mst, char *buff)
{
    if (!is_a_number(buff))
        return (NOT_A_NB);
    if (!is_possible(buff))
        return (CANT_MATCH);
    if (!too_big(my_atoi(buff), mst))
        return (TOO_BIG);
    return (0);
}
