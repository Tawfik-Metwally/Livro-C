#include <stdio.h>
#include <stdlib.h>
#include "RNE_functions.h"
#include "map_functions.h"

MAP m;
POSITION hero;

int main()
{
    readMap(&m);
    searchMap(&m, &hero, HERO);

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
    if (!itsDirection(direction))
        return;

    int nextx = hero.x;
    int nexty = hero.y;

    switch (direction)
    {
    case LEFT:
        nexty--;
        break;
    case UP:
        nextx--;
        break;
    case DOWN:
        nextx++;
        break;
    case RIGHT:
        nexty++;
        break;
    }

    if (!itsValid(&m, nextx, nexty))
        return;
    if (!itsEmpty(&m, nextx, nexty))
        return;

    walkInMap(&m, hero.x, hero.y, nextx, nexty);
    hero.x = nextx;
    hero.y = nexty;
}

int itsDirection(char direction)
{
    return direction == LEFT ||
           direction == UP ||
           direction == DOWN ||
           direction == RIGHT;
}

int finish()
{
    return 0;
}