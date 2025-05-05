# Algoritmo de Ordenação de Lista Encadeada

Algoritmo de ordenação para listas encadeadas que funciona de forma semelhante ao **Insertion Sort** (ordenação por inserção). Vamos analisá-lo passo a passo:

## Estrutura Básica
```c
No* ordenar_crescente(No *lista) {
    if (lista == NULL || lista->proximo == NULL) {
        return lista; // Lista vazia ou com apenas um elemento já está ordenada
    }
```
- A função recebe o ponteiro para o primeiro nó da lista
- Verifica se a lista está vazia (`NULL`) ou tem apenas um elemento - nesses casos, já está ordenada por definição

## Inicialização
```c
    No *ordenada = NULL;
    No *atual = lista;
```
- `ordenada`: será nossa nova lista ordenada (inicialmente vazia)
- `atual`: ponteiro para percorrer a lista original

## Loop Principal
```c
    while (atual != NULL) {
        No *proximo = atual->proximo;
```
- Enquanto houver elementos na lista original:
  - Guardamos o próximo nó (`proximo`) antes de manipular o atual

## Inserção na Lista Ordenada
Há dois casos principais:

### 1. Inserir no início da lista ordenada
```c
        if (ordenada == NULL || ordenada->valor >= atual->valor) {
            atual->proximo = ordenada;
            ordenada = atual;
        }
```
- Caso a lista ordenada esteja vazia OU
- O valor do nó atual seja menor ou igual ao primeiro da lista ordenada
- Fazemos a inserção no início:
  - O próximo do nó atual aponta para a lista ordenada atual
  - A lista ordenada agora começa com o nó atual

### 2. Inserir no meio/fim da lista ordenada
```c
        else {
            No *temp = ordenada;
            while (temp->proximo != NULL && temp->proximo->valor < atual->valor) {
                temp = temp->proximo;
            }
            atual->proximo = temp->proximo;
            temp->proximo = atual;
        }
```
- Percorremos a lista ordenada até encontrar a posição correta:
  - Avançamos enquanto houver próximo E o valor do próximo for menor que o valor atual
- Quando encontramos a posição:
  - O próximo do nó atual aponta para o que era o próximo do temp
  - O próximo do temp agora aponta para o nó atual

## Atualização e Retorno
```c
        atual = proximo;
    }
    
    return ordenada;
}
```
- Avançamos para o próximo nó da lista original
- No final, retornamos o ponteiro para a lista ordenada

## Complexidade
- **Tempo**: O(n²) no pior caso (lista em ordem inversa)
- **Espaço**: O(1) (usa espaço constante, apenas reorganiza os nós existentes)

## Exemplo Prático
Suponha a lista: 3 → 1 → 4 → 2

Passo a passo:
1. Insere 3 na lista vazia → ordenada: 3
2. Insere 1 no início → ordenada: 1 → 3
3. Insere 4 no final → ordenada: 1 → 3 → 4
4. Insere 2 entre 1 e 3 → ordenada: 1 → 2 → 3 → 4

Este algoritmo é eficiente para listas pequenas ou quase ordenadas, mas pode ser lento para listas grandes desordenadas.
