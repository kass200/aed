#include <stdio.h>
typedef struct{
   char titulo [50];
   char autor [50];
   int ano;
}livros;
void mostrarlivros(livros l[], int tamanho, int anolimite){
    printf("\n--- LIVROS PUBLICADOS APÓS %d ---\n", anolimite);

    int encontrou = 0;
    for(int i =0; i < tamanho; i++){
        if(l[i].ano > anolimite){
            printf("Título: %s\n", l[i].titulo);
            printf("Autor: %s\n", l[i].autor);
            printf("Ano: %d\n\n", l[i].ano);
            encontrou = 1;
        }
    }
    
     if (!encontrou) {
    printf("Nenhum livro encontrado após o ano %d.\n", anolimite);
    }
}
int main(){
    int n, anolimite;
    printf("quantos livros vc quer cadastrar?");
    scanf("%d",&n);
    livros l[n];
    for(int i = 0;i < n; i++){
        printf("\n--- Livro %d ---\n", i + 1);
        printf("Título: ");
        scanf("%s", l[i].titulo);
        printf("Autor:");
        scanf("%s", l[i].autor);
        printf("Ano:");
        scanf("%d",&l[i].ano);
    }
    printf("digite o ano limite");
    scanf("%d", &anolimite);
    mostrarlivros(l,n,anolimite);

    return 0;
}