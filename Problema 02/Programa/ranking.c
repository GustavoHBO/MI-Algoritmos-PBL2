#include <stdio.h>
#include "funcoes.h"

int gerar_ranking(int *condicao){

    int buscar = 0, buscar2 = 0, opcao = 0, paises = 0;

    FILE *arquivo;
    system("cls");

    buscar = buscar_entrada();
    buscar2 = buscar_matriz();
    if (buscar == 1 && buscar2 == 1){
        printf("Arquivo de entrada nao localizado!\n");
        return 1;
    }
    else if(buscar == 0 && buscar2 == 1){
        arquivo = fopen("entrada.txt", "r");
        opcao = 1;
    }
    else if (buscar == 1 && buscar2 == 0){
        arquivo = fopen("matriz.txt", "r");
        opcao = 2;
    }
    else{
        do{
            printf("Deseja exibir o ranking utilizando o arquivo de entrada ou arquivo editado\nanteriormente?\n\n");
            printf("1) Usar arquivo de entrada\t2) Usar o arquivo editado anteriormente\n");
            scanf("%d", &opcao);
            if (opcao == 1)
                arquivo = fopen("entrada.txt", "r");
            if (opcao == 2)
                arquivo = fopen("matriz.txt", "r");
        }while(opcao != 1 && opcao != 2);
    }
    fscanf(arquivo, "%d", &paises);
    fclose(arquivo);
    int matriz[paises][5];
    if (opcao == 1)
        ler_entrada(matriz);
    if (opcao == 2)
        ler_matriz(matriz);
    system("cls");
    int contp = 0, contm = 0, controle = 0, provas = 0;
    float porcentagem = 0;
    printf("\t\t*Ranking Detalhado*\n\n\n");
    printf("\t\tRanking ordenado pelo numero do pais:\n\n");
    printf("\t\tOuro\t\tPrata\t\tBronze\t\tTotal\n\n");
    for (contp = 0; contp < paises; contp++){// Aqui exibe o ranking ordenado pela numera��o do pa�s.
        printf("Pais [%d]\t", contp+1);
        for (contm = 0; contm < 4; contm++){
            printf("%2d\t\t", matriz[contp][contm]);
        }
        printf("\n");
    }
    ordenar_total(matriz, paises);

    /* Ranking definido pela quantidade total de medalhas*/
    printf("\n\n\t\tRanking Ordenado Pela Quantidade Total de Medalhas\n\n");
    printf("\t\tOuro\t\tPrata\t\tBronze\t\tTotal\n\n");
    for (contp = 0; contp < paises; contp++){// Aqui exibe o ranking ordenado pela quantidade total de medalhas
        printf("Pais [%d]\t", matriz[contp][4] + 1);
        for (contm = 0; contm < 4; contm++){
            printf("%2d\t\t", matriz[contp][contm]);
        }
        printf("\n");
    }
    /* Ranking ordenado pela quantidade de medalhas de ouro, prata, bronze, respectivamente.*/
    printf("\n\nRanking Ordenado Pela Quantidade Total de Ouro > Prata > Bronze > Ordem\n\n");
    printf("\t\tOuro\t\tPrata\t\tBronze\t\tTotal\n\n");

    ordenar_medalhas(matriz, paises);

    for (contp = 0; contp < paises; contp++){// Aqui exibe o ranking ordenado pela quantidade total de medalhas seguindo a ordem hierarquica
        printf("Pais [%d]\t", matriz[contp][4] + 1);// de Ouro > Prata > Bronze >> N�mero do pa�s.
        for (contm = 0; contm < 4; contm++){
            printf("%2d\t\t", matriz[contp][contm]);
        }
        printf("\n");
    }
    for(controle = 0; controle < paises; controle++){
        provas += matriz[controle][0];
    }
    /* Exibir a quantidade de provas disputadas.*/
    printf("\n\n\tQuantidade de provas disputadas ao encerrar o programa: %d\n\n", provas);
    porcentagem =(float) provas * 100 / 306; //Calculo respons�vel por exibir a porcentagem de provas disputadas.
    printf("\n\tPercentual de provas disputadas : %.2f%c\n\n\n", porcentagem, 37);

    do{
        printf("\nDeseja voltar para o menu?\n\n(1) Sim\t(2) Nao\n");
        scanf("%d", &controle);
    }while(controle != 1 && controle != 2);
    gerar_relatorio(paises, opcao);
    switch (controle){
    case 1:
        *condicao = 0;
        break;
    case 2:
        *condicao = 2;
        break;
    default:
        printf("Opcao invalida!\n");
        break;
    }
    return 0;
}

void ordenar_total(int matriz[][5], int paises){

    int contp = 0, contm = 0, controle = 0, controle2 = 0;

    for (contp = 0; contp < paises; contp++){
        for ( contm = contp; contm < paises; contm++){
            if ( matriz[contp][3] < matriz[contm][3] ){
                for (controle = 0; controle < 5; controle++){
                    controle2 = matriz[contp][controle];
                    matriz[contp][controle] = matriz[contm][controle];
                    matriz[contm][controle] = controle2;
                }
            }
            if ( matriz[contp][3] == matriz[contm][3] && matriz[contp][0] < matriz[contm][0] ){
                for (controle = 0; controle < 5; controle++){
                    controle2 = matriz[contp][controle];
                    matriz[contp][controle] = matriz[contm][controle];
                    matriz[contm][controle] = controle2;
                }
            }
            if ( matriz[contp][3] == matriz[contm][3] && matriz[contp][0] == matriz[contm][0] && matriz[contp][1] < matriz[contm][1]){
                for (controle = 0; controle < 5; controle++){
                    controle2 = matriz[contp][controle];
                    matriz[contp][controle] = matriz[contm][controle];
                    matriz[contm][controle] = controle2;
                }
            }
        }
    }
}

void ordenar_medalhas(int matriz[][5], int paises){

    int contp = 0, contm = 0, controle = 0, controle2 = 0;


    for (contp = 0; contp < paises; contp++){
        for(contm = contp; contm < paises; contm++){
            if ( matriz[contp][0] < matriz[contm][0]){
                for (controle = 0; controle < 5; controle++){
                    controle2 = matriz[contp][controle];
                    matriz[contp][controle] = matriz[contm][controle];
                    matriz[contm][controle] = controle2;
                }
            }
            if ( matriz[contp][0] == matriz[contm][0] && matriz[contp][1] < matriz[contm][1]){
                for (controle = 0; controle < 5; controle++){
                    controle2 = matriz[contp][controle];
                    matriz[contp][controle] = matriz[contm][controle];
                    matriz[contm][controle] = controle2;
                }
            }
            if ( matriz[contp][0] == matriz[contm][0] && matriz[contp][1] == matriz[contm][1] && matriz[contp][2] < matriz[contm][2]){
                for (controle = 0; controle < 5; controle++){
                    controle2 = matriz[contp][controle];
                    matriz[contp][controle] = matriz[contm][controle];
                    matriz[contm][controle] = controle2;
                }
            }
        }
    }
}
