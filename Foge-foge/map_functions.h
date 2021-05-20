struct position
{
    int x;
    int y;
};

typedef struct position POSITION;

struct map
{
    char **matrix;
    int rows;
    int columns;
};

typedef struct map MAP;

void searchMap(MAP *m, POSITION *p, char);
void readMap(MAP *m);
void allocateMap(MAP *m);
void freeMap(MAP *m);
void printMap(MAP *m);