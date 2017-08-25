#include <stdio.h>

void gerar_relatorio(int paises, int opcao){

    FILE *arquivo;
    arquivo = fopen("Relat�rio.txt", "w");
    int matriz[paises][5], cont = 0, cont2 = 0, provas = 0;
    float porcentagem = 0;
    ler_entrada(matriz);
    fprintf(arquivo, "\t\tQuadro de Medalhas Inicial (Antes da Adi��o de Medalhas).\n\n");
    fprintf(arquivo, "\n\tOuro\t|\tPrata\t|\tBronze\t|\tTotal\n\n");
    for ( cont = 0; cont < paises; cont++ ){
        fprintf(arquivo, "[P%d]\t", matriz[cont][4]+1);
        for ( cont2 = 0; cont2 < 4; cont2++ ){
            fprintf(arquivo, "%d\t\t", matriz[cont][cont2]);
        }
    fprintf(arquivo, "\n");
    }
    ordenar_medalhas(matriz, paises);
    fprintf(arquivo, "\n\n\n\t\tRanking com Desempenho Inicial dos Pa�ses\n\n");
    fprintf(arquivo, "\n\tOuro\t|\tPrata\t|\tBronze\t|\tTotal\n\n");
    for ( cont = 0; cont < paises; cont++ ){
        fprintf(arquivo, "[P%d]\t", matriz[cont][4]+1);
        for ( cont2 = 0; cont2 < 4; cont2++ ){
            fprintf(arquivo, "%d\t\t", matriz[cont][cont2]);
        }
    fprintf(arquivo, "\n");
    }
    ordenar_total(matriz, paises);
    fprintf(arquivo, "\n\n\t\tQuadro Ordenado pela Quantidade Total de Medalhas\n\n");
    fprintf(arquivo, "\n\tOuro\t|\tPrata\t|\tBronze\t|\tTotal\n\n");
    for ( cont = 0; cont < paises; cont++ ){
        fprintf(arquivo, "[P%d]\t", matriz[cont][4]+1);
        for ( cont2 = 0; cont2 < 4; cont2++ ){
            fprintf(arquivo, "%d\t\t", matriz[cont][cont2]);
        }
    fprintf(arquivo, "\n");
    }
    if(opcao == 1)
        ler_entrada(matriz);
    if (opcao == 2)
        ler_matriz(matriz);
    fprintf(arquivo, "\n\n\n\t\tRanking com Desempenho dos Pa�ses Ordenado Pela Numera��o (ao Encerrar o Programa).\n\n");
    fprintf(arquivo, "\n\tOuro\t|\tPrata\t|\tBronze\t|\tTotal\n\n");
    for ( cont = 0; cont < paises; cont++ ){
        fprintf(arquivo, "[P%d]\t", matriz[cont][4]+1);
        for ( cont2 = 0; cont2 < 4; cont2++ ){
            fprintf(arquivo, "%d\t\t", matriz[cont][cont2]);
        }
    fprintf(arquivo, "\n");
    }
    ordenar_total(matriz, paises);
    fprintf(arquivo, "\n\n\t\tQuadro Ordenado Pela Quantidade Total de Medalhas Recebidas\n\n");
    fprintf(arquivo, "\n\tOuro\t|\tPrata\t|\tBronze\t|\tTotal\n\n");
    for ( cont = 0; cont < paises; cont++ ){
        fprintf(arquivo, "[P%d]\t", matriz[cont][4]+1);
        for ( cont2 = 0; cont2 < 4; cont2++ ){
            fprintf(arquivo, "%d\t\t", matriz[cont][cont2]);
        }
    fprintf(arquivo, "\n");
    }
    ordenar_medalhas(matriz, paises);
    fprintf(arquivo, "\n\n\t\tQuadro Ordenado pela Quantidade de Medalhas\n\n");
    fprintf(arquivo, "\n\tOuro\t|\tPrata\t|\tBronze\t|\tTotal\n\n");
    for ( cont = 0; cont < paises; cont++ ){
        fprintf(arquivo, "[P%d]\t", matriz[cont][4]+1);
        for ( cont2 = 0; cont2 < 4; cont2++ ){
            fprintf(arquivo, "%d\t\t", matriz[cont][cont2]);
        }
    fprintf(arquivo, "\n");
    }
    for(cont = 0; cont < paises; cont++){
        provas += matriz[cont][0];
    }
    /* Exibir a quantidade de provas disputadas.*/
    fprintf(arquivo, "\n\n\tQuantidade de provas disputadas ao encerrar o programa: %d\n\n", provas);
    porcentagem =(float) provas * 100 / 306; //Calculo respons�vel por exibir a porcentagem de provas disputadas.
    fprintf(arquivo, "\n\tPercentual de provas disputadas : %.2f%c\n\n\n", porcentagem, 37);
    fclose(arquivo);
}
