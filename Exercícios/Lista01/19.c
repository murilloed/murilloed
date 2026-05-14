#include <stdio.h>

int main() {
    float distancia, litros, consumo;
    
    printf("Digite a distância percorrida em km: ");
    scanf("%f", &distancia);
    
    printf("Digite a quantidade de combustível gasta em litros: ");
    scanf("%f", &litros);
    
    consumo = distancia / litros;
    
    printf("O consumo médio é: %.2f km/litro\n", consumo);
    
    return 0;
}
