#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "forcaFuncoes.h"

char palavraSecreta[TAMANHO_PALAVRA], chutes[TAMANHO_PALAVRA + 6];
int chutesDados = 0;
int querJogar = 0;

int main()
{
    abertura();
    escolhePalavra();

    do
    {
        desenhaForca();
        chuta();
    } while (!ganhou() && !enforcou());

    system("cls");
    desenhaForca();

    if (ganhou())
    {
        printf("\n\n\t**Parabens, voce ganhou!**\n\n");

        printf("\t       ___________      \n");
        printf("\t      '._==_==_=_.'     \n");
        printf("\t      .-\\:      /-.    \n");
        printf("\t     | (|:.     |) |    \n");
        printf("\t      '-|:.     |-'     \n");
        printf("\t        \\::.    /      \n");
        printf("\t         '::. .'        \n");
        printf("\t           ) (          \n");
        printf("\t         _.' '._        \n");
        printf("\t        '-------'       \n\n");
    }
    else
    {
        printf("\n\n   **Infelizmente voce foi inforcado!**\n");
        printf("\t A palavra era **%s**\n\n", palavraSecreta);

        printf("\t    _______________         \n");
        printf("\t   /               \\       \n");
        printf("\t  /                 \\      \n");
        printf("\t//                   \\/\\  \n");
        printf("\t\\|   XXXX     XXXX   | /   \n");
        printf("\t |   XXXX     XXXX   |/     \n");
        printf("\t |   XXX       XXX   |      \n");
        printf("\t |                   |      \n");
        printf("\t \\__      XXX      __/     \n");
        printf("\t   |\\     XXX     /|       \n");
        printf("\t   | |           | |        \n");
        printf("\t   | I I I I I I I |        \n");
        printf("\t   |  I I I I I I  |        \n");
        printf("\t   \\_             _/       \n");
        printf("\t     \\_         _/         \n");
        printf("\t       \\_______/           \n");
    }

    adicionarPalavra();

    return 0;
}

void abertura()
{
    system("cls");
    printf("\n***************************\n");
    printf("BEM-VINDO AO JOGO DA FORCA!\n");
    printf("***************************\n\n");
}

void escolhePalavra()
{
    FILE *f;

    f = fopen("forcaPalavras.txt", "r");

    if (f == 0)
    {
        printf("Banco de dados de palavras indisponivel\n\n");
        exit(1);
    }

    int qtdDePalavras;
    fscanf(f, "%d", &qtdDePalavras);

    srand(time(0));
    int posicaoSecreta = rand() % qtdDePalavras;
    for (int i = 0; i <= posicaoSecreta; i++)
    {
        fscanf(f, "%s", palavraSecreta);
    }

    fclose(f);
}

void desenhaForca()
{
    int erros = chutesErrados();

    printf("  _______       \n");
    printf(" |/      |      \n");
    printf(" |      %c%c%c  \n", (erros >= 1 ? '(' : ' '), (erros >= 1 ? '_' : ' '), (erros >= 1 ? ')' : ' '));
    printf(" |      %c%c%c  \n", (erros >= 3 ? '\\' : ' '), (erros >= 2 ? '|' : ' '), (erros >= 3 ? '/' : ' '));
    printf(" |       %c     \n", (erros >= 2 ? '|' : ' '));
    printf(" |      %c %c   \n", (erros >= 4 ? '/' : ' '), (erros >= 4 ? '\\' : ' '));
    printf(" |              \n");
    printf("_|___           \n");
    printf("\n");

    for (int i = 0; i < strlen(palavraSecreta); i++)
    {
        if (jaChutou(palavraSecreta[i]))
        {
            printf("%c ", palavraSecreta[i]);
        }
        else
        {
            printf("_ ");
        }
    }
}

int chutesErrados()
{
    int erros = 0;

    for (int i = 0; i < chutesDados; i++)
    {
        if (!letraExiste(chutes[i]))
        {
            erros++;
        }
    }
    return erros;
}

int letraExiste(char letra)
{
    for (int j = 0; j < strlen(palavraSecreta); j++)
    {
        if (letra == palavraSecreta[j])
        {
            return 1;
        }
    }
    return 0;
}

int jaChutou(char letra)
{
    int achou = 0;
    for (int j = 0; j < chutesDados; j++)
    {
        if (chutes[j] == letra)
        {
            achou = 1;
            break;
        }
    }
    return achou;
}

void chuta()
{
    char chute;
    char continuar;

    printf("\n\nChute uma letra: ");
    scanf(" %c", &chute);

    system("cls");

    if (letraExiste(chute))
    {
        printf("Voce acertou! A palavra tem a letra '%c'\n", chute);
    }
    else
    {
        printf("Voce errou! A palavra nao tem a letra '%c'\n", chute);
    }

    /*printf("Aperte qualquer tecla e enter para continuar o jogo: \n\n");
    scanf(" %c", &continuar);*/

    chutes[chutesDados] = chute;
    chutesDados++;
}

int ganhou()
{
    for (int i = 0; i < strlen(palavraSecreta); i++)
    {
        if (!jaChutou(palavraSecreta[i]))
        {
            return 0;
        }
    }
    return 1;
}

int enforcou()
{
    return chutesErrados() >= 5;
}

void adicionarPalavra()
{
    char quer;

    printf("Voce deseja adicionar uma nova palavra no jogo (S/N)? ");
    scanf(" %c", &quer);

    if (quer == 'S')
    {
        char novaPalavra[TAMANHO_PALAVRA];

        printf("Digite a nova palavra: ");
        scanf("%s", novaPalavra);

        FILE *f;

        f = fopen("forcaPalavras.txt", "r+");
        if (f == 0)
        {
            printf("Banco de dados de palavras indisponivel\n\n");
            exit(1);
        }

        int qtd;
        fscanf(f, "%d", &qtd);
        qtd++;
        fseek(f, 0, SEEK_SET);
        fprintf(f, "%d", qtd);

        fseek(f, 0, SEEK_END);
        fprintf(f, "\n%s", novaPalavra);

        fclose(f);
    }
}

