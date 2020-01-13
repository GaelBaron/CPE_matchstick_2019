/*
** EPITECH PROJECT, 2020
** main.c
** File description:
** Gael Baron's main.c made the 01/07/2020
*/

#include "../include/stick.h"

int main(int ac, char **av)
{
    return (matchstick(my_atoi(av[1]), my_atoi(av[2])));
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
