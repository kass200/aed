#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isBalanced(const char* expression) {
    int balance = 0;

    for (int i = 0; expression[i] != '\0'; i++) {
        if (expression[i] == '(') {
            balance++;
        } else if (expression[i] == ')') {
            balance--;
        }

        if (balance < 0) {
            return 0;
        }
    }

    return balance == 0;
}

int main() {
    char expression1[] = "(())()";
    char expression2[] = "(()";

    if (isBalanced(expression1)) {
        printf("Expressão 1: Válido\n");
    } else {
        printf("Expressão 1: Inválido\n");
    }

    if (isBalanced(expression2)) {
        printf("Expressão 2: Válido\n");
    } else {
        printf("Expressão 2: Inválido\n");
    }

    return 0;
}
