#include <stdio.h>

#define LINHAS 10
#define COLUNAS 10

int tabuleiro[LINHAS][COLUNAS]; // Tabuleiro global
char simbolo;
int l, c; // Variáveis globais para linha e coluna

void tabuleiroGrafico() {
    if (tabuleiro[l][c] == 2) {
        simbolo = '~';  // Água
    } else if (tabuleiro[l][c] == 3) {
        simbolo = 'O';  // Navio
    } else {
        simbolo = ' ';  // Vazio
    }
    printf("%c ", simbolo);
}

void inicializaTabuleiro() {
    for (int i = 0; i < LINHAS; i++) {
        for (int j = 0; j < COLUNAS; j++) {
            tabuleiro[i][j] = 2; // Inicializa com água
        }
    }
}

// Função para exibir o tabuleiro gráfico
void exibirTabuleiro() {
    // Exibição do tabuleiro com coordenadas
    printf("\nTabuleiro de Batalha Naval:\n\n");

    // Cabeçalho das colunas (A, B, C...)
    printf("   ");
    for (int c = 0; c < COLUNAS; c++) {
        printf("%c ", 'A' + c);
    }
    printf("\n");

    // Linhas numeradas com os valores do tabuleiro
    for (int l = 0; l < LINHAS; l++) {
        printf("%2d ", l + 1);  // Linha numerada (1 a 10)
        for (int c = 0; c < COLUNAS; c++) {
            printf("%d ", tabuleiro[l][c]);
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
    exibirTabuleiro();
    return 0;
}