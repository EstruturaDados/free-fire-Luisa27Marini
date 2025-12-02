#include <stdio.h>


// Struct Item: representa cada objeto da mochila

typedef struct {
    char nome[30];
    char tipo[20];
    int quantidade;
} Item;

// Função para inserir um item no inventário

void inserirItem(Item mochila[], int *total) {
    if (*total >= MAX_ITENS) {
        printf("\nA mochila está cheia! Não é possível adicionar mais itens.\n");
        return;
    }

    Item novo;

    printf("\n--- Cadastro de Item ---\n");
    printf("Nome do item: ");
    scanf("%s", novo.nome);

    printf("Tipo do item (arma, municao, cura, etc.): ");
    scanf("%s", novo.tipo);

    printf("Quantidade: ");
    scanf("%d", &novo.quantidade);

    mochila[*total] = novo;
    (*total)++;

    printf("Item adicionado com sucesso!\n");
}

// Função para remover um item da mochila pelo nome

void removerItem(Item mochila[], int *total) {
    char alvo[30];
    int encontrado = -1;

    if (*total == 0) {
        printf("\nA mochila está vazia! Nada para remover.\n");
        return;
    }

    printf("\nInforme o nome do item que deseja remover: ");
    scanf("%s", alvo);

    // Busca sequencial para encontrar o índice
    for (int i = 0; i < *total; i++) {
        if (strcmp(mochila[i].nome, alvo) == 0) {
            encontrado = i;
            break;
        }
    }

    if (encontrado == -1) {
        printf("Item não encontrado!\n");
        return;
    }

    // Compacta o vetor
    for (int i = encontrado; i < *total - 1; i++) {
        mochila[i] = mochila[i + 1];
    }

    (*total)--;

    printf("Item removido com sucesso!\n");
}

// Função para listar todos os itens da mochila

void listarItens(Item mochila[], int total) {
    printf("\n--- Itens na Mochila ---\n");

    if (total == 0) {
        printf("(nenhum item cadastrado)\n");
        return;
    }

    for (int i = 0; i < total; i++) {
        printf("Item %d:\n", i + 1);
        printf(" Nome: %s\n", mochila[i].nome);
        printf(" Tipo: %s\n", mochila[i].tipo);
        printf(" Quantidade: %d\n", mochila[i].quantidade);
        printf("-------------------------\n");
    }
}

// Busca sequencial por item

void buscarItem(Item mochila[], int total) {
    char alvo[30];

    if (total == 0) {
        printf("\nA mochila está vazia! Nada para buscar.\n");
        return;
    }

    printf("\nInforme o nome do item que deseja buscar: ");
    scanf("%s", alvo);

    for (int i = 0; i < total; i++) {
        if (strcmp(mochila[i].nome, alvo) == 0) {
            printf("\nItem encontrado!\n");
            printf(" Nome: %s\n", mochila[i].nome);
            printf(" Tipo: %s\n", mochila[i].tipo);
            printf(" Quantidade: %d\n", mochila[i].quantidade);
            return;
        }
    }

    printf("Item não encontrado!\n");
}

// Função principal: controla o menu e o fluxo do programa

int main() {
    Item mochila[MAX_ITENS];
    int total = 0;
    int opcao;

    do {
        printf("\n====================================\n");
        printf("        Sistema de Inventário\n");
        printf("====================================\n");
        printf("1 - Cadastrar item\n");
        printf("2 - Remover item\n");
        printf("3 - Buscar item\n");
        printf("4 - Listar itens\n");
        printf("0 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                inserirItem(mochila, &total);
                listarItens(mochila, total);
                break;
            case 2:
                removerItem(mochila, &total);
                listarItens(mochila, total);
                break;
            case 3:
                buscarItem(mochila, total);
                break;
            case 4:
                listarItens(mochila, total);
                break;
            case 0:
                printf("Encerrando o sistema...\n");
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
        }

    } while (opcao != 0);

    return 0;
}
