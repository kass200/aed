#include <stdio.h>
#include <stdlib.h>

void contagemRegressiva(int numero) {
    while (numero >= 0) {
        printf("%d ", numero);
        numero--;
    }
}

int main() {
    int numero;

    printf("Voce vai visualizar uma contagem regressiva.\n");
    printf("Digite um numero: ");
    scanf("%d", &numero);

    printf("A contagem regressiva partindo do numero %d eh: ", numero);
    contagemRegressiva(numero);
    printf("\n");

    return 0;
}
