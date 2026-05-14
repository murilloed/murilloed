#include <stdio.h>

int main() {
    int numero;
    
    printf("Digite um número inteiro: ");
    scanf("%d", &numero);
    
    printf("O número digitado: %d\n", numero);
    printf("O antecessor: %d\n", numero - 1);
    printf("O sucessor: %d\n", numero + 1);
    
    return 0;
}
