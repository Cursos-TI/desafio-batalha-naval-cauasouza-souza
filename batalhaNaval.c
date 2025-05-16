#include <stdio.h>

#define TAMANHO 10
#define TAMANHO_NAVIO 3
#define AGUA 0
#define NAVIO 3

// Função para inicializar o tabuleiro com água (0s)
void inicializarTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    for(int i = 0; i < TAMANHO; i++) {
        for(int j = 0; j < TAMANHO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }
}

// Função para verificar se uma posição está dentro do tabuleiro
int posicaoValida(int linha, int coluna) {
    return linha >= 0 && linha < TAMANHO && coluna >= 0 && coluna < TAMANHO;
}

// Função para verificar sobreposição com outros navios
int semSobreposicao(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna) {
    return tabuleiro[linha][coluna] == AGUA;
}

// Posiciona navio horizontal
int posicionarHorizontal(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna) {
    // Verifica se todas as posições são válidas e sem sobreposição
    for(int j = coluna; j < coluna + TAMANHO_NAVIO; j++) {
        if(!posicaoValida(linha, j) || !semSobreposicao(tabuleiro, linha, j)) {
            return 0;
        }
    }
    
    // Posiciona o navio
    for(int j = coluna; j < coluna + TAMANHO_NAVIO; j++) {
        tabuleiro[linha][j] = NAVIO;
    }
    return 1;
}

// Posiciona navio vertical
int posicionarVertical(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna) {
    // Verifica se todas as posições são válidas e sem sobreposição
    for(int i = linha; i < linha + TAMANHO_NAVIO; i++) {
        if(!posicaoValida(i, coluna) || !semSobreposicao(tabuleiro, i, coluna)) {
            return 0;
        }
    }
    
    // Posiciona o navio
    for(int i = linha; i < linha + TAMANHO_NAVIO; i++) {
        tabuleiro[i][coluna] = NAVIO;
    }
    return 1;
}

// Posiciona navio diagonal principal (linha = coluna)
int posicionarDiagonalPrincipal(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna) {
    // Verifica se todas as posições são válidas e sem sobreposição
    for(int k = 0; k < TAMANHO_NAVIO; k++) {
        if(!posicaoValida(linha + k, coluna + k) || !semSobreposicao(tabuleiro, linha + k, coluna + k)) {
            return 0;
        }
    }
    
    // Posiciona o navio
    for(int k = 0; k < TAMANHO_NAVIO; k++) {
        tabuleiro[linha + k][coluna + k] = NAVIO;
    }
    return 1;
}

// Posiciona navio diagonal secundária (linha + coluna = constante)
int posicionarDiagonalSecundaria(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna) {
    // Verifica se todas as posições são válidas e sem sobreposição
    for(int k = 0; k < TAMANHO_NAVIO; k++) {
        if(!posicaoValida(linha + k, coluna - k) || !semSobreposicao(tabuleiro, linha + k, coluna - k)) {
            return 0;
        }
    }
    
    // Posiciona o navio
    for(int k = 0; k < TAMANHO_NAVIO; k++) {
        tabuleiro[linha + k][coluna - k] = NAVIO;
    }
    return 1;
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
    
    printf("Posicionando navios...\n");
    
    // Navio horizontal (linha 2, coluna 3)
    if(!posicionarHorizontal(tabuleiro, 2, 3)) {
        printf("Erro ao posicionar navio horizontal!\n");
        return 1;
    }
    
    // Navio vertical (linha 5, coluna 7)
    if(!posicionarVertical(tabuleiro, 5, 7)) {
        printf("Erro ao posicionar navio vertical!\n");
        return 1;
    }
    
    // Navio diagonal principal (linha 1, coluna 1)
    if(!posicionarDiagonalPrincipal(tabuleiro, 1, 1)) {
        printf("Erro ao posicionar navio diagonal principal!\n");
        return 1;
    }
    
    // Navio diagonal secundária (linha 0, coluna 8)
    if(!posicionarDiagonalSecundaria(tabuleiro, 0, 8)) {
        printf("Erro ao posicionar navio diagonal secundário!\n");
        return 1;
    }
    
    // Exibe o tabuleiro com os navios posicionados
    exibirTabuleiro(tabuleiro);
    
    return 0;
}
