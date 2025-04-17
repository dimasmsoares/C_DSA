#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int value;
    struct Node* p_next_node;
} Node;

void inserir_valor_fim(Node **p2_inicio_lista, int valor);
void inserir_valor_inicio(Node **p2_inicio_lista, int valor);
void imprimir_lista(Node *p_inicio_lista);
void liberar_lista(Node **p2_inicio_lista);
//void inserir_valor(Node **p2_inicio_lista, int valor, int posicao);
void remover_valor(Node **p2_inicio_lista, int valor);
int tamanho(Node *p_inicio_lista);

int main()
{
    Node* p_lista = NULL;
    printf("A lista tem %d elementos\n", tamanho(p_lista));
    inserir_valor_fim(&p_lista, 20);
    inserir_valor_inicio(&p_lista, 0);
    inserir_valor_fim(&p_lista, 20);
    inserir_valor_fim(&p_lista, 30);
    inserir_valor_fim(&p_lista, 20);
    inserir_valor_inicio(&p_lista, 20);
    imprimir_lista(p_lista);
    printf("A lista tem %d elementos\n", tamanho(p_lista));
    remover_valor(&p_lista, 20);
    imprimir_lista(p_lista);
    printf("A lista tem %d elementos\n", tamanho(p_lista));
    liberar_lista(&p_lista);

    return 0;
}

void inserir_valor_fim(Node **p2_inicio_lista, int valor)
{   /*
    Essa função adiciona um novo nó (com um novo valor) ao final da lista.
    Args:
        - p2_inicio_lista: ponteiro para o ponteiro que aponta para o inicio da lista
        - valor: número inteiro a ser armazenado novo nó
    */
    printf("[inserir_valor_fim] INICIO\n");
    
    // Alocação dinâmica de espaço na memória (heap) para um nó. p_novo aponta para essa memória alocada 
    Node* p_novo = (Node*)malloc(sizeof(Node));
    p_novo->value = valor;
    p_novo->p_next_node = NULL;

    // Se a lista estiver vazia
    if (*p2_inicio_lista == NULL)
    {
        printf("[inserir_valor_fim] A lista esta vazia\n");
        *p2_inicio_lista = p_novo;  
        printf("[inserir_valor_fim] Valor (%d) adicionado com sucesso!\n", valor);
    }
    else{ //Se a lista não está vazia...
        // Percorre-se a lista até o fim para que o ultimo elemento passe a apontar para o nó criado (p_novo)
        printf("[inserir_valor_fim] A lista NAO esta vazia\n");
        Node *atual = *p2_inicio_lista;
        while(atual->p_next_node != NULL){
            atual = atual->p_next_node;
        }
        atual->p_next_node = p_novo;
        printf("[inserir_valor_fim] Valor (%d) adicionado com sucesso!\n", valor);
    }
    printf("[inserir_valor_fim] FIM\n");
}

void inserir_valor_inicio(Node **p2_inicio_lista, int valor)
{   /*
    Essa função adiciona um novo nó (com um novo valor) no início da lista.
    Args:
        - p2_inicio_lista: ponteiro para o ponteiro que aponta para o inicio da lista
        - valor: número inteiro a ser armazenado novo nó
    */
    printf("[inserir_valor_inicio] INICIO\n");

    // Alocação dinâmica de espaço na memória (heap) para um nó. p_novo aponta para essa memória alocada 
    Node *p_novo = (Node*)malloc(sizeof(Node));
    p_novo->value = valor;
    // Novo nó aponta para o antigo primeiro elemento (ou NULL, se a lista estiver vazia)
    p_novo->p_next_node = *p2_inicio_lista;

    // Atualiza o início da lista para o novo nó
    *p2_inicio_lista = p_novo;

    printf("[inserir_valor_inicio] Valor (%d) adicionado com sucesso!\n", valor);
}

void imprimir_lista(Node* p_inicio_lista) 
{   /*
    Essa função imprime os valores da lista.
    Args:
        - p_inicio_lista: ponteiro que aponta para o inicio da lista
    */
    if (p_inicio_lista == NULL) {
        printf("NULL\n");
    } else {
        Node* p_atual = p_inicio_lista;
        while (p_atual != NULL) {
            printf("[%d] --> ", p_atual->value);
            p_atual = p_atual->p_next_node;
        }
        printf("NULL\n");
    }
}

void liberar_lista(Node **p2_inicio_lista)
{   
    Node *atual = *p2_inicio_lista;
    Node *temp;

    while (atual != NULL)
    {
        temp = atual;                    // Guarda o nó atual
        atual = atual->p_next_node;      // Avança para o próximo
        free(temp);                      // Libera o nó anterior
    }

    *p2_inicio_lista = NULL;  // Opcional: zera a lista para evitar ponteiro solto
}

void remover_valor(Node **p2_inicio_lista, int valor)
{   /*
    Essa função remove todos os nós (com um determinado valor) da lista.
    Args:
        - p2_inicio_lista: ponteiro para o ponteiro que aponta para o inicio da lista
        - valor: número inteiro a ser removido
    */
    Node *p_atual = *p2_inicio_lista;
    Node *p_anterior = NULL;
    Node *p_temp;
    if(p_atual == NULL)
    {
        printf("[remover_valor] A lista esta vazia\n");
    }
    else{
        while(p_atual != NULL){
            if(p_atual->value == valor)
            {
                if(p_atual == *p2_inicio_lista)
                {   // Caso especial: nó a ser removido é o primeiro da lista
                    *p2_inicio_lista = p_atual->p_next_node;
                }
                else
                {
                    p_anterior->p_next_node = p_atual->p_next_node;
                }
                p_temp = p_atual;
                p_atual = p_atual->p_next_node;
                free(p_temp);

            }
            else
            {
                p_anterior = p_atual;
                p_atual = p_atual->p_next_node;
            }
        }
    }
}

int tamanho(Node *p_inicio_lista)
{   /* 
    Essa função calcula o tamanho da lista.
    Args:
        - p_inicio_lista: ponteiro que aponta para o inicio da lista.
    Return:
        - tam: inteiro que representa o tamanho (quantidade de nós) da lista.
    */
    Node *p_atual = p_inicio_lista;
    int tam = 0;
    while(p_atual != NULL)
    {
        tam++;
        p_atual = p_atual->p_next_node;
    }
    return tam;
}