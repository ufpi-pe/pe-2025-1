# Listas Encadeadas em C

## Introdução às Listas Encadeadas

### Motivação

**Problemas com vetores (arrays):**
- Tamanho fixo e pré-definido
- Dificuldade em inserir/remover elementos no meio
- Necessidade de realocação de memória para redimensionar

**Vantagens das listas encadeadas:**
- Tamanho dinâmico (cresce e diminui conforme necessário)
- Inserções e remoções eficientes em qualquer posição
- Não requer espaço contíguo na memória

## Conceitos Fundamentais

### Estrutura de um Nó

Cada elemento (nó) da lista contém:
1. Dados (informação)
2. Ponteiro para o próximo nó

```c
struct Tlista {
    int info;               // Dado armazenado
    struct Tlista* prox;    // Ponteiro para o próximo nó
};

typedef struct Tlista Lista; // Definindo um novo tipo 'Lista'
```

## Operações Básicas

### 1. Criação de uma Lista Vazia

```c
Lista* lst_cria(void) {
    return NULL; // Retorna um ponteiro nulo
}

// Uso:
Lista* minha_lista = lst_cria();
```

### 2. Inserção na "cabeça" da lista

```c
Lista* lst_insere(Lista* lst, int val) {
    Lista* novo = (Lista*)malloc(sizeof(Lista)); // 1. Aloca memória
    novo->info = val;                            // 2. Atribui valor
    novo->prox = lst;                            // 3. Aponta para a lista atual
    return novo;                                 // 4. Retorna novo elemento cabeca
}

// Uso:
minha_lista = lst_insere(minha_lista, 10);
minha_lista = lst_insere(minha_lista, 20);
```

### 3. Impressão dos Elementos

```c
void lst_imprime(Lista* lst) {
    Lista* p; // Ponteiro auxiliar para percorrer a lista
    for (p = lst; p != NULL; p = p->prox) {
        printf("Valor: %d\n", p->info);
    }
    printf("Fim da lista\n");
}
```

### 4. Verificação se a Lista está Vazia

```c
int lst_vazia(Lista* lst) {
    return (lst == NULL); // Retorna 1 se vazia, 0 caso contrário
}
```

### 5. Liberação da Memória

```c
void lst_libera(Lista* lst) {
    Lista* p = lst;
    while (p != NULL) {
        Lista* temp = p->prox; // Guarda referência para o próximo
        free(p);           // Libera o nó atual
        p = temp;             // Avança para o próximo
    }
}
```

## Exemplo Completo

```c
#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura
struct Tlista {
    int info;
    struct Tlista* prox;
};
typedef struct Tlista Lista;

// Protótipos das funções
Lista* lst_cria(void);
Lista* lst_insere(Lista* lst, int val);
void lst_imprime(Lista* lst);
int lst_vazia(Lista* lst);
void lst_libera(Lista* lst);

int main() {
    Lista* lista = lst_cria();
    
    printf("Lista vazia? %d\n", lst_vazia(lista));
    
    lista = lst_insere(lista, 10);
    lista = lst_insere(lista, 20);
    lista = lst_insere(lista, 30);
    
    lst_imprime(lista);
    
    printf("Lista vazia? %d\n", lst_vazia(lista));
    
    lst_libera(lista);
    
    return 0;
}

// Implementações das funções (como mostrado acima)
```

## Exercícios Propostos

### 1. Busca de Elemento

Implemente uma função que verifica se um valor está na lista:

```c
int lst_busca(Lista* lst, int val) {
    Lista* p;
    for (p = lst; p != NULL; p = p->prox) {
        if (p->info == val) {
            return 1; // Encontrou
        }
    }
    return 0; // Não encontrou
}
```

### 2. Lista de Alunos

Adapte a lista para armazenar estruturas de alunos:

```c
typedef struct {
    char matricula[13]; // 12 caracteres + \0
    char nome[51];      // 50 caracteres + \0
    float nota1;
    float nota2;
} Aluno;

struct TlistaAluno {
    Aluno info;
    struct TlistaAluno* prox;
};
typedef struct TlistaAluno ListaAluno;

// Funções similares, mas trabalhando com Aluno
ListaAluno* lst_aluno_insere(ListaAluno* lst, Aluno aluno) {
    ListaAluno* novo = (ListaAluno*)malloc(sizeof(ListaAluno));
    novo->info = aluno;
    novo->prox = lst;
    return novo;
}
```

### 3. Busca por Matrícula

```c
Aluno* lst_aluno_busca(ListaAluno* lst, const char* matricula) {
    ListaAluno* p;
    for (p = lst; p != NULL; p = p->prox) {
        if (strcmp(p->info.matricula, matricula) == 0) {
            return &(p->info); // Retorna ponteiro para o aluno encontrado
        }
    }
    return NULL; // Não encontrado
}
```

## Considerações Finais

- Listas encadeadas são fundamentais para entender estruturas de dados dinâmicas
- Permitem implementar pilhas, filas e outras estruturas mais complexas
- O custo de acesso é O(n), enquanto inserções/remoções no início são O(1)
- Requerem cuidado com o gerenciamento de memória para evitar vazamentos

Próximos passos: implementar remoção de elementos, listas duplamente encadeadas e listas circulares.
