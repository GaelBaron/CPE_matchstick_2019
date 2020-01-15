/*
** EPITECH PROJECT, 2020
** main.c
** File description:
** Gael Baron's main.c made the 01/07/2020
*/

#include "../include/stick.h"

int too_big(int nb, stick_t *mst)
{
    int nbs = 0;

    if (nb > mst->map_size)
        return (0);
    for (int i = 0; mst->map[nb][i]; i++)
        if (mst->map[nb][i] == '|')
            nbs++;
    if (nbs == 0)
        return (0);
    return (1);
}

int main(int ac, char **av)
{
    int ret = 0;

    if (ac != 3)
        return (84);
    if (!is_a_number(av[1]) || !is_a_number(av[2]))
        return (84);
    if (my_atoi(av[1]) <= 0 || my_atoi(av[2]) <= 0)
        return (84);
    ret = matchstick(my_atoi(av[1]), my_atoi(av[2]));
    if (ret == 1)
        my_putstr("LOL I BEAT YOU U BAD HAHAHAHAHA\n");
    if (ret == 2)
        my_putstr("You won for this time... BUT I M STILL BETTER THAN YOU\n");
    return (ret);
}

char **player_turn(char **map, int line, int stick)
{
    int first_stick = 0;

    for (; map[line][first_stick] != '|'
            && map[line][first_stick]; first_stick++);
    for (int i = 0; i < stick; i++)
        map[line][first_stick + i] = ' ';
    my_putstr("Player Removed ");
    my_put_nbr(stick);
    my_putstr(" match(es) from line ");
    my_put_nbr(line);
    my_putchar('\n');
    return (map);
}
