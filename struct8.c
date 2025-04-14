#include <stdio.h>

typedef struct{
    float base;
    float altura;
}area_perimetro;

void area(float base, float altura){
  float area = base * altura;
  printf("Area: %.2f", area);
}
void perimetro(float base, float altura){
    float perimetro = (base * 2) + (altura * 2);
    printf("Perimetro: %.2f", perimetro);
}

int main(){
    area_perimetro ap;
    printf("Insira os valores da base e da altura para imprimir a area e o perimetro");
    scanf("%f", &ap.base);
    scanf("%f", &ap.altura);
    area(ap.base, ap.altura);
    perimetro(ap.base, ap.altura);

    return 0;
}