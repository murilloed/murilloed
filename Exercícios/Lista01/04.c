#include <stdio.h>

int main() {
    float nota1, nota2, media;
    
    printf("Digite a primeira nota: ");
    scanf("%f", &nota1);
    
    printf("Digite a segunda nota: ");
    scanf("%f", &nota2);
    
    media = (nota1 + nota2) / 2.0;
    
    printf("A primeira nota: %.2f\n", nota1);
    printf("A segunda nota: %.2f\n", nota2);
    printf("A média final: %.2f\n", media);
    
    return 0;
}
