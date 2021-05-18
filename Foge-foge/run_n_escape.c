#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *f;
    char map[5][10 + 1];

    f = fopen("map.txt", "r");

    if (f == 0)
    {
        printf("Map reading error");
        exit(1);
    }

    for (int i = 0; i < 5; i++)
    {
        fscanf(f, "%s", map[i]);
    }

    for (int i = 0; i < 5; i++)
    {
        printf("%s\n", map[i]);
    }

    fclose(f);

    return 0;
}
