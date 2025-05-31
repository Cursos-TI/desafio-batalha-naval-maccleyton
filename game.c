#include <stdio.h>

#define LINHAS 10
#define COLUNAS 10
#define TAMANHO 3

void batalhaNaval() { // Tabuleiro inicial da Batalha Naval, iniciando apenas com água (0)
    int tabuleiro[LINHAS][COLUNAS] = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
    };

    // Vetor com informações dos navios, ambos com tamanho igual a 3
    int navioH[TAMANHO] = {3, 3, 3}; // Localizado na horizontal
    int navioV[TAMANHO] = {3, 3, 3}; // Localizado na vertical
    int navioD1[TAMANHO] = {3, 3, 3}; // Localizado na diagonal principal
    int navioD2[TAMANHO] = {3, 3, 3}; // Localizado na diagonal secundária

    // Posição inicial dos navios, 1º navio na horizontal, 2º navio na vertical
    int linhaH = 1, colunaH = 7; // Índice (1,7) -> Linha 2 - Coluna 8
    int linhaV = 7, colunaV = 1; // Índice (7,1) -> Linha 8 - Coluna 2
    int linhaD1 = 2, colunaD1 = 0; // Índice (2,0) -> Linha 3 - Coluna 1
    int linhaD2 = 7, colunaD2 = 7; // Índice (7,7) -> Linha 8 - Coluna 8
    // Lembrando que eixo y = linha (j) e eixo x = coluna (i)

    // Validação se tamanho dos navios cabem no tabuleiro
    if (colunaH + 3 > 10) {
        printf("Erro! Navio não cabe no tabuleiro.\n");
    }

    if (linhaV + 3 > 10) {
        printf("Erro! Navio não cabe no tabuleiro.\n");
    }

    int sobreposicao = 0;
    
    // Sobreposição horizontal
    for (int i = 0; i < 3; i++) {
        if (tabuleiro[linhaH][colunaH + i] != 0) {
            sobreposicao = 1;
            break;
        }
    }

    // Sobreposição vertical
    for (int i = 0; i < 3; i++) {
        if (tabuleiro[linhaV + i][colunaV] != 0) {
            sobreposicao = 1;
            break;
        }
    }

    if (sobreposicao) {
        printf("Atenção! Os navios estão se sobrepondo!\n");
    }

    // Posicionando o navio horizontal
    for (int i = 0; i < 3; i++) {
        tabuleiro[linhaH][colunaH + i] = navioH[i];
    }

    // Posicionando o navio vertical
    for (int i = 0; i < 3; i++) {
        tabuleiro[linhaV + i][colunaV] = navioV[i];
    }

    // Posicionado o navio diagonal principal
    for (int i = 0; i < 3; i++) {
        tabuleiro[linhaD1 + i][colunaD1 + i] = navioD1[i];
    }

    // Posicionado o navio diagonal secundária
    for (int i = 0; i < 3; i++) {
        tabuleiro[linhaD2 + i][colunaD2 + i] = navioD2[i];
    }

    // Exibição do tabuleiro com os navios
    printf("\nTabuleiro de Batalha Naval:\n\n");
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main() { // Execução do código

    batalhaNaval();
    return 0;
}