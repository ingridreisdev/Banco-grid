#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "banco.h"

void consultarSaldo(Conta *cliente) {
    printf("===SALDO===\n");
    printf("Titular: %s\n", cliente->nome);
    printf("Agencia: %d\n", cliente->agencia);
    printf("Saldo: R$ %.2f\n", cliente->saldo);
}

void depositar(Conta *cliente) {
    float valor;
    printf("===DEPOSITAR===\n");
    scanf("%f", &valor);
    if (valor <= 0) {
        printf("Valor invalido\n");
        return;
    }
    cliente->saldo += valor;
    printf("Deposito realizado! Novo saldo: R$ %.2f\n", cliente->saldo);
    sprintf(cliente->extrato[cliente->qtdOperacoes], "Deposito: R$ %.2f", valor);
    cliente->qtdOperacoes++;
}

void sacar(Conta *cliente) {
    float valor;
    printf("===SAQUE===\n");
    scanf("%f", &valor);
    if (valor <= 0) {
        printf("Valor invalido\n");
        return;
    }
    if (valor > cliente->saldo) {
        printf("Saldo insuficiente\n");
        return;
    }
    cliente->saldo -= valor;
    printf("Saque realizado! Novo saldo: R$ %.2f\n", cliente->saldo);
    sprintf(cliente->extrato[cliente->qtdOperacoes], "Saque: R$ %.2f", valor);
    cliente->qtdOperacoes++;
}

void verExtrato(Conta *cliente) {
    printf("===EXTRATO COMPLETO===\n");
    printf("Titular: %s\n", cliente->nome);
    printf("Agencia: %d\n", cliente->agencia);
    printf("Saldo atual: R$ %.2f\n", cliente->saldo);
    printf("-----------------------\n");

    if (cliente->qtdOperacoes == 0) {
        printf("Nenhuma operacao realizada.\n");
    } else {
        for (int i = 0; i < cliente->qtdOperacoes; i++) {
            printf("%s\n", cliente->extrato[i]);
        }
    }
}
void menuConta(Conta *cliente) {
    int opcao;
    do {
        printf("\n===MENU DO CLIENTE GRID===\n");
        printf("1. Consultar saldo\n");
        printf("2. Depositar\n");
        printf("3. Sacar\n");
        printf("4. Ver extrato\n");
        printf("5. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: consultarSaldo(cliente); break;
            case 2: depositar(cliente); break;
            case 3: sacar(cliente); break;
            case 4: verExtrato(cliente); break;
            case 5: printf("Saindo...\n"); break;
            default: printf("Opcao invalida!\n");
        }
    } while (opcao != 5);
}

void criarConta() {
    Conta cliente;

    printf("Digite seu nome: ");
    scanf("%s", cliente.nome);
    printf("Digite seu CPF: ");
    scanf("%s", cliente.cpf);
    cliente.saldo = 0.0;

    srand(time(NULL));
    cliente.agencia = rand() % 9000 + 1000;
    cliente.saldo = 0.0;
    cliente.qtdOperacoes = 0;

    printf("\nConta criada com sucesso!\n");
    printf("Agencia atribuida: %d\n", cliente.agencia);
 
    menuConta(&cliente);
}
