#include <stdio.h>
#include <string.h>

typedef struct {
    char nomedotitular[50];
    int numerodaconta;
    float saldo;
} ContaBancaria;

void depositar_valor(ContaBancaria *conta, float valor) {
    if (valor > 0) {
        conta->saldo += valor;
        printf("Depósito de R$%.2f realizado com sucesso!\n", valor);
    } else {
        printf("Valor de depósito inválido.\n");
    }
}

void sacar_valor(ContaBancaria *conta, float valor) {
    if (valor > 0 && valor <= conta->saldo) {
        conta->saldo -= valor;
        printf("Saque de R$%.2f realizado com sucesso!\n", valor);
    } else {
        printf("Saque inválido. Verifique o saldo.\n");
    }
}

void exibir_saldo(ContaBancaria conta) {
    printf("\n--- SALDO ATUAL ---\n");
    printf("Titular: %s\n", conta.nomedotitular);
    printf("Conta: %d\n", conta.numerodaconta);
    printf("Saldo: R$%.2f\n", conta.saldo);
}

int main() {
    ContaBancaria minhaConta;
    int opcao;
    float valor;

    printf("Digite o nome do titular: ");
    scanf(" %[^\n]", minhaConta.nomedotitular); // permite espaços no nome

    printf("Digite o número da conta: ");
    scanf("%d", &minhaConta.numerodaconta);

    minhaConta.saldo = 0.0;

    do {
        printf("\n--- MENU ---\n");
        printf("1. Depositar\n");
        printf("2. Sacar\n");
        printf("3. Exibir saldo\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                printf("Digite o valor para depósito: ");
                scanf("%f", &valor);
                depositar_valor(&minhaConta, valor);
                break;
            case 2:
                printf("Digite o valor para saque: ");
                scanf("%f", &valor);
                sacar_valor(&minhaConta, valor);
                break;
            case 3:
                exibir_saldo(minhaConta);
                break;
            case 0:
                printf("Encerrando o programa.\n");
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while(opcao != 0);

    return 0;
}