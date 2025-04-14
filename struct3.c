#include <stdio.h>

typedef struct{
    char nome[30];
    int codigo;
    float preco;
} produto;

void formatacao (produto p){
    printf("\n--- DADOS DO PRODUTO ---\n");
    printf("Nome: %s\n", p.nome);
    printf("Codigo: %d\n", p.codigo);
    printf("Preço: R$ %.2f\n", p.preco);
   }
int main(){
    produto p2;
    printf("Insira os dados dos produtos:\n");
    printf("Nome:\n Codigo:\n Preço:");
    scanf("%s", p2.nome);  
    scanf("%d", &p2.codigo); 
    scanf("%f", &p2.preco); 
    formatacao(p2);

    return 0;
}