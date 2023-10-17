#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <locale.h>

int main() {
    int periodo = 0, i;

    float principal, percentualRendimento = 0, balance;

    printf("Digite o valor investido\n");
    scanf("%f", &principal);

    printf("Digite a quantidade de meses do investimento\n");
    scanf("%d", &periodo);

    printf("Digite o percentual de rendimento ao mês\n");
    scanf("%f", &percentualRendimento);

    percentualRendimento = percentualRendimento / 100; 

    balance = principal;

    for (i = 1; i <= periodo; i++) {
        balance = balance * (1 + percentualRendimento); 

        printf("Após o mês %d, o saldo é: R$%.2f\n", i, balance);
    }

    double imposto = 0.15 * (balance - principal);
    balance -= imposto;

    printf("\nSaldo Final: R$%.2f\n", balance);
    printf("\nValor Saldo Final - Imposto Retido na Fonte = R$%.2f\n", balance - imposto);

    return 0;
}
