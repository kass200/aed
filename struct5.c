#include <stdio.h>

typedef struct{
    char nome[50];
    char cargo[30];
    float salario;
}funcionarios;

int main(){
    int n;
    printf("insira o número de funcionarios que deseja registrar:");
    scanf("%d", &n);

    funcionarios f[n];

    for(int i = 0; i < n; i++){
     printf("Digite o nome o cargo e o salario do funcionario: %d", i + 1);
     scanf("%s", f[i].nome );
     scanf("%s", f[i].cargo);
     scanf("%f", &f[i].salario);
    }
    printf("\n--- DADOS FUNCIONARIOS ---\n");
     
    for (int i = 0; i < n; i++) {
        printf("\nFuncionário %d:\n", i + 1);
        printf("Nome: %s\n", f[i].nome);
        printf("Cargo: %s\n", f[i].cargo);
        printf("Salário: R$ %.2f\n", f[i].salario);
    }
    return 0;
}