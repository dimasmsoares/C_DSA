#include <stdio.h>
#include <stdlib.h>

// Protótipos dos menus
void menu_principal();
void menu_lista_simples();
// (futuramente: menu_lista_dupla(), menu_lista_circular(), ...)

int main() {
    menu_principal();
    return 0;
}

// Menu principal: escolha do tipo de lista
void menu_principal() {
    int escolha;
    while (1) {
        printf("\n===== MENU PRINCIPAL =====\n");
        printf("Escolha o tipo de lista:\n");
        printf("1. Lista Encadeada Simples\n");
        printf("2. Lista Duplamente Encadeada\n");
        printf("3. Lista Circular Simples\n");
        printf("0. Sair\n");
        printf("Digite sua opção: ");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                printf("Lista Simplesmente Encadeada ainda não implementada.\n");
                break;
            case 2:
                printf("Lista Duplamente Encadeada ainda não implementada.\n");
                break;
            case 3:
                printf("Lista Circular Simples ainda não implementada.\n");
                break;
            case 0:
                printf("Encerrando o programa.\n");
                return;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    }
}
