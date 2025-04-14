#include <stdio.h>

void contagemRegressiva(int numero) {
    if (numero < 0) {
        return;
    } else {
        printf("%d ", numero);
        contagemRegressiva(numero - 1);
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