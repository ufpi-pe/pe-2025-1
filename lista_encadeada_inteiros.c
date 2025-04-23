#include <stdio.h>
#include <stdlib.h>

struct node{
    int info;
    struct node* proximo;
};

typedef struct node Lista;

/* declara e inicia a lista de inteiros */
Lista *lista_de_inteiros = NULL;

/* funcao que cria uma nova lista de inteiros */
Lista *cria_lista_vazia(){
    return NULL;
}

/* insere um novo elemento no inicio da lista */
Lista *insere(Lista *lista, int valor){
    Lista *novo = (Lista *)malloc(sizeof(Lista));
    novo->info = valor;
    novo->proximo = lista;
    return novo;
}

/* mostra os elementos da lista */
void mostra_elementos(Lista *lista){
    Lista *p;

    for (p = lista; p != NULL; p = p->proximo){
        printf("Info: %d\n", p->info);
    }
}

/* 
    testa se a lista esta vazia
    retorna 1 se vazia
    retorna 0 se nao vazia
*/
int teste_lista_vazia(Lista *lista){
    return (lista == NULL);
}

/*
    Busca um elemento na lista
    se elemento for encontrado, retorna o elemento
    se elemento nao for encontrado retorna NULL
*/
Lista *busca_na_lista(Lista *lista, int valor){
    Lista *p;
    for (p = lista; p != NULL; p = p->proximo ){
        if (p->info == valor){
            return p;
        }
    }
    return NULL;
}

/* destroi a lista lista liberando todos os elementos da memoria */
void libera_elementos_lista(Lista *lista){
    Lista *p = lista;

    while (p != NULL)
    {
        Lista *temp = p->proximo; /* guarda a referencia par a proximo elemento */
        free(p); /* libera memoria apontada por p */
        p = temp;
    }
}

int main(){
    printf("Lista encadeada de inteiros\n");
    printf("Cria uma nova lista\n");
    lista_de_inteiros = cria_lista_vazia();
    printf("Insere um novo elemento\n");
    lista_de_inteiros = insere(lista_de_inteiros, 9);
    lista_de_inteiros = insere(lista_de_inteiros, 8);
    lista_de_inteiros = insere(lista_de_inteiros, 6);  
    lista_de_inteiros = insere(lista_de_inteiros, 6);  
    mostra_elementos(lista_de_inteiros);
    printf("Lista vazia? %d\n", teste_lista_vazia(lista_de_inteiros));
    lista_de_inteiros=busca_na_lista(lista_de_inteiros, 9);
    printf("Busca o elemento 9 na lista: %d\n", lista_de_inteiros->info);
    printf("Libera elementos da lista\n");
    libera_elementos_lista(lista_de_inteiros);
    return 0;
}
