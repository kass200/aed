#include <stdio.h>

int soma_dos_digitos(int n){
    if(n == 0){
        return 0;
    }
    return (n % 10) + soma_digitos(n / 10);
}

int main(){
    int num;

    printf("Digite um numero inteiro:");
    scanf("%d", &num);

    if (num < 0) {
        num = -num;
    }

    printf("A soma dos dígitos é: %d\n", soma_digitos(num));

    return 0;
}