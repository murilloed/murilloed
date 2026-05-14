#include <stdio.h>

int main() {
    int num1, num2, soma;
    
    printf("Número 1: ");
    scanf("%d", &num1);
    
    printf("Número 2: ");
    scanf("%d", &num2);
    
    soma = num1 + num2;
    printf("Resultado: %d\n", soma);
    
    return 0;
}
