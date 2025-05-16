#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3

// Função para inicializar o tabuleiro com 0s (água)
void inicializarTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    for(int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for(int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = 0;
        }
    }
}

// Função para posicionar navio horizontal
int posicionarNavioHorizontal(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    // Verifica se o navio cabe no tabuleiro
    if(coluna + TAMANHO_NAVIO > TAMANHO_TABULEIRO) {
        printf("Erro: Navio horizontal sai do tabuleiro!\n");
        return 0;
    }
    
    // Verifica sobreposição
    for(int j = coluna; j < coluna + TAMANHO_NAVIO; j++) {
        if(tabuleiro[linha][j] != 0) {
            printf("Erro: Navio horizontal sobrepõe outro navio!\n");
            return 0;
        }
    }
    
    // Posiciona o navio
    for(int j = coluna; j < coluna + TAMANHO_NAVIO; j++) {
        tabuleiro[linha][j] = 3;
    }
    return 1;
}

// Função para posicionar navio vertical
int posicionarNavioVertical(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    // Verifica se o navio cabe no tabuleiro
    if(linha + TAMANHO_NAVIO > TAMANHO_TABULEIRO) {
        printf("Erro: Navio vertical sai do tabuleiro!\n");
        return 0;
    }
    
    // Verifica sobreposição
    for(int i = linha; i < linha + TAMANHO_NAVIO; i++) {
        if(tabuleiro[i][coluna] != 0) {
            printf("Erro: Navio vertical sobrepõe outro navio!\n");
            return 0;
        }
    }
    
    // Posiciona o navio
    for(int i = linha; i < linha + TAMANHO_NAVIO; i++) {
        tabuleiro[i][coluna] = 3;
    }
    return 1;
}

// Função para exibir o tabuleiro
void exibirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    printf("\nTabuleiro de Batalha Naval:\n");
    printf("  0 1 2 3 4 5 6 7 8 9\n");
    for(int i = 0; i < TAMANHO_TABULEIRO; i++) {
        printf("%d ", i);
        for(int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
    
    // Inicializa o tabuleiro com água (0s)
    inicializarTabuleiro(tabuleiro);
    
    // Posiciona navio horizontal (linha 2, coluna 3)
    printf("Posicionando navio horizontal na linha 2, coluna 3...\n");
    if(!posicionarNavioHorizontal(tabuleiro, 2, 3)) {
        return 1; // Sai do programa se não conseguir posicionar
    }
    
    // Posiciona navio vertical (linha 5, coluna 7)
    printf("Posicionando navio vertical na linha 5, coluna 7...\n");
    if(!posicionarNavioVertical(tabuleiro, 5, 7)) {
        return 1; // Sai do programa se não conseguir posicionar
    }
    
    // Exibe o tabuleiro com os navios posicionados
    exibirTabuleiro(tabuleiro);
    
    return 0;
}