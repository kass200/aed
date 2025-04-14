#include <stdio.h>
#include <stdlib.h>

int maiorElemento(int vetor[], int tamanho) {
    int maior = vetor[0];

    for (int i = 0; i < tamanho; i++) {
        if (vetor[i] > maior) {
            maior = vetor[i];
        }
    }
    return maior;
}

int main() {
    int tamanho;
    int maior;

    printf("Voce vai montar um vetor de inteiros.\n");
    printf("Informe o tamanho do vetor: ");
    scanf("%d", &tamanho);

    int vetor[tamanho];
    printf("Agora informe os elementos do vetor: \n");
    for (int i = 0; i < tamanho; i++) {
        printf("Posicao %d: ", i);
        scanf("%d", &vetor[i]);
    }
    
    printf("Vetor preenchido.\n");

    maior = maiorElemento(vetor, tamanho);
    printf("O maior valor armazenado no vetor eh: %d\n", maior);

    return 0;
}
