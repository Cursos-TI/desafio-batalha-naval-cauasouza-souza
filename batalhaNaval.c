#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define TAMANHO 10
#define TAMANHO_NAVIO 3
#define AGUA 0
#define NAVIO 3
#define HABILIDADE 5
#define TAM_HABILIDADE 5  // Tamanho das matrizes de habilidade (5x5)

// Função para inicializar o tabuleiro com água (0s)
void inicializarTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    for(int i = 0; i < TAMANHO; i++) {
        for(int j = 0; j < TAMANHO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }
}

// Função para posicionar navio horizontal
void posicionarHorizontal(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna) {
    for(int j = coluna; j < coluna + TAMANHO_NAVIO; j++) {
        if(j < TAMANHO) {
            tabuleiro[linha][j] = NAVIO;
        }
    }
}

// Função para posicionar navio vertical
void posicionarVertical(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna) {
    for(int i = linha; i < linha + TAMANHO_NAVIO; i++) {
        if(i < TAMANHO) {
            tabuleiro[i][coluna] = NAVIO;
        }
    }
}

// Cria matriz de habilidade em formato de cone
void criarCone(int habilidade[TAM_HABILIDADE][TAM_HABILIDADE]) {
    int centro = TAM_HABILIDADE / 2;
    for(int i = 0; i < TAM_HABILIDADE; i++) {
        for(int j = 0; j < TAM_HABILIDADE; j++) {
            // Verifica se a posição está dentro do cone
            if(j >= centro - i && j <= centro + i && i >= centro) {
                habilidade[i][j] = 1;
            } else {
                habilidade[i][j] = 0;
            }
        }
    }
}

// Cria matriz de habilidade em formato de cruz
void criarCruz(int habilidade[TAM_HABILIDADE][TAM_HABILIDADE]) {
    int centro = TAM_HABILIDADE / 2;
    for(int i = 0; i < TAM_HABILIDADE; i++) {
        for(int j = 0; j < TAM_HABILIDADE; j++) {
            // Verifica se está na linha ou coluna central
            if(i == centro || j == centro) {
                habilidade[i][j] = 1;
            } else {
                habilidade[i][j] = 0;
            }
        }
    }
}

// Cria matriz de habilidade em formato de octaedro (losango)
void criarOctaedro(int habilidade[TAM_HABILIDADE][TAM_HABILIDADE]) {
    int centro = TAM_HABILIDADE / 2;
    for(int i = 0; i < TAM_HABILIDADE; i++) {
        for(int j = 0; j < TAM_HABILIDADE; j++) {
            // Verifica se está dentro do losango
            int dist_centro_i = abs(i - centro);
            int dist_centro_j = abs(j - centro);
            if(dist_centro_i + dist_centro_j <= centro) {
                habilidade[i][j] = 1;
            } else {
                habilidade[i][j] = 0;
            }
        }
    }
}

// Aplica uma habilidade ao tabuleiro
void aplicarHabilidade(int tabuleiro[TAMANHO][TAMANHO], int habilidade[TAM_HABILIDADE][TAM_HABILIDADE], int linha, int coluna) {
    int offset = TAM_HABILIDADE / 2;
    
    for(int i = 0; i < TAM_HABILIDADE; i++) {
        for(int j = 0; j < TAM_HABILIDADE; j++) {
            int tab_i = linha - offset + i;
            int tab_j = coluna - offset + j;
            
            // Verifica se está dentro do tabuleiro e se a posição é afetada pela habilidade
            if(tab_i >= 0 && tab_i < TAMANHO && tab_j >= 0 && tab_j < TAMANHO && habilidade[i][j] == 1) {
                // Marca apenas se não for um navio
                if(tabuleiro[tab_i][tab_j] != NAVIO) {
                    tabuleiro[tab_i][tab_j] = HABILIDADE;
                }
            }
        }
    }
}

// Exibe o tabuleiro formatado
void exibirTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    printf("\n  ");
    for(int j = 0; j < TAMANHO; j++) {
        printf("%2d", j);
    }
    printf("\n");
    
    for(int i = 0; i < TAMANHO; i++) {
        printf("%2d", i);
        for(int j = 0; j < TAMANHO; j++) {
            printf("%2d", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int tabuleiro[TAMANHO][TAMANHO];
    
    // Inicializa o tabuleiro
    inicializarTabuleiro(tabuleiro);
    
    // Posiciona alguns navios
    posicionarHorizontal(tabuleiro, 2, 3);
    posicionarVertical(tabuleiro, 5, 7);
    posicionarHorizontal(tabuleiro, 7, 1);
    
    // Cria matrizes de habilidades
    int cone[TAM_HABILIDADE][TAM_HABILIDADE];
    int cruz[TAM_HABILIDADE][TAM_HABILIDADE];
    int octaedro[TAM_HABILIDADE][TAM_HABILIDADE];
    
    criarCone(cone);
    criarCruz(cruz);
    criarOctaedro(octaedro);
    
    // Aplica as habilidades ao tabuleiro
    aplicarHabilidade(tabuleiro, cone, 4, 4);      // Cone no centro
    aplicarHabilidade(tabuleiro, cruz, 1, 8);      // Cruz no canto superior direito
    aplicarHabilidade(tabuleiro, octaedro, 8, 2);  // Octaedro na parte inferior esquerda
    
    // Exibe o tabuleiro com navios e áreas de habilidade
    exibirTabuleiro(tabuleiro);
    
    // Legenda
    printf("\nLegenda:\n");
    printf("%d - Água\n", AGUA);
    printf("%d - Navio\n", NAVIO);
    printf("%d - Área de habilidade\n", HABILIDADE);
    
    return 0;
}
