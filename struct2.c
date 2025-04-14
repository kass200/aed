#include <stdio.h>
typedef struct{
    char aluno[50];
    int matricula;
    float nota;
}alunos;

int main(){
    alunos a[5];

    for(int i = 0; i < 5; i++) {
        printf("Digite o nome, matricula e nota aluno %d", i + 1);
        scanf("%s %d %f", a[i].aluno, &a[i].matricula, &a[i].nota);
    }
    for(int i = 0; i <5; i++) {
        printf("aluno: %s \n matricula: %d \n nota: %.2f", a[i].aluno, a[i].matricula, a[i].nota);
    }

    return 0;
}