#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_ITENS 10

// -------------------------------------------------------------
// Struct que representa um item do inventário
// -------------------------------------------------------------
typedef struct {
    char nome[30];
    char tipo[20];
    int quantidade;
} Item;

// Vetor que armazena até 10 itens
Item mochila[MAX_ITENS];
int totalItens = 0;

// -------------------------------------------------------------
// Função: inserirItem()
// Adiciona um novo item ao inventário, se houver espaço
// -------------------------------------------------------------
void inserirItem() {
    if (totalItens >= MAX_ITENS) {
        printf("\n⚠ A mochila está cheia! Não é possível adicionar mais itens.\n");
        return;
    }

    Item novo;

    printf("\nDigite o nome do item: ");
    scanf("%s", novo.nome);

    printf("Digite o tipo do item (arma, municao, cura...): ");
    scanf("%s", novo.tipo);

    printf("Digite a quantidade: ");
    scanf("%d", &novo.quantidade);

    mochila[totalItens] = novo;
    totalItens++;

    printf("\n✅ Item cadastrado com sucesso!\n");
}

// -------------------------------------------------------------
// Função: removerItem()
// Remove um item do inventário baseado no nome
// -------------------------------------------------------------
void removerItem() {
    if (totalItens == 0) {
        printf("\n⚠ A mochila está vazia, nada para remover.\n");
        return;
    }

    char nomeRemover[30];
    printf("\nDigite o nome do item a remover: ");
    scanf("%s", nomeRemover);

    for (int i = 0; i < totalItens; i++) {
        if (strcmp(mocha[i].nome, nomeRemover) == 0) {
            // Substitui item removido pelo último da lista
            mochila[i] = mochila[totalItens - 1];
            totalItens--;
            printf("\n🗑 Item removido com sucesso!\n");
            return;
        }
    }

    printf("\n❌ Item não encontrado na mochila.\n");
}

// -------------------------------------------------------------
// Função: listarItens()
// Exibe todos os itens cadastrados
// -------------------------------------------------------------
void listarItens() {
    printf("\n----- ITENS NA MOCHILA -----\n");

    if (totalItens == 0) {
        printf("A mochila está vazia.\n");
        return;
    }

    for (int i = 0; i < totalItens; i++) {
        printf("\nItem %d:\n", i + 1);
        printf("Nome: %s\n", mochila[i].nome);
        printf("Tipo: %s\n", mochila[i].tipo);
        printf("Quantidade: %d\n", mochila[i].quantidade);
    }
}

// -------------------------------------------------------------
// Função: buscarItem()
// Busca sequencial pelo nome do item
// -------------------------------------------------------------
void buscarItem() {
    if (totalItens == 0) {
        printf("\n⚠ Não há itens para buscar.\n");
        return;
    }

    char nomeBusca[30];
    printf("\nDigite o nome do item que deseja buscar: ");
    scanf("%s", nomeBusca);

    for (int i = 0; i < totalItens; i++) {
        if (strcmp(mochila[i].nome, nomeBusca) == 0) {
            printf("\n🔎 Item encontrado!\n");
            printf("Nome: %s\n", mochila[i].nome);
            printf("Tipo: %s\n", mochila[i].tipo);
            printf("Quantidade: %d\n", mochila[i].quantidade);
            return;
        }
    }

    printf("\n❌ Item não encontrado.\n");
}

// -------------------------------------------------------------
// Função principal
// -------------------------------------------------------------
int main() {
    int opcao;

    do {
        printf("\n========== SISTEMA DE INVENTÁRIO ==========\n");
        printf("1 - Inserir item\n");
        printf("2 - Remover item\n");
        printf("3 - Listar itens\n");
        printf("4 - Buscar item\n");
        printf("0 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                inserirItem();
                listarItens();
                break;
            case 2:
                removerItem();
                listarItens();
                break;
            case 3:
                listarItens();
                break;
            case 4:
                buscarItem();
                break;
            case 0:
                printf("\nEncerrando o sistema...\n");
                break;
            default:
                printf("\n⚠ Opcao invalida! Tente novamente.\n");
        }

    } while (opcao != 0);

    return 0;
}