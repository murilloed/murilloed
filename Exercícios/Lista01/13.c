#include <stdio.h>

int main() {
    float valor, valorFinal;
    
    printf("Digite o valor do produto: ");
    scanf("%f", &valor);
    
    if (valor > 100) {
        valorFinal = valor - (valor * 0.10); // 10% de desconto
    } else {
        valorFinal = valor; // sem desconto
    }
    
    printf("O valor final do produto é: %.2f\n", valorFinal);
    
    return 0;
}
