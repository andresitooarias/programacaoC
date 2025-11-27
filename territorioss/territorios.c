#include <stdio.h>
#include <string.h>

#define MAX_TERRITORIOS 5

/* 
 * Struct Territorio:
 * Agrupa os dados relacionados a um território:
 * - nome: nome do território (até 29 caracteres + terminador)
 * - cor: cor do exército (até 9 caracteres + terminador)
 * - tropas: quantidade de tropas (inteiro)
 */
typedef struct {
    char nome[30];
    char cor[10];
    int tropas;
} Territorio;

int main(void) {
    /* Vetor para armazenar os territórios (capacidade fixa de 5) */
    Territorio territorios[MAX_TERRITORIOS];

    printf("=== Sistema de Cadastro de Territórios ===\n\n");
    printf("Voce ira cadastrar %d territorios. Siga as instrucoes abaixo.\n\n", MAX_TERRITORIOS);

    /* Laço de entrada: preenche os 5 territórios com dados fornecidos pelo usuário */
    for (int i = 0; i < MAX_TERRITORIOS; i++) {
        printf("Territorio %d de %d\n", i + 1, MAX_TERRITORIOS);

        /* 
         * Leitura do nome:
         * Usamos scanf com scanset " %29[^\n]" para permitir espaços no nome
         * e limitar a entrada a 29 caracteres (mais o '\0').
         * O espaço inicial no formato consome eventuais caracteres de quebra de linha.
         */
        printf("  Nome (pode conter espacos, max 29 caracteres): ");
        if (scanf(" %29[^\n]", territorios[i].nome) != 1) {
            /* Em caso de erro simples de leitura, garantimos string vazia */
            territorios[i].nome[0] = '\0';
        }

        /* Leitura da cor do exército: normalmente uma palavra curta */
        printf("  Cor do exercito (sem espacos, max 9 caracteres): ");
        if (scanf(" %9s", territorios[i].cor) != 1) {
            territorios[i].cor[0] = '\0';
        }

        /* Leitura do numero de tropas (inteiro) */
        printf("  Numero de tropas (inteiro): ");
        if (scanf("%d", &territorios[i].tropas) != 1) {
            /* Se a leitura falhar, define 0 e consome entrada incorreta */
            territorios[i].tropas = 0;

            /* Limpa o buffer de entrada até a proxima linha para evitar loop infinito */
            int c;
            while ((c = getchar()) != '\n' && c != EOF) { }
        }

        printf("\n"); /* separador visual entre cadastros */
    }

    /* Exibicao dos dados: percorre o vetor e imprime cada territorio com formatacao clara */
    printf("=== Dados dos Territorios Cadastrados ===\n\n");
    for (int i = 0; i < MAX_TERRITORIOS; i++) {
        printf("Territorio %d:\n", i + 1);
        printf("  Nome : %s\n", territorios[i].nome);
        printf("  Cor  : %s\n", territorios[i].cor);
        printf("  Tropas: %d\n", territorios[i].tropas);
        printf("----------------------------------------\n");
    }

    printf("Fim do cadastro. Obrigado!\n");
    return 0;
}