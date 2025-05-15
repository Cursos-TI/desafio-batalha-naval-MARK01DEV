#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 10

void ET(int matriz[TAM][TAM], const char* titulo) {
    printf("\n   %s\n   ", titulo);
    for (char c = 'A'; c < 'A' + TAM; c++) printf(" %c", c);
    printf("\n");
    for (int i = 0; i < TAM; i++) {
        printf("%2d ", i + 1);
        for (int j = 0; j < TAM; j++) {
            printf(" %d", matriz[i][j]);
        }
        printf("\n");
    }
}

void nivelNT() {
    int tabuleiro[5][5] = {0};

    for (int j = 1; j <= 3; j++) {
        tabuleiro[1][j] = 3;
        printf("Navio horizontal em: (%d,%d)\n", 2, j + 1);
    }

    for (int i = 3; i <= 4; i++) {
        tabuleiro[i][2] = 3;
        printf("Navio vertical em: (%d,%d)\n", i + 1, 3);
    }

    printf("\nTabuleiro Novato (5x5):\n");
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

void nivelAT(int tabuleiro[TAM][TAM]) {
    memset(tabuleiro, 0, sizeof(int) * TAM * TAM);

    for (int j = 2; j <= 5; j++) tabuleiro[2][j] = 3;

    for (int i = 4; i <= 7; i++) tabuleiro[i][6] = 3;

    for (int i = 0; i < 4; i++) tabuleiro[1 + i][1 + i] = 3;

    for (int i = 0; i < 4; i++) tabuleiro[5 + i][4 - i] = 3;

    ET(tabuleiro, "TABULEIRO BATALHA NAVAL");
}

void AH(int matriz[TAM][TAM], int tipo, int cx, int cy) {
    memset(matriz, 0, sizeof(int) * TAM * TAM);
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            int dx = i - cx;
            int dy = j - cy;
            switch (tipo) {
                case 1:
                    if (dx >= 0 && abs(dy) <= dx) matriz[i][j] = 1;
                    break;
                case 2: 
                    if (i == cx || j == cy) matriz[i][j] = 1;
                    break;
                case 3:
                    if (abs(dx) + abs(dy) <= 2) matriz[i][j] = 1;
                    break;
            }
        }
    }
}

void nivelMT() {
    int habilidade[TAM][TAM];

    AH(habilidade, 1, 2, 4); 
    ET(habilidade, "Habilidade: CONE em (3,E)");

    AH(habilidade, 2, 5, 5);
    ET(habilidade, "Habilidade: CRUZ em (6,F)");

    AH(habilidade, 3, 4, 4);
    ET(habilidade, "Habilidade: OCTAEDRO em (5,E)");
}

int main() {
    printf("== NÍVEL NOVATO ==\n");
    nivelNT();

    printf("\n== NÍVEL AVENTUREIRO ==\n");
    int tabuleiroAventureiro[TAM][TAM];
    nivelAT(tabuleiroAventureiro);

    printf("\n== NÍVEL MESTRE ==\n");
    nivelMT();

    return 0;
}
