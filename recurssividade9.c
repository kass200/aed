#include <stdio.h>
#include <stdlib.h>

int somaDigitos(int numero) {
    int soma = 0;

    while (numero > 0) {
        soma = soma + numero % 10; 
        numero = numero / 10; 
    }
    return soma;
}

int main() {
    int numero;
    int soma;

    printf("Voce vai somar os digitos de um numero.\n");
    printf("Digite um numero: ");
    scanf("%d", &numero);

    soma = somaDigitos(numero);
    printf("A soma dos digitos do numero %d eh: %d\n", numero, soma);

    return 0;
}
