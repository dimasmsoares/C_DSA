/* 💡 Desafio Integrado: Lista, Pilha e Fila

Implemente em C três estruturas separadas: Lista, Pilha e Fila, todas usando 
o mesmo tipo de nó com valor e ponteiro para o próximo.

Depois:
	•	Crie um menu interativo para o usuário escolher qual estrutura usar.
	•	Permita inserir, remover e imprimir os elementos conforme a estrutura escolhida.

🎯 Requisitos:
	1.	Use o mesmo typedef struct No:
    typedef struct No {
        int valor;
        struct No* proximo;
    } No;

    2.	Crie:
	•	Funções inserir_lista, remover_lista, imprimir_lista
	•	Funções push, pop, imprimir_pilha
	•	Funções enqueue, dequeue, imprimir_fila
	
    3.	No main, faça um menu mais ou menos assim:
    
    1 - Usar Lista
    2 - Usar Pilha
    3 - Usar Fila
    0 - Sair

    Se o usuário escolher uma opção, ele poderá:
    a - Inserir valor
    b - Remover valor
    c - Imprimir estrutura
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct No
{
    int valor;
    struct No* p_no;
} No;

// Protótipos
No* criar_no(10, NULL);

//void inserir_lista(No ** p_p_inicio_lista, int valor, int posicao);
//void remover_lista();
void imprimir_lista();
//int tamanho_lista();

int main()
{
    No* lista = criar_no(10);

    imprimir_lista(lista);


}

No* criar_no(int valor, No* p_next)
{
    No* p_no = (No*)malloc(sizeof(No));
    if (p_no == NULL) {
        printf("[criar_no] Erro de alocação de memória!\n");
        exit(1);
    }
    p_no->valor = valor;
    p_no->p_no = p_next;
    return p_no;
}

void imprimir_lista(No* no_inicial)
{
    if (no_inicial == NULL)
    {
        printf("A lista está vazia!\n");
    }
    else 
    {
        while(no_inicial != NULL)
        {
            printf("[ %d ]", no_inicial->valor);
            no_inicial = no_inicial->p_no;
        }
        printf("\n");
    }
}