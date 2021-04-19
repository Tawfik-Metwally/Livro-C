#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main()
{
    char palavra[20];
    sprintf(palavra, "melancia");
    int tamanho = strlen(palavra);
    int i = 12;
    int vdd = i < strlen(palavra);
    printf("%s,%d,%d", palavra, tamanho, vdd);

    return 0;
}
