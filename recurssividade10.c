#include <stdio.h>
#include <stdlib.h>

int produto(int numero, int vezes) {
    int resultado = 0;

    for (int i = 0; i < vezes; i++) {
        resultado = resultado + numero;
    }
    return resultado;
}

int main() {
    int numero, vezes, resultado;

    printf("Voce vai calcular o produto de dois numeros inteiros.\n");
    printf("Digite o primeiro numero: ");
    scanf("%d", &numero);

    printf("Digite quantas vezes quer multiplicar esse numero inserido: ");
    scanf("%d", &vezes);

    resultado = produto(numero, vezes);
    printf("O resultado da operacao : %d x %d eh: %d\n", numero, vezes, resultado);

    return 0;
}
