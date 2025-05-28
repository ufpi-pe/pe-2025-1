#include <stdio.h>
#include <stdlib.h>
#include "operacoes.h"

void menu() {
    printf("\n=== MINI CALCULADORA CIENTIFICA ===\n");
    printf("1. Seno\n");
    printf("2. Cosseno\n");
    printf("3. Tangente\n");
    printf("4. Exponencial (e^x)\n");
    printf("5. Logaritmo Natural (ln)\n");
    printf("6. Logaritmo Base 10 (log10)\n");
    printf("7. Potenciação (x^y)\n");
    printf("8. Função Quadrática (ax² + bx + c)\n");
    printf("0. Sair\n");
    printf("Escolha uma opção: ");
}

int main() {
    int opcao, modo;
    double valor, base, expoente, a, b, c, x1, x2;
    
    do {
        menu();
        scanf("%d", &opcao);
        
        switch(opcao) {
            case 1:
                printf("Digite 1 para radianos ou 2 para graus: ");
                scanf("%d", &modo);
                printf("Digite o valor: ");
                scanf("%lf", &valor);
                printf("Seno(%.2f) = %.4f\n", valor, seno(valor, modo));
                break;
            case 2:
                printf("Digite 1 para radianos ou 2 para graus: ");
                scanf("%d", &modo);
                printf("Digite o valor: ");
                scanf("%lf", &valor);
                printf("Cosseno(%.2f) = %.4f\n", valor, cosseno(valor, modo));
                break;
            case 3:
                printf("Digite 1 para radianos ou 2 para graus: ");
                scanf("%d", &modo);
                printf("Digite o valor: ");
                scanf("%lf", &valor);
                printf("Tangente(%.2f) = %.4f\n", valor, tangente(valor, modo));
                break;
            case 4:
                printf("Digite o expoente: ");
                scanf("%lf", &valor);
                printf("e^%.2f = %.4f\n", valor, exponencial(valor));
                break;
            case 5:
                printf("Digite o valor: ");
                scanf("%lf", &valor);
                printf("ln(%.2f) = %.4f\n", valor, logaritmo_natural(valor));
                break;
            case 6:
                printf("Digite o valor: ");
                scanf("%lf", &valor);
                printf("log10(%.2f) = %.4f\n", valor, logaritmo_base10(valor));
                break;
            case 7:
                printf("Digite a base e o expoente: ");
                scanf("%lf %lf", &base, &expoente);
                printf("%.2f^%.2f = %.4f\n", base, expoente, potencia(base, expoente));
                break;
            case 8:
                printf("Digite os coeficientes a, b e c: ");
                scanf("%lf %lf %lf", &a, &b, &c);
                quadratica(a, b, c, &x1, &x2);
                printf("Raízes: x1 = %.2f, x2 = %.2f\n", x1, x2);
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while(opcao != 0);
    
    return 0;
}
