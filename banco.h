#ifndef BANCO_H
#define BANCO_H

typedef struct Conta {
    char nome[100];
    char cpf[15];
    int conta;
    int agencia;
    float saldo;
    char extrato[100][100];
    int qtdOperacoes;
} Conta;

void criarConta();
void menuConta(Conta *cliente);
void consultarSaldo(Conta *cliente);
void depositar(Conta *cliente);
void sacar(Conta *cliente);
void verExtrato(Conta *cliente);

#endif 
