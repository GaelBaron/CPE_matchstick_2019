/*
** EPITECH PROJECT, 2020
** stick.h
** File description:
** Gael Baron's stick.h made the 01/07/2020
*/

#ifndef STICK_H
#define STICK_H

#include "my.h"
#include <stdlib.h>
#include <stdio.h>

#ifndef NOT_END
#define NOT_END 0
#endif
#ifndef PLAYER_WIN
#define PLAYER_WIN 1
#endif
#ifndef AI_WIN
#define AI_WIN 2
#endif
#ifndef NOT_A_NB
#define NOT_A_NB 1
#endif
#ifndef CANT_MATCH
#define CANT_MATCH 2
#endif
#ifndef EMPTY_LINE
#define EMPTY_LINE 3
#endif
#ifndef TOO_BIG
#define TOO_BIG 4
#endif
#ifndef TOO_SMALL
#define TOO_SMALL 5
#endif

typedef struct stick_structure
{
    int map_size;
    int max_stick_taken;
    char **map;
} stick_t;

char **player_turn(char **map, int line, int stick);

/*mapping.c*/
char **mapping(int map_size);
char **fir_tree(int map_size, int i, char **map, int *space_nb);

/*matchstick.c*/
int is_game_end(char **map);
char **game_fight(stick_t *mst);
int is_game_end(char **map);
void print_interface(char **map);
int matchstick(int map_size, int max_stick_taken);

/*error.c*/
int too_big(int nb, stick_t *mst);
int too_small_line(stick_t *mst, char *buff, int line);
int are_sticks_all_ok(stick_t *mst, char *buff, int line);
int stick_errors(stick_t *mst, int line);

/*game.c*/
char *delete_n(char *buff);
void print_error(int err);
int is_a_number(char *buff);
int is_possible(char *buff);
int are_they_all_ok(stick_t *mst, char *buff);

/*ai.c*/
char **ai_turn(char **map, int max);

void split_bigger(int *tmp, int *tmp_l, char **map, int max);
int line_nb(char *str);

#endif
