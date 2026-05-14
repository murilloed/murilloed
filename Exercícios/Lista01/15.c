#include <stdio.h>

int main() {
    float valor, valorFinal;
    char formaPagt;
    
    printf("Digite o valor do produto: ");
    scanf("%f", &valor);
    
    printf("Forma de pagamento (A para à vista, P para a prazo): ");
    scanf(" %c", &formaPagt);
    
    if (formaPagt == 'A' || formaPagt == 'a') {
        valorFinal = valor - (valor * 0.10); // 10% de desconto
    } else if (formaPagt == 'P' || formaPagt == 'p') {
        valorFinal = valor + (valor * 0.05); // 5% de juros
    } else {
        printf("Opção inválida!\n");
        return 1;
    }
    
    printf("O valor final da compra é: %.2f\n", valorFinal);
    
    return 0;
}
