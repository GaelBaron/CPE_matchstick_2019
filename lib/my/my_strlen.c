/*
** EPITECH PROJECT, 2019
** my_strlen
** File description:
** strlen
*/

int my_strlen(char *str)
{
    int i = 0;

    while (str[i] != '\0')
        i++;
    return (i);
}
