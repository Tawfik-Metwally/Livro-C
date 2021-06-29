#include <stdio.h>
#include <stdlib.h>
#include "time.h"
#include "RNE_fun.h"
#include "map_fun.h"
#include "ui.h"

MAP m;
POSITION hero;
int hasPill = 0;

int main()
{
    readMap(&m);
    searchMap(&m, &hero, HERO);

    do
    {
        printf("Pill: %s\n", (hasPill ? "YES" : "NO"));
        printMap(&m);

        char command;
        scanf(" %c", &command);

        if (itsDirection(command))
            move(command);
        if (command == BOMB)
            explodePill();

        ghosts();

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

    if (!canWalk(&m, HERO, nextx, nexty))
        return;
    if (itsCharacter(&m, PILL, nextx, nexty))
        hasPill = 1;

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

void explodePill()
{
    if (!hasPill)
        return;

    explodePill2(hero.x, hero.y, 0, 1, 3);
    explodePill2(hero.x, hero.y, 0, -1, 3);
    explodePill2(hero.x, hero.y, 1, 0, 3);
    explodePill2(hero.x, hero.y, -1, 0, 3);

    hasPill = 0;
}

void explodePill2(int x, int y, int sumx, int sumy, int qty)
{

    if (qty == 0)
        return;

    int newx = x + sumx;
    int newy = y + sumy;

    if (!itsValid(&m, newx, newy))
        return;
    if (itsWall(&m, newx, newy))
        return;

    m.matrix[x][y + 1] = EMPTY;
    explodePill2(newx, newy, sumx, sumy, qty - 1);
}

void ghosts()
{
    MAP copy;

    copyMap(&copy, &m);

    for (int i = 0; i < copy.rows; i++)
    {
        for (int j = 0; j < copy.columns; j++)
        {
            if (copy.matrix[i][j] == GHOST)
            {
                int xdestin;
                int ydestin;

                int found = whereGhostGoes(i, j, &xdestin, &ydestin);

                if (found)
                {
                    walkInMap(&m, i, j, xdestin, ydestin);
                }
            }
        }
    }
    freeMap(&copy);
}

int whereGhostGoes(int xorigin, int yorigin, int *xdestin, int *ydestin)
{
    int options[4][2] = {
        {xorigin, yorigin + 1},
        {xorigin + 1, yorigin},
        {xorigin, yorigin - 1},
        {xorigin - 1, yorigin},
    };

    srand(time(0));
    for (int i = 0; i < 10; i++)
    {
        int position = rand() % 4;

        if (canWalk(&m, GHOST, options[position][0], options[position][1]))
        {
            *xdestin = options[position][0];
            *ydestin = options[position][1];
            return 1;
        }
    }
    return 0;
}

int finish()
{
    POSITION pos;

    int lose = !searchMap(&m, &pos, HERO);
    int win = !searchMap(&m, &pos, GHOST);

    return win || lose;
}