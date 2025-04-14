#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

typedef struct {
    char nome[50];
    char telefone[15];
} agenda;

void buscarcontato(agenda a[], int tamanho, char nomebusca[]) {
    int encontrou = 0;
    for (int i = 0; i < tamanho; i++) {
        if (strcmp(a[i].nome, nomebusca) == 0) {
            printf("\n--- CONTATO ENCONTRADO ---\n");
            printf("Nome: %s\n", a[i].nome);
            printf("Telefone: %s\n", a[i].telefone);
            encontrou = 1;
            break;
        }
    }

    if (!encontrou) {
        printf("\nContato com nome '%s' não encontrado.\n", nomebusca);
    }
}

int main() {
    int n;
    printf("Quantos contatos você quer cadastrar? ");
    scanf("%d", &n);

    agenda a[n];

    for (int i = 0; i < n; i++) {
        printf("\n--- Contato %d ---\n", i + 1);
        printf("Nome: ");
        scanf("%s", a[i].nome);
        printf("Telefone: ");
        scanf("%s", a[i].telefone);
    }

    char nomebusca[50];
    printf("\nDigite o nome do contato que deseja buscar: ");
    scanf("%s", nomebusca);

    buscarcontato(a, n, nomebusca);

    return 0;
}
