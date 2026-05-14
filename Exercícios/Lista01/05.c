#include <stdio.h>

int main() {
    float metros, centimetros;
    
    printf("Digite o valor em metros: ");
    scanf("%f", &metros);
    
    centimetros = metros * 100.0;
    
    printf("%.2f metros = %.2f centímetros\n", metros, centimetros);
    return 0;
}
