#include <stdio.h>

int main() {
    int idade;
    
    printf("Digite a idade: ");
    scanf("%d", &idade);
    
    if (idade >= 0 && idade <= 12) {
        printf("Criança\n");
    } else if (idade >= 13 && idade <= 17) {
        printf("Adolescente\n");
    } else if (idade >= 18) {
        printf("Adulto\n");
    } else {
        printf("Idade inválida.\n");
    }
    
    return 0;
}
