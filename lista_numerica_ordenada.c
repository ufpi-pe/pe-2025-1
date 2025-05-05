#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura do nó da lista
typedef struct no {
    int valor;
    struct no *proximo;
} No;

// Função para criar uma lista vazia
No* criar_lista() {
    return NULL;
}

// Função para inserir um número no início da lista
No* inserir(No *lista, int num) {
    No *novo_no = (No*)malloc(sizeof(No));
    
    if(novo_no) {
        novo_no->valor = num;
        novo_no->proximo = lista;
        return novo_no;
    }
    else {
        printf("Erro ao alocar memoria!\n");
        return lista;
    }
}

// Função para imprimir todos os elementos da lista
void imprimir_lista(No *lista) {
    printf("\nLista: ");
    while(lista) {
        printf("%d ", lista->valor);
        lista = lista->proximo;
    }
    printf("\n");
}

// Função para buscar um elemento na lista (busca sequencial)
void buscar_elemento(No *lista, int num) {
    int posicao = 1;
    No *aux = lista;
    
    while(aux) {
        if(aux->valor == num) {
            printf("Numero %d encontrado na posicao %d da lista!\n", num, posicao);
            return;
        }
        aux = aux->proximo;
        posicao++;
    }
    
    printf("Numero %d nao encontrado na lista!\n", num);
}

// Função para ordenar a lista em ordem crescente
No* ordenar_crescente(No *lista) {
    if (lista == NULL || lista->proximo == NULL) {
        return lista; // Lista vazia ou com apenas um elemento já está ordenada
    }
    
    No *ordenada = NULL;
    No *atual = lista;
    
    while (atual != NULL) {
        No *proximo = atual->proximo;
        
        if (ordenada == NULL || ordenada->valor >= atual->valor) {
            // Insere no início da lista ordenada
            atual->proximo = ordenada;
            ordenada = atual;
        } else {
            // Procura a posição correta para inserção
            No *temp = ordenada;
            while (temp->proximo != NULL && temp->proximo->valor < atual->valor) {
                temp = temp->proximo;
            }
            atual->proximo = temp->proximo;
            temp->proximo = atual;
        }
        
        atual = proximo;
    }
    
    return ordenada;
}

// Função para ordenar a lista em ordem decrescente
No* ordenar_decrescente(No *lista) {
    if (lista == NULL || lista->proximo == NULL) {
        return lista; // Lista vazia ou com apenas um elemento já está ordenada
    }
    
    No *ordenada = NULL;
    No *atual = lista;
    
    while (atual != NULL) {
        No *proximo = atual->proximo;
        
        if (ordenada == NULL || ordenada->valor <= atual->valor) {
            // Insere no início da lista ordenada
            atual->proximo = ordenada;
            ordenada = atual;
        } else {
            // Procura a posição correta para inserção
            No *temp = ordenada;
            while (temp->proximo != NULL && temp->proximo->valor > atual->valor) {
                temp = temp->proximo;
            }
            atual->proximo = temp->proximo;
            temp->proximo = atual;
        }
        
        atual = proximo;
    }
    
    return ordenada;
}

// Função para liberar a memória alocada para a lista
void liberar_lista(No *lista) {
    No *aux;
    
    while(lista) {
        aux = lista;
        lista = lista->proximo;
        free(aux);
    }
    
    printf("\nMemoria liberada com sucesso!\n");
}

int main() {
    No *lista = criar_lista();
    int opcao, valor;
    
    do {
        printf("\nMENU DE OPCOES\n");
        printf("1 - Inserir numero\n");
        printf("2 - Imprimir lista\n");
        printf("3 - Buscar numero\n");
        printf("4 - Ordenar crescente\n");
        printf("5 - Ordenar decrescente\n");
        printf("6 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        
        switch(opcao) {
            case 1:
                printf("Digite um numero inteiro: ");
                scanf("%d", &valor);
                lista = inserir(lista, valor);
                break;
                
            case 2:
                imprimir_lista(lista);
                break;
                
            case 3:
                printf("Digite o numero a ser buscado: ");
                scanf("%d", &valor);
                buscar_elemento(lista, valor);
                break;
                
            case 4:
                lista = ordenar_crescente(lista);
                printf("Lista ordenada em ordem crescente!\n");
                break;
                
            case 5:
                lista = ordenar_decrescente(lista);
                printf("Lista ordenada em ordem decrescente!\n");
                break;
                
            case 6:
                liberar_lista(lista);
                printf("Programa encerrado.\n");
                break;
                
            default:
                printf("Opcao invalida!\n");
        }
    } while(opcao != 6);
    
    return 0;
}
