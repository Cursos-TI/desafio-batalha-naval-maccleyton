#include <stdio.h>
#include <stdlib.h> // Para a função abs
// A função abs é usada para calcular o valor absoluto da diferença entre as coordenadas

#define HABILIDADESLIN 5
#define HABILIDADESCOL 5
#define LINHAS 10
#define COLUNAS 10
#define TAMANHO 3

int tabuleiro[LINHAS][COLUNAS]; // Seu tabuleiro maior
int habilidade[HABILIDADESLIN][HABILIDADESCOL];  // Matriz da habilidade
int origemLinha = 4;   // Exemplo
int origemColuna = 5;  // Exemplo
int meio = 5 / 2;      // Para centralizar, meio da matriz de habilidade

void cone() { // Ataca inimigos em uma área circular ao redor do personagem
    int matriz[HABILIDADESLIN][HABILIDADESCOL];

    for (int i = 0; i < HABILIDADESLIN; i++) {
        for (int j = 0; j < HABILIDADESCOL; j++) {
            // Condição para formar o cone (triângulo inverso)
            if (i == 0 && j == 2) {
                matriz[i][j] = 1; // Borda do tabuleiro
            } else if (i == 1 && (j >= 1 && j <= 3)) {
                matriz[i][j] = 1; // Borda do tabuleiro
            } else if (i == 2 && (j >= 0 && j <= 4)) {
                matriz[i][j] = 1; // Borda do tabuleiro
            } else {
                matriz[i][j] = 0; // Espaço vazio
            }
        }
    }

    // Exibe a matriz da habilidade Cone de Fogo
    printf("Habilidade -> Cone de Fogo 🔥\n");
    for (int i = 0; i < HABILIDADESLIN; i++) {
        for (int j = 0; j < HABILIDADESCOL; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void cruz() { // Ataca inimigos em linha reta na horizontal e vertical
    int matriz[HABILIDADESLIN][HABILIDADESCOL];

    for (int i = 0; i < HABILIDADESLIN; i++) {
        for (int j = 0; j < HABILIDADESCOL; j++) {
            // Condição para formar a cruz
            if (i == 2 || j == 2) {
                matriz[i][j] = 1; // Borda do tabuleiro
            } else {
                matriz[i][j] = 0; // Espaço vazio
            }
        }
    }

    // Exibe a matriz da habilidade Cruzada
    printf("Habilidade -> Cruzada 💥\n");
    for (int i = 0; i < HABILIDADESLIN; i++) {
        for (int j = 0; j < HABILIDADESCOL; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void octaedro() { //Ataca inimigos em uma área em forma de octaedro ao redor do personagem
    int matriz[HABILIDADESLIN][HABILIDADESCOL];
    int centro = HABILIDADESLIN / 2; // Posição central da matriz

    for (int i = 0; i < HABILIDADESLIN; i++) {
        for (int j = 0; j < HABILIDADESCOL; j++) {
            if (abs(i - centro) + abs(j - centro) <= 2) {
                matriz[i][j] = 1; // Borda do tabuleiro
            } else {
                matriz[i][j] = 0; // Espaço vazio
            }
        }
    }

    // Exibe a matriz da habilidade Octaedro
    printf("Habilidade -> Octaedro 🔷\n");
    for (int i = 0; i < HABILIDADESLIN; i++) {
        for (int j = 0; j < HABILIDADESCOL; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
    cone();
    cruz();
    octaedro();
    return 0;
}

// Preenchendo a matriz de habilidade com valores de exemplo
void sobreposicaoHabilidade() {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            int tabLinha = origemLinha - meio + i;
            int tabColuna = origemColuna - meio + j;

            if (tabLinha >= 0 && tabLinha < 10 && tabColuna >= 0 && tabColuna < 10) {
                if (habilidade[i][j] == 1) {
                    tabuleiro[tabLinha][tabColuna] = 5; // Marca área de efeito (valor diferente de 0 e 3)
                }
            }
        }
    }
}