#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "forcaFuncoes.h"
int main()
{
    /*char palavra[20];
    sprintf(palavra, "melancia");
    int tamanho = strlen(palavra);
    int i = 12;
    int vdd = i < strlen(palavra);
    printf("%s,%d,%d", palavra, tamanho, vdd);
*/
    char chute;

    printf("\n\nChute uma letra: ");
    scanf(" %c", &chute);
    chute = toupper(chute);
    printf("%c", chute);

    char novaPalavra[TAMANHO_PALAVRA];
    printf("Digite a nova palavra: ");
    scanf("%s", novaPalavra);
    for (int i = 0; i <= strlen(novaPalavra); i++)
    {
        novaPalavra[i] = toupper(novaPalavra[i]);
    }
    printf("%s", novaPalavra);

    return 0;
}
