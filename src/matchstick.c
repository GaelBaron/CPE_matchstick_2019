/*
** EPITECH PROJECT, 2020
** matchstick.c
** File description:
** Gael Baron's matchstick.c made the 01/07/2020
*/

#include "../include/stick.h"

int lines_errors(stick_t *mst)
{
    char *buff = NULL;
    size_t len = 0;
    int err = 0;

    if (getline(&buff, &len, stdin) <= -1)
        return (-84);
    buff = delete_n(buff);
    err = are_they_all_ok(mst, buff);
    if (err != 0)
        while (err != 0) {
            print_error(err);
            if (getline(&buff, &len, stdin) <= -1)
                return (-84);
            buff = delete_n(buff);
            err = are_they_all_ok(mst, buff);
        }
    return (my_atoi(buff));
}

void print_interface(char **map)
{
    for(int i = 0; map[i]; i++) {
        my_putstr(map[i]);
        my_putchar('\n');
    }
    my_putstr("\nYour turn:\nLine: ");
}

int is_game_end(char **map)
{
    int nb = 0;

    for (int i = 0; map[i]; i++)
        for (int j = 0; map[i][j]; j++) {
            if (map[i][j] == '|')
                nb++;
        }
    if (nb == 0)
        return (1);
    return (NOT_END);
}

char **game_fight(stick_t *mst)
{
    int line = 0;
    int stick_nb = 0;

    print_interface(mst->map);
    line = lines_errors(mst);
    if (line == -84)
        return (NULL);
    my_putstr("Matches: ");
    stick_nb = stick_errors(mst, line);
    if (stick_nb == -84)
        return (NULL);
    mst->map = player_turn(mst->map, line, stick_nb);
    return (mst->map);
}

int matchstick(int map_size, int max_stick_taken)
{
    stick_t *mst = malloc(sizeof(stick_t));

    mst->map_size = map_size;
    mst->max_stick_taken = max_stick_taken;
    mst->map = mapping(map_size + 1);
    while (!is_game_end(mst->map)) {
        mst->map = game_fight(mst);
        if (!mst->map)
            return (0);
        if (is_game_end(mst->map))
            return (1);
        mst->map = ai_turn(mst->map, max_stick_taken);
        if (!mst->map)
            return (0);
        if (is_game_end(mst->map))
            return (2);
    }
    return (0);
}
