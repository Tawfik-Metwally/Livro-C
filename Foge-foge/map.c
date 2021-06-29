#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "map_fun.h"

void readMap(MAP *m)
{
    FILE *f;

    f = fopen("map.txt", "r");

    if (f == 0)
    {
        printf("Map reading error");
        exit(1);
    }

    fscanf(f, "%d %d", &(m->rows), &(m->columns));
    allocateMap(m);

    for (int i = 0; i < 5; i++)
    {
        fscanf(f, "%s", m->matrix[i]);
    }

    fclose(f);
}

void allocateMap(MAP *m)
{
    m->matrix = malloc(sizeof(char *) * m->rows);

    for (int i = 0; i < m->rows; i++)
    {
        m->matrix[i] = malloc(sizeof(char) * m->columns + 1);
    }
}

void freeMap(MAP *m)
{
    for (int i = 0; i < m->rows; i++)
    {
        free(m->matrix[i]);
    }
    free(m->matrix);
}

int searchMap(MAP *m, POSITION *p, char c)
{
    for (int i = 0; i < m->rows; i++)
    {
        for (int j = 0; j < m->columns; i++)
        {
            if (m->matrix[i][j] == HERO)
            {
                p->x = i;
                p->y = j;
                return 1;
            }
        }
    }
    return 0;
}

int itsValid(MAP *m, int x, int y)
{
    if (x >= m->rows)
        return 0;
    if (y >= m->columns)
        return 0;
    return 1;
}

int itsWall(MAP *m, int x, int y)
{
    return m->matrix[x][y] == VERTICAL_WALL ||
           m->matrix[x][y] == HORIZONTAL_WALL;
}

int itsCharacter(MAP *m, char character, int x, int y)
{
    return m->matrix[x][y] == character;
}

void walkInMap(MAP *m, int xorigin, int yorigin, int xdestination, int ydestination)
{
    char character = m->matrix[xorigin][yorigin];
    m->matrix[xdestination][ydestination] = character;
    m->matrix[xorigin][yorigin] = EMPTY;
}

void copyMap(MAP *destin, MAP *origin)
{
    destin->rows = origin->rows;
    destin->columns = origin->columns;
    allocateMap(destin);
    for (int i = 0; i < origin->rows; i++)
    {
        strcpy(destin->matrix[i], origin->matrix[i]);
    }
}

int canWalk(MAP *m, char character, int x, int y)
{
    return itsValid(m, x, y) &&
           !itsWall(m, x, y) &&
           !itsCharacter(m, character, x, y);
}