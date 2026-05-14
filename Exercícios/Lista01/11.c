#include <stdio.h>

int main() {
    float media;
    
    printf("Digite a média final do aluno: ");
    scanf("%f", &media);
    
    if (media >= 7.0) {
        printf("Aprovado\n");
    } else {
        printf("Reprovado\n");
    }
    
    return 0;
}
