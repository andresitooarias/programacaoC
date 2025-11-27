#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*-----------------------------------------------------------
    Struct Sala
    Representa cada cômodo da mansão usando uma árvore binária.
-----------------------------------------------------------*/
typedef struct sala {
    char nome[50];
    struct sala *esq;
    struct sala *dir;
} Sala;

/*-----------------------------------------------------------
    Função criarSala()
    Cria dinamicamente um nó da árvore representando uma sala.
-----------------------------------------------------------*/
Sala* criarSala(const char *nome) {
    Sala *nova = (Sala*) malloc(sizeof(Sala));
    if (nova == NULL) {
        printf("Erro ao alocar memória!\n");
        exit(1);
    }

    strcpy(nova->nome, nome);
    nova->esq = NULL;
    nova->dir = NULL;
    return nova;
}

/*-----------------------------------------------------------
    Função explorarSalas()
    Navega pela mansão a partir de uma sala fornecida.
    O jogador escolhe ir para a esquerda (e), direita (d)
    ou sair (s).
-----------------------------------------------------------*/
void explorarSalas(Sala *atual) {
    char opcao;

    while (1) {
        printf("\nVocê está em: %s\n", atual->nome);

        /* Caso seja um nó-folha, a exploração termina */
        if (atual->esq == NULL && atual->dir == NULL) {
            printf("Este cômodo não possui mais caminhos. Exploração encerrada!\n");
            return;
        }

        printf("Escolha um caminho:\n");
        if (atual->esq != NULL) printf("  (e) Ir para %s\n", atual->esq->nome);
        if (atual->dir != NULL) printf("  (d) Ir para %s\n", atual->dir->nome);
        printf("  (s) Sair da exploração\n");
        printf("Opção: ");
        scanf(" %c", &opcao);

        if (opcao == 'e' && atual->esq != NULL) {
            atual = atual->esq;
        }
        else if (opcao == 'd' && atual->dir != NULL) {
            atual = atual->dir;
        }
        else if (opcao == 's') {
            printf("Você saiu da exploração.\n");
            return;
        }
        else {
            printf("Opção inválida! Tente novamente.\n");
        }
    }
}

/*-----------------------------------------------------------
    Função main()
    Monta manualmente a árvore binária da mansão,
    utilizando criarSala(), e inicia a exploração.
-----------------------------------------------------------*/
int main() {
    /* Criação das salas (árvore montada manualmente) */
    Sala *hall = criarSala("Hall de Entrada");
    Sala *salaEstar = criarSala("Sala de Estar");
    Sala *cozinha = criarSala("Cozinha");
    Sala *biblioteca = criarSala("Biblioteca");
    Sala *jardim = criarSala("Jardim");

    /* Montagem da árvore binária */
    hall->esq = salaEstar;
    hall->dir = cozinha;

    salaEstar->esq = biblioteca;
    salaEstar->dir = jardim;

    /* Início da exploração */
    printf("=== Detective Quest – Mansão Misteriosa ===\n");
    explorarSalas(hall);

    return 0;
}