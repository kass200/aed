#include <stdio.h>

int produto(int numero, int vezes) {
    if (numero == 0 || vezes == 0) {
        return 0;
    }
    return numero + produto(numero, vezes - 1);
}

int main() {
    int numero, vezes, resultado;

    printf("Você vai calcular o produto de dois números inteiros.\n");
    printf("Digite o primeiro número: ");
    scanf("%d", &numero);

    printf("Digite quantas vezes quer multiplicar esse número inserido: ");
    scanf("%d", &vezes);

    resultado = produto(numero, vezes);

    printf("O resultado da operação %d x %d é: %d\n", numero, vezes, resultado);

    return 0;
}