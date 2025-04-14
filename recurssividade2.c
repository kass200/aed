#include <stdio.h>

int maior_numero(int vet[], int tamanho) {
    if (tamanho == 1) {
        return vet[0];
    }

    int maior_restante = maior_numero(vet, tamanho - 1);

    if (vet[tamanho - 1] > maior_restante) {
        return vet[tamanho - 1];
    } else {
        return maior_restante;
    }
}

int main() {
    int n;

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);

    int vet[n];
    printf("Digite os %d elementos do vetor:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &vet[i]);
    }

    int maior = maior_numero(vet, n);
    printf("O maior número do vetor é: %d\n", maior);

    return 0;
}
