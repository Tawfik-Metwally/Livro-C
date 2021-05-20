#include <stdio.h>
#include <stdlib.h>
#include "RNE_functions.h"
#include "map_functions.h"

MAP m;
POSITION hero;

int main()
{
    readMap(&m);
    searchMap(&m, &hero, '@');

    do
    {
        printMap(&m);

        char command;
        scanf(" %c", &command);

        move(command);
    } while (!finish());

    freeMap(&m);
    return 0;
}

void move(char direction)
{
    m.matrix[hero.x][hero.y] = '.';

    switch (direction)
    {
    case 'a':
        m.matrix[hero.x][hero.y - 1] = '@';
        hero.y--;
        break;
    case 'd':
        m.matrix[hero.x][hero.y + 1] = '@';
        hero.y++;
        break;
    case 'w':
        m.matrix[hero.x - 1][hero.y] = '@';
        hero.x--;
        break;
    case 's':
        m.matrix[hero.x + 1][hero.y] = '@';
        hero.x++;
        break;
    }
}

int finish()
{
    return 0;
}