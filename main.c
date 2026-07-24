#include "banco.h"
#include <stdio.h>

int main() {
    int opcao;
    do {
        printf("\n===MENU PRINCIPAL BANCO GRID===\n");
        printf("1. Criar conta\n");
        printf("2. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: criarConta(); break;
            case 2: printf("\nObrigada por utilizar o Banco Grid!\n"); break;
            case 3: printf("Encerrando...\n"); break;
            default: printf("Opcao invalida!\n");
        }
    } while (opcao != 3);

    return 0;
}
