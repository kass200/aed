#include <stdio.h>

typedef struct{
    char nome[50];
    int idade;
    char diagnostico[100];
}registro_pacientes;
void exibir_pacientes(registro_pacientes rg[], int tamanho){
    printf("\n--- PACIENTES COM MAIS DE 60 ANOS ---\n");
    for(int i = 0; i < tamanho; i++){
    if(rg[i].idade > 60){
        printf("Nome: %s\n", rg[i].nome);
            printf("Idade: %d\n", rg[i].idade);
            printf("Diagnóstico: %s\n\n", rg[i].diagnostico);
    }
}

}
int main(){
    int tamanho;
    printf("Informe quantos pacientes");
    scanf("%d", &tamanho);
    registro_pacientes rg[tamanho];
    
    for(int i = 0; i < tamanho; i++){
    
    printf("Informe os dados dos pacientes");
    printf("Nome:\n Idade:\n Diagnostico:");
    scanf("%s", rg[i].nome);
    scanf("%d", &rg[i].idade);
    scanf("%s", rg[i].diagnostico);
    }

    exibir_pacientes(rg,tamanho);

    return 0;
}