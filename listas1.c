#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No* proximo;
} No;

No* inserir_inicio(No* lista, int valor) {
    No* novo = (No*)malloc(sizeof(No));
    novo->valor = valor;
    novo->proximo = lista;
    return novo;
}

No* inserir_final(No* lista, int valor) {
    No* novo = (No*)malloc(sizeof(No));
    novo->valor = valor;
    novo->proximo = NULL;

    if (lista == NULL) {
        return novo;
    }

    No* atual = lista;
    while (atual->proximo != NULL) {
        atual = atual->proximo;
    }
    atual->proximo = novo;
    return lista;
}

No* remover_elemento(No* lista, int valor) {
    No* atual = lista;
    No* anterior = NULL;

    while (atual != NULL && atual->valor != valor) {
        anterior = atual;
        atual = atual->proximo;
    }

    if (atual == NULL) {
        printf("Elemento %d nao encontrado.\n", valor);
        return lista;
    }

    if (anterior == NULL) {
        No* temp = atual->proximo;
        free(atual);
        return temp;
    } else {
        anterior->proximo = atual->proximo;
        free(atual);
        return lista;
    }
}

void exibir_lista(No* lista) {
    if (lista == NULL) {
        printf("Lista vazia.\n");
        return;
    }

    printf("Elementos da lista:\n");
    No* atual = lista;
    while (atual != NULL) {
        printf("%d -> ", atual->valor);
        atual = atual->proximo;
    }
    printf("NULL\n");
}

int main() {
    No* lista = NULL;
    int opcao, valor;

    do {
        printf("\n1 - Inserir no inicio\n");
        printf("2 - Inserir no final\n");
        printf("3 - Remover elemento\n");
        printf("4 - Exibir lista\n");
        printf("0 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o valor a ser inserido no inicio: ");
                scanf("%d", &valor);
                lista = inserir_inicio(lista, valor);
                break;
            case 2:
                printf("Digite o valor a ser inserido no final: ");
                scanf("%d", &valor);
                lista = inserir_final(lista, valor);
                break;
            case 3:
                printf("Digite o valor a ser removido: ");
                scanf("%d", &valor);
                lista = remover_elemento(lista, valor);
                break;
            case 4:
                exibir_lista(lista);
                break;
            case 0:
                printf("Encerrando o programa.\n");
                break;
            default:
                printf("Opcao invalida.\n");
        }
    } while (opcao != 0);

    No* atual = lista;
    while (atual != NULL) {
        No* temp = atual;
        atual = atual->proximo;
        free(temp);
    }

    return 0;
}
