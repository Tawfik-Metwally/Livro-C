#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    char inicio;
    system("cls");
    printf("-> Bem Vindo ao jogo de adivinhacao!\n");
    printf("-> Tente achar o numero secreto entre 0 e 100!\n");
    printf("-> Temos tres niveis de dificuldade (Facil/Medio/Dificl)\n");
    printf("-> Voce comeca com 1000 pontos, cada vez que errar, seus pontos vao diminuindo.\n");
    printf("-> Boa sorte!\n\n");
    printf("Aperte qualquer tecla e enter para comecar o jogo: ");
    scanf("%s", &inicio);
    system("cls");
    srand(time(0));
    int numeroSecreto = rand() % 101, numeroDeTentativas, nivel, chute, acertou;
    double pontos = 1000;

    printf("\nQual o nivel de dificuldade?\n\n");
    printf("(1) Facil\t(2) Medio\t(3) Dificil\n\n");
    printf("Escolha: ");
    scanf("%d", &nivel);

    switch (nivel)
    {
    case 1:
        numeroDeTentativas = 20;
        break;
    case 2:
        numeroDeTentativas = 15;
        break;
    default:
        numeroDeTentativas = 6;
        break;
    }

    for (int i = 1; i < numeroDeTentativas; i++)
    {
        printf("\n-> Tentativa %d de %d\n", i, numeroDeTentativas);
        printf("Chute um numero: ");
        scanf("%d", &chute);

        if (chute < 0)
        {
            printf("\nVoce nao pode chutar numeros negativos!\n\n");
            i--;
            continue;
        }

        acertou = chute == numeroSecreto;
        if (acertou)
        {
            break;
        }
        else if (chute > numeroSecreto)
        {
            printf("\nO seu chute foi maior que o numero secreto!\n");
        }
        else
        {
            printf("\nO seu chute foi menor que o numero secreto!\n");
        }

        double pontosPerdidos = abs(numeroSecreto - chute) / (double)2;
        pontos = pontos - pontosPerdidos;
    }
    if (acertou)
    {
        printf("\nParabens! Voce acertou!\n");
        printf("Voce fez %.2f pontos. Ate a proxima!\n\n", pontos);
    }
    else
    {

        printf("\nVoce perdeu! Tente novamente!\n\n");
    }
    return 0;
}