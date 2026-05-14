#include <stdio.h>

int main() {
    float numero;
    
    printf("Digite um número: ");
    scanf("%f", &numero);
    
    if (numero > 0) {
        printf("Positivo\n");
    } else if (numero < 0) {
        printf("Negativo\n");
    } else {
        printf("Zero\n");
    }
    
    return 0;
}
