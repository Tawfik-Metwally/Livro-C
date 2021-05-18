#include <stdio.h>
#include <stdlib.h>
#include "RNE_functions.h"

char **map;
int rows;
int columns;

int main()
{
    readmap();

    for (int i = 0; i < 5; i++)
    {
        printf("%s\n", map[i]);
    }

    freemap();
    return 0;
}

void readmap()
{
    FILE *f;

    f = fopen("map.txt", "r");

    if (f == 0)
    {
        printf("Map reading error");
        exit(1);
    }

    fscanf(f, "%d %d", &rows, &columns);
    allocatemap();

    for (int i = 0; i < 5; i++)
    {
        fscanf(f, "%s", map[i]);
    }

    fclose(f);
}

void allocatemap()
{
    map = malloc(sizeof(char *) * rows);

    for (int i = 0; i < rows; i++)
    {
        map[i] = malloc(sizeof(char) * columns + 1);
    }
}

void freemap()
{
    for (int i = 0; i < rows; i++)
    {
        free(map[i]);
    }
    free(map);
}