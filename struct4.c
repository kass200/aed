#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char modelo[30];
    int ano;
    float preço;
}carro;

int main(){
    carro *ptr;
    ptr = (carro *)malloc(sizeof(carro));

    printf("Digite os dados:");
    printf("Modelo:\n Ano:\n Preço:");
    scanf("%s", ptr->modelo);
    scanf("%d", &ptr->ano);
    scanf("%f", &ptr->preço);
    
    printf("\n--- DADOS DO CARRO ---\n");
    printf("Modelo: %s\n Ano: %d\n Preço: %.2f ", ptr->modelo, ptr->ano, ptr->preço);

    free(ptr);
    return 0;
}