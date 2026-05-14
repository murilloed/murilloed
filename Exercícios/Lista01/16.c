#include <stdio.h>

int main() {
    float peso, altura, imc;
    
    printf("Digite o peso (kg): ");
    scanf("%f", &peso);
    
    printf("Digite a altura (m): ");
    scanf("%f", &altura);
    
    imc = peso / (altura * altura);
    
    printf("Valor do IMC: %.2f\n", imc);
    
    return 0;
}
