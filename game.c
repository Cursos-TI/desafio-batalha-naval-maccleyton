#include <stdio.h>

void batalhaNaval() { // Tabuleiro inicial da Batalha Naval, iniciando apenas com água (0)
    int tabuleiro[10][10] = {
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
    int navioH[3] = {3, 3, 3}; // Localizado na horizontal
    int navioV[3] = {3, 3, 3}; // Localizado na vertical

    // Posição inicial dos navios, 1º navio na horizontal, 2º navio na vertical
    int linhaH = 1, colunaH = 7; // Índice (1,7) -> Linha 2 - Coluna 8
    int linhaV = 7, colunaV = 1; // Índice (7,1) -> Linha 8 - Coluna 2
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