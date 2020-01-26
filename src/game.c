/*
** EPITECH PROJECT, 2020
** game.c
** File description:
** Gael Baron's game.c made the 01/13/2020
*/

#include "../include/stick.h"

void print_error(int err, stick_t *mst)
{
    my_putstr("Error: ");
    err == -86 ? my_putstr("invalid input (positive number expected)\n") : 0;
    err == -87 ? my_putstr("not enough match on this line\n") : 0;
    err == -88 ? my_putstr("invalid input (positive number expected)\n") : 0;
    err == -89 ? my_putstr("you have to remove at least one match\n") : 0;
    if (err == -90) {
        my_putstr("you cannot remove more than ");
        my_put_nbr(mst->max_stick_taken);
        my_putstr(" matches per turn\n");
    }
    err == -91 ? my_putstr("invalid input (positive number expected)\n") : 0;
    err == -92 ? my_putstr("invalid input (positive number expected)\n") : 0;
    err == -93 ? my_putstr("this line is out of range\n") : 0;
}

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
        return (-91);
    if (!is_possible(buff))
        return (-92);
    if (!too_big(my_atoi(buff), mst))
        return (-93);
    return (0);
}
