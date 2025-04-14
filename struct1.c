#include <stdio.h>
typedef struct{
char nome[50];
int idade;
float altura;
}pessoa;
int main() {
  pessoa p;
  printf("Digite o nome, idade e altura: \n");
  scanf("%s %d %f", p.nome, &p.idade, &p.altura);
  printf("Nome: %s \n Idade: %d \n Altura: %.2f \n", p.nome, p.idade,p.altura);
  
  return 0;
}