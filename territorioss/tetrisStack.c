#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAMANHO_FILA 5

// -------------------------------------------------------------
// Estrutura que representa uma peça do Tetris
// -------------------------------------------------------------
typedef struct {
    char nome;   // tipo da peça: 'I', 'O', 'T', 'L'
    int id;      // identificador único da peça
} Peca;

// -------------------------------------------------------------
// Estrutura da fila circular de peças
// -------------------------------------------------------------
typedef struct {
    Peca itens[TAMANHO_FILA];
    int frente;
    int tras;
    int quantidade;
} Fila;

// -------------------------------------------------------------
// Protótipos das funções
// -------------------------------------------------------------
void inicializarFila(Fila *f);
int estaVazia(Fila *f);
int estaCheia(Fila *f);
Peca gerarPeca();
void enqueue(Fila *f, Peca p);
Peca dequeue(Fila *f);
void exibirFila(Fila *f);

// -------------------------------------------------------------
// Função principal
// -------------------------------------------------------------
int main() {
    Fila fila;
    int opcao;
    int proximoID = 0; // controla IDs únicos

    srand(time(NULL));

    inicializarFila(&fila);

    // Inicializa a fila com 5 peças automaticamente
    for (int i = 0; i < TAMANHO_FILA; i++) {
        enqueue(&fila, gerarPeca(proximoID++));
    }

    // Loop do menu
    do {
        printf("\n============================================\n");
        printf("          Fila de Peças Futuras\n");
        printf("============================================\n");
        exibirFila(&fila);

        printf("\nOpções:\n");
        printf("1 - Jogar peça (dequeue)\n");
        printf("2 - Inserir nova peça (enqueue)\n");
        printf("0 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                if (!estaVazia(&fila)) {
                    Peca jogada = dequeue(&fila);
                    printf("\nPeça jogada: [%c %d]\n", jogada.nome, jogada.id);
                } else {
                    printf("\nA fila está vazia! Não há peças para jogar.\n");
                }
                break;

            case 2:
                if (!estaCheia(&fila)) {
                    enqueue(&fila, gerarPeca(proximoID++));
                    printf("\nNova peça inserida com sucesso!\n");
                } else {
                    printf("\nA fila está cheia! Não é possível inserir nova peça.\n");
                }
                break;

            case 0:
                printf("\nEncerrando o programa...\n");
                break;

            default:
                printf("\nOpção inválida! Tente novamente.\n");
        }

    } while (opcao != 0);

    return 0;
}

// -------------------------------------------------------------
// Inicializa os ponteiros e quantidade da fila
// -------------------------------------------------------------
void inicializarFila(Fila *f) {
    f->frente = 0;
    f->tras = 0;
    f->quantidade = 0;
}

// -------------------------------------------------------------
// Verifica se a fila está vazia
// -------------------------------------------------------------
int estaVazia(Fila *f) {
    return (f->quantidade == 0);
}

// -------------------------------------------------------------
// Verifica se a fila está cheia
// -------------------------------------------------------------
int estaCheia(Fila *f) {
    return (f->quantidade == TAMANHO_FILA);
}

// -------------------------------------------------------------
// Gera automaticamente uma peça com nome aleatório e ID único
// -------------------------------------------------------------
Peca gerarPeca(int id) {
    char tipos[] = {'I', 'O', 'T', 'L'};
    Peca p;
    p.nome = tipos[rand() % 4];
    p.id = id;
    return p;
}

// -------------------------------------------------------------
// Insere uma peça no final da fila (enqueue)
// -------------------------------------------------------------
void enqueue(Fila *f, Peca p) {
    if (estaCheia(f)) return;

    f->itens[f->tras] = p;
    f->tras = (f->tras + 1) % TAMANHO_FILA;
    f->quantidade++;
}

// -------------------------------------------------------------
// Remove uma peça da frente da fila (dequeue)
// -------------------------------------------------------------
Peca dequeue(Fila *f) {
    Peca p = f->itens[f->frente];
    f->frente = (f->frente + 1) % TAMANHO_FILA;
    f->quantidade--;
    return p;
}

// -------------------------------------------------------------
// Exibe a fila completa mostrando nome e ID
// -------------------------------------------------------------
void exibirFila(Fila *f) {
    printf("\nFila de Peças:\n");

    if (estaVazia(f)) {
        printf("[VAZIA]\n");
        return;
    }

    int i = f->frente;

    for (int count = 0; count < f->quantidade; count++) {
        printf("[%c %d] ", f->itens[i].nome, f->itens[i].id);
        i = (i + 1) % TAMANHO_FILA;
    }
    printf("\n");
}