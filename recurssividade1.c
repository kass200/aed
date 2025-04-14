#include <stdio.h>

int contar_digitos(int n){
    if(n == 0){
        return 0;
    }
    return 1 + contar_digitos(n/10);
}
int main(){
    int num;
    printf("insira os numeros para a contagem de digitos:");
    scanf("%d", &num);
    if (num == 0) {
        printf("O número possui 1 dígito.\n");
    } else {
        printf("O número possui %d dígito(s).\n", contar_digitos(num));
    }
    return 0;
}