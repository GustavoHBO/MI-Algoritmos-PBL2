/*******************************************************************************
Autor: Gustavo Henrique
Componente Curricular: MI - Algoritmos
Concluido em: 07/09/2015
Declaro que este código foi elaborado por mim de forma individual e não contém nenhum
trecho de código de outro colega ou de outro autor, tais como provindos de livros e
apostilas, e páginas ou documentos eletrônicos da Internet. Qualquer trecho de código
de outra autoria que não a minha está destacado com uma citação para o autor e a fonte
do código, e estou ciente que estes trechos não serão considerados para fins de avaliação.
******************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"

int main(){

    int opcao = 0, condicao = 0;
    system("color 1f");
    do{
        opcao = menu();
        switch (opcao){//Para controlar as opções do menu utilizei switch case.
            case 1:
                system("cls");
                int matriz = buscar_matriz();
                int entrada = buscar_entrada();
                if ( entrada == 1 && matriz == 1){
                    printf("Arquivo de entrada nao localizado!\n\n");
                    return 1;
                }
                else if(entrada == 0 && matriz == 0){
                    printf("Deseja adicionar medalhas ao arquivo salvo anteriormente?\n\n");
                    printf("(1)Sim, usar o arquivo salvo anteriormente.\t(2)Nao, usar arquivo de entrada.\n");
                    do{
                        scanf("%d", &opcao);
                        if (opcao == 1 || opcao == 2){
                            adicionar_medalhas(opcao, &condicao);
                        }
                    }while(opcao != 1 && opcao != 2);
                }
                else if (entrada == 1 && matriz == 0){
                    adicionar_medalhas(1, &condicao);
                }
                else{
                    adicionar_medalhas(2, &condicao);
                }
                break;
            case 2:
                gerar_ranking(&condicao);// Função de exibição do ranking.
                if ( condicao == 2 )
                    return 1;
                break;
            case 3:
                return 0;
                break;
            default:
                printf("Opcao invalida!");
                break;
        }
    }while(condicao != 1 && condicao !=2 && condicao != 3);
    return 0;
}

int menu(void){ // Função responsável por exibir o menu ao usuário e chamar a função correta.

    system("cls");
    int opcao = 0;
    printf("Digite o numero correspondente a cada opcao:\n\n");//Aqui inica-se o menu.
    printf("(1)Adicionar medalhas\t(2)Exibir ranking detalhado e Gerar Relatorio\t(3)Sair\n");
    scanf("%d", &opcao);

    return opcao;
}

int buscar_matriz(void){// Função que busca o arquivo matriz.txt, se existir retorna 0 se não existir retorna 1.

    FILE *arquivo;
    arquivo = fopen("matriz.txt", "r");
    if ( arquivo == NULL){
        fclose(arquivo);
        return 1;
    }
    fclose(arquivo);
    return 0;
}

int buscar_entrada(void){//Função que busca o arquivo de entrada, se existir retorna 0 se não retorna 1.

    FILE *arquivo;
    arquivo = fopen("entrada.txt", "r");
    if (arquivo == NULL){
        fclose(arquivo);
        return 1;
    }
    fclose(arquivo);
    return 0;
}

void ler_entrada (int matriz[][5]){

    int paises = 0, modalidades = 0, cont = 0, cont2 = 0, cont3 = 0, medalhas = 0;
    FILE *arquivo;
    arquivo = fopen("entrada.txt", "r");
    fscanf(arquivo, "%d %d", &paises, &modalidades);
    for ( cont = 0; cont < paises; cont++ )
        for ( cont2 = 0; cont2 < 5; cont2++ )
            matriz[cont][cont2] = 0;
    for ( cont = 0; cont < paises; cont++ ){
        for ( cont2 = 0; cont2 < modalidades; cont2++ ){
            for ( cont3 = 0; cont3 < 3; cont3++ ){
                fscanf(arquivo, "%d", &medalhas);
                matriz[cont][cont3] += medalhas;
                matriz[cont][3] += medalhas;
            }
        }
        matriz[cont][4] = cont;
    }
    fclose(arquivo);
}

void adicionar_medalhas (int condicao, int *opcao){// Função responsável por adicionar medalhas ao país que o usuário escolher.

    /* Condição irá ter o valor passado pela função que chama ela, que no caso é a main, então irá ter o valor da escolha do usuário,
    de usar o arquivo de entrada.txt = 1, ou usar matriz.txt = 2, valores diferentes destes não são passados.*/
    int paises = 0, cont = 0;
    FILE *arquivo;
    if ( condicao == 2 ){
        arquivo = fopen("entrada.txt", "r");
    }
    else if(condicao == 1){
        arquivo = fopen("matriz.txt", "r");
    }
    fscanf(arquivo, "%d", &paises);
    fclose(arquivo);
    int matriz[paises][5];
    if ( condicao == 2 ){// Se existir o arquivo matriz.txt ele vai passar a matriz para receber os valores contidos no arquivo.
        ler_entrada(matriz);
    }
    else if(condicao == 1)// Se existir o arquivo entrada.txt ele vai passar a matriz para receber os valores contidos no arquivo.
        ler_matriz(matriz);
    printf("Quadro atual de medalhas:\n\n");
    do{
        system("cls");
        printf("Digite o numero correspondente ao pais que deseja adicionar medalhas :\n\n");
        printf("    \t   Ouro | Prata  | Bronze\n");
        for (cont = 0; cont < paises; cont++){
            printf("Pais [%d]  [%2d   |   %2d   |   %2d]\n", cont+1, matriz[cont][0], matriz[cont][1], matriz[cont][2]);
        }
        do{
            printf("Medalha de Ouro : \n>> ");
            scanf("%d", &cont);
            cont--;
            if(cont >= paises || cont < 0){
                printf("Pais Invalido!\n");
            }
            else
                matriz[cont][0]++;
        }while(cont >= paises || cont < 0);
        do{
            printf("Medalha de Prata :\n>>");
            scanf("%d", &cont);
            cont--;
            if(cont >= paises || cont < 0){
                printf("Pais Invalido!\n");
            }
            else
                matriz[cont][1]++;
        }while(cont >= paises || cont < 0);
        do{
            printf("Medalha de Bronze :\n>>");
            scanf("%d", &cont);
            cont--;
            if(cont >= paises || cont < 0){
                printf("Pais Invalido!\n");
            }
            else
                matriz[cont][2]++;
        }while(cont >= paises || cont < 0);
        do{
            printf("Adicionar mais medalhas?\n");
            printf("(1)Adicionar\t\t(2)Voltar ao menu\n");
            scanf("%d", &cont);
            if (cont != 1 && cont != 2){
                printf("Opcao Invalida!\n");
            }
            if (cont == 2){
                gerar_matriz(matriz, paises);
                system("cls");
                *opcao = 0;
            }
        }while(cont != 1 && cont != 2);
    }while(cont==1);
}

void gerar_matriz(int matriz[][5], int paises){

    int cont = 0, cont2 = 0;
    FILE *arquivo;
    arquivo = fopen("matriz.txt", "w");
    fprintf(arquivo, "%d\n", paises);
    for (cont = 0; cont < paises; cont++){
        for(cont2 = 0; cont2 < 3; cont2++){
            fprintf(arquivo, "%d ", matriz[cont][cont2]);
        }
        fprintf(arquivo, "\n");
    }
    fclose(arquivo);
}

void ler_matriz(int matriz[][5]){

    int cont = 0, cont2 = 0, paises = 0;
    FILE *arquivo;
    arquivo = fopen("matriz.txt", "r");
    fscanf(arquivo, "%d", &paises);
    for(cont = 0; cont < paises; cont++){
        matriz[cont][4] = cont;
        for(cont2 = 0; cont2 < 3; cont2++){
            fscanf(arquivo, "%d", &matriz[cont][cont2]);
        }
        matriz[cont][3]  = 0;
    }
    for(cont = 0; cont < paises; cont++){ // para
        for(cont2 = 0; cont2 < 3; cont2++){
            matriz[cont][3] += matriz[cont][cont2];
        }
    }
    fclose(arquivo);
}
