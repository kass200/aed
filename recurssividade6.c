#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool palindromo(char palavra[], int inicio, int fim) {
    if (inicio >= fim) {
        return true;
    }

    if (palavra[inicio] != palavra[fim]) {
        return false;
    }

    return palindromo(palavra, inicio + 1, fim - 1);
}

int main() {
    char palavra[50];
    bool resultado;

    printf("Voce vai visualizar se uma palavra eh palindromo ou nao.\n");
    printf("Digite uma palavra: ");
    scanf("%s", palavra);

    int tamanho = strlen(palavra);

    resultado = palindromo(palavra, 0, tamanho - 1);

    if (resultado) {
        printf("A palavra eh palindromo.\n");
    } else {
        printf("A palavra nao eh palindromo.\n");
    }

    return 0;
}
