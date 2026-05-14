#include <stdio.h>

int main() {
    int senha;
    
    printf("Digite a senha numérica: ");
    scanf("%d", &senha);
    
    if (senha == 1234) {
        printf("Acesso permitido\n");
    } else {
        printf("Senha incorreta\n");
    }
    
    return 0;
}
