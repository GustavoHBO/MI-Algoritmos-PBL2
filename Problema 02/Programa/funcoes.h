#ifndef FUNCOES_H_INCLUDED
#define FUNCOES_H_INCLUDED

/*
*   Fun��o respons�vel por exibir o menu ao usu�rio.
*/

    int menu(void);


/*
*   Fun��o que busca o arquivo matriz.txt, se existir retorna 0 se n�o existir retorna 1.
*/
    int buscar_matriz(void);


/*
*   Fun��o que busca o arquivo de entrada, se existir retorna 0 se n�o retorna 1.
*/

    int buscar_entrada(void);


/*
*   Fun��o que gera matriz com base nas medalhas adicionadas.
*/

    void gerar_matriz(int [][5], int);


/*
*   Fun��o respons�vel por adicionar medalhas ao arquivo.txt.
*/

    void adicionar_medalhas(int, int*);

/*
*   Fun��o respons�vel por ler e gerar a matriz.
*/

    void ler_entrada(int matriz[][5]);


/*
*   Fun��o respons�vel por ler o aquivo de matriz;
*/

    void ler_matriz(int matriz[][5]);

/*
*   Fun��o respons�vel por gerar o ranking.
*/

    int gerar_ranking(int *);

/*
*   Fun��o respons�vel por ordenar a matriz pela quantidade total de medalhas na posi��o 3 da matriz.
*/

    void ordenar_total(int matriz[][5], int);

/*
*   Fun��o respons�vel por ordenar as medalhas por ouro / prata / bronze, (posi��o 0, 1, 3, respectivamente).
*/

    void ordenar_medalhas(int matriz[][5], int paises);

#endif // FUNCOES_H_INCLUDED
