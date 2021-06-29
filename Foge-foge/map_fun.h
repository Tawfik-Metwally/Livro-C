#ifndef _MAP_FUN_H_
#define _MAP_FUN_H_

#define HERO '@'
#define EMPTY '.'
#define VERTICAL_WALL '|'
#define HORIZONTAL_WALL '-'
#define GHOST 'G'
#define PILL 'P'

struct map
{
    char **matrix;
    int rows;
    int columns;
};

typedef struct map MAP;

void readMap(MAP *m);
void allocateMap(MAP *m);
void freeMap(MAP *m);

struct position
{
    int x;
    int y;
};

typedef struct position POSITION;

int searchMap(MAP *m, POSITION *p, char);
int itsValid(MAP *m, int, int);
int itsWall(MAP *m, int, int);
int itsCharacter(MAP *m, char, int, int);
void walkInMap(MAP *m, int, int, int, int);
void copyMap(MAP *destin, MAP *origin);
int canWalk(MAP *m, char, int, int);

#endif