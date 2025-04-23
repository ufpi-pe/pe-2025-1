# Explicação do Código de Lista Ligada em C

Explicação da lista encadeada [(lista ligada) de inteiros](https://github.com/ufpi-pe/pe-2025-1/blob/main/lista_encadeada_inteiros.c) usando alocação dinâmica de memória em C.

## Estrutura Básica

```c
struct node{
    int info;
    struct node* proximo;
};

typedef struct node Lista;
```

- Define a estrutura `node` que representa cada elemento da lista:
  - `info`: armazena o valor inteiro
  - `proximo`: ponteiro para o próximo nó da lista
- `typedef` cria um alias `Lista` para `struct node`, simplificando a sintaxe

## Funções Principais

### 1. `cria_lista_vazia()`
```c
Lista *cria_lista_vazia(){
    return NULL;
}
```
- Inicializa uma lista vazia retornando NULL
- Uma lista vazia é representada por um ponteiro nulo

### 2. `insere()`
```c
Lista *insere(Lista *lista, int valor){
    Lista *novo = (Lista *)malloc(sizeof(Lista));
    novo->info = valor;
    novo->proximo = lista;
    return novo;
}
```
- Aloca memória para um novo nó (`malloc`)
- Atribui o valor ao campo `info`
- Faz o novo nó apontar para o início atual da lista
- Retorna o novo nó (que agora é o novo início da lista)
- **Obs**: Insere no início (mais eficiente - O(1))

### 3. `mostra_elementos()`
```c
void mostra_elementos(Lista *lista){
    Lista *p;
    for (p = lista; p != NULL; p = p->proximo){
        printf("Info: %d\n", p->info);
    }
}
```
- Percorre a lista do início ao fim (enquanto `p != NULL`)
- Imprime o valor de cada nó
- Complexidade: O(n)

### 4. `teste_lista_vazia()`
```c
int teste_lista_vazia(Lista *lista){
    return (lista == NULL);
}
```
- Verifica se a lista está vazia
- Retorna 1 (verdadeiro) se estiver vazia, 0 (falso) caso contrário

### 5. `busca_na_lista()`
```c
Lista *busca_na_lista(Lista *lista, int valor){
    Lista *p;
    for (p = lista; p != NULL; p = p->proximo){
        if (p->info == valor){
            return p;
        }
    }
    return NULL;
}
```
- Percorre a lista procurando um valor
- Retorna o ponteiro para o nó se encontrar, NULL caso contrário
- Complexidade: O(n) no pior caso

### 6. `libera_elementos_lista()`
```c
void libera_elementos_lista(Lista *lista){
    Lista *p = lista;
    while (p != NULL){
        Lista *temp = p->proximo;
        free(p);
        p = temp;
    }
}
```
- Percorre a lista liberando cada nó da memória
- Importante para evitar vazamentos de memória
- Armazena a referência para o próximo nó antes de liberar o atual

## Função `main()`

```c
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
```

### Fluxo de Execução:
1. Cria uma lista vazia
2. Insere quatro elementos (9, 8, 6, 6)
3. Mostra todos os elementos
4. Testa se a lista está vazia
5. Busca pelo elemento 9
6. Libera toda a memória alocada

## Observações Importantes:
1. **Alocação Dinâmica**: Cada novo elemento é alocado com `malloc`
2. **Liberação de Memória**: É essencial liberar a memória com `free` para evitar vazamentos
3. **Inserção**: Sempre no início (mais eficiente)
4. **Lista Encadeada**: Cada elemento aponta para o próximo (último aponta para NULL)

Este código implementa uma lista simples com operações básicas. Em uma aplicação real, você poderia adicionar mais funcionalidades como:
- Remoção de elementos
- Inserção ordenada
- Contagem de elementos
- Concatenção de listas
