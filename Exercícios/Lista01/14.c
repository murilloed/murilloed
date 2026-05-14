#include <stdio.h>

int main() {
    float salario, salarioFinal;
    
    printf("Digite o salário do funcionário: ");
    scanf("%f", &salario);
    
    if (salario < 2000) {
        salarioFinal = salario + 200;
    } else {
        salarioFinal = salario + 100;
    }
    
    printf("O salário final é: %.2f\n", salarioFinal);
    
    return 0;
}
