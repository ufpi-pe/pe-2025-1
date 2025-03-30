# **Ponteiros em C: Endereços de Memória e Manipulação Direta**

### **O que são Ponteiros em C?**

Em C, **ponteiros** são variáveis que armazenam **endereços de memória** de outras variáveis. Eles permitem acesso e manipulação indireta de dados, oferecendo controle preciso sobre a memória.

**Por que usar ponteiros?**  
1. **Eficiência:** Permitem manipular grandes estruturas de dados (como arrays e strings) sem copiá-las.  
2. **Flexibilidade:** Facilitam a passagem de parâmetros por referência (modificando valores originais em funções).  
3. **Alocação dinâmica:** Essenciais para gerenciar memória manualmente (com `malloc`, `calloc`, `free`).  

---

### **Como Declarar e Usar Ponteiros**

Para declarar um ponteiro, use o operador `*` após o tipo de dado.  
Para acessar o endereço de uma variável, use `&`.  
Para acessar o valor no endereço apontado, use `*` (dereferência).  

**Sintaxe:**  
```c
tipo *nome_ponteiro;  // Declaração
nome_ponteiro = &variavel;  // Atribuição de endereço
*ponteiro = valor;  // Modificação do valor apontado
```

**Exemplo:**  
```c
#include <stdio.h>

int main() {
    int x = 10;
    int *ptr = &x;  // ptr armazena o endereço de x

    printf("Endereço de x: %p\n", ptr);  // Saída: endereço em hexadecimal
    printf("Valor de x via ponteiro: %d\n", *ptr);  // Saída: 10

    *ptr = 20;  // Modifica x indiretamente
    printf("Novo valor de x: %d\n", x);  // Saída: 20

    return 0;
}
```

---

### **Passagem por Referência com Ponteiros**

Em C, toda passagem de parâmetros é **por valor** (cópia). Ponteiros simulam **passagem por referência**, permitindo que funções modifiquem variáveis originais.

**Exemplo:**  
```c
#include <stdio.h>

void dobrar(int *ptr) {
    *ptr = *ptr * 2;  // Altera o valor no endereço apontado
}

int main() {
    int num = 5;
    dobrar(&num);  // Passa o endereço de num
    printf("Valor dobrado: %d\n", num);  // Saída: 10
    return 0;
}
```

---

### **Ponteiros e Arrays**

Arrays e ponteiros estão intimamente ligados em C. O nome de um array é um **ponteiro constante** para seu primeiro elemento.

**Exemplo:**  
```c
#include <stdio.h>

int main() {
    int vetor[3] = {10, 20, 30};
    int *ptr = vetor;  // Equivalente a ptr = &vetor[0]

    // Acessando elementos via aritmética de ponteiros
    printf("Primeiro elemento: %d\n", *ptr);       // Saída: 10
    printf("Segundo elemento: %d\n", *(ptr + 1));  // Saída: 20

    return 0;
}
```

---

### **Alocação Dinâmica de Memória**

Ponteiros são usados com `malloc`, `calloc` e `free` para alocar e liberar memória manualmente no **heap**.

**Exemplo:**  
```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int *ptr = (int *)malloc(3 * sizeof(int));  // Aloca array de 3 inteiros

    if (ptr == NULL) {
        printf("Falha na alocação!\n");
        return 1;
    }

    ptr[0] = 100;  // Atribui valores
    ptr[1] = 200;
    free(ptr);      // Libera a memória

    return 0;
}
```

---

### **Ponteiros para Estruturas**

Ponteiros podem apontar para estruturas (`struct`), usando `->` para acessar campos.

**Exemplo:**  
```c
#include <stdio.h>

typedef struct {
    int idade;
    char nome[50];
} Pessoa;

int main() {
    Pessoa p1 = {25, "João"};
    Pessoa *ptr = &p1;

    printf("Nome: %s, Idade: %d\n", ptr->nome, ptr->idade);  // Acesso com ->
    return 0;
}
```

---

### **Cuidados com Ponteiros**

1. **Ponteiros não inicializados:** Apontam para lixo de memória. Sempre inicialize.  
   ```c
   int *ptr;  // Perigoso! Pode causar comportamento indefinido.
   ```  
2. **Dangling pointers:** Ponteiros que apontam para memória já liberada.  
   ```c
   int *ptr = malloc(sizeof(int));
   free(ptr);
   *ptr = 10;  // ERRO: ptr agora é "dangling".
   ```  
3. **Vazamentos de memória:** Esquecer de liberar memória alocada.  

---

### **Exercícios Práticos**

1. **Troca de Valores:**  
   Escreva uma função `trocar(int *a, int *b)` que troque os valores de duas variáveis.  

2. **Soma de Array:**  
   Crie uma função que some os elementos de um array usando aritmética de ponteiros.  

3. **Lista Dinâmica:**  
   Implemente uma lista ligada simples usando alocação dinâmica.  

---

### **Resumo**

- **Ponteiros** armazenam endereços de memória.  
- **`&`** obtém o endereço de uma variável.  
- **`*`** acessa ou modifica o valor apontado.  
- **Passagem por referência** permite modificar variáveis em funções.  
- **Arrays** e **strings** são acessados eficientemente via ponteiros.  
- **Alocação dinâmica** (`malloc`, `free`) gerencia memória manualmente.  

**Próximo tópico:** Ponteiros avançados (ponteiros para funções, ponteiros duplos).  

--- 

### **Material de Apoio**  
- Livro: *"C Programming Language"* (Kernighan & Ritchie).  
- [Tutorial sobre Ponteiros (GeeksforGeeks)](https://www.geeksforgeeks.org/pointers-in-c/).  
