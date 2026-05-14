#include <stdio.h>

int main() {
    char nomeProduto[100];
    float valorProduto, valorTotal, valorFinal;
    int quantidade;
    
    printf("Nome do produto: ");
    scanf("%99s", nomeProduto);
    
    printf("Valor do produto: ");
    scanf("%f", &valorProduto);
    
    printf("Quantidade comprada: ");
    scanf("%d", &quantidade);
    
    valorTotal = valorProduto * quantidade;
    
    if (valorTotal > 500) {
        valorFinal = valorTotal - (valorTotal * 0.15); // 15% de desconto
    } else {
        valorFinal = valorTotal; // sem desconto
    }
    
    printf("\n--- Resumo ---\n");
    printf("Nome do produto: %s\n", nomeProduto);
    printf("Quantidade: %d\n", quantidade);
    printf("Valor total sem desconto: %.2f\n", valorTotal);
    
    if (valorTotal > 500) {
        printf("Valor final com desconto: %.2f\n", valorFinal);
    }
    
    return 0;
}
