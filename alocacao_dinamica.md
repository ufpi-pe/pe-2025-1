# **Alocação Dinâmica na Linguagem C**  

## **Objetivos**  
1. Entender a diferença entre **alocação estática** e **alocação dinâmica**.  
2. Aprender as funções básicas para alocação dinâmica em C (`malloc`, `free`).  
3. Ver exemplos comparando alocação estática e dinâmica.

Observação: revise o uso e os conceitos de [ponteiros](https://github.com/ufpi-pe/pe-2025-1/blob/main/ponteiros.md) em C

---  

## **1. Alocação Estática vs. Alocação Dinâmica**  

### **Alocação Estática**  
- O tamanho da memória é definido em **tempo de compilação**.  
- A memória é alocada na **stack** (pilha).  
- Não pode ser redimensionada durante a execução.  
- Exemplo:  
  ```c
  int vetor[10]; // Alocação estática de um vetor com 10 inteiros
  ```

### **Alocação Dinâmica**  
- O tamanho da memória é definido em **tempo de execução**.  
- A memória é alocada na **heap**.  
- Pode ser redimensionada ou liberada conforme necessário.  
- Exemplo:  
  ```c
  int *vetor = (int*) malloc(10 * sizeof(int)); // Alocação dinâmica de um vetor com 10 inteiros
  ```

---  

## **2. Funções para Alocação Dinâmica**  

### **`malloc` (Memory Allocation)**  
- Aloca um bloco de memória do tamanho especificado.  
- **Retorna**: Um ponteiro para o início do bloco alocado (`NULL` se falhar).  
- **Sintaxe**:  
  ```c
  void* malloc(size_t tamanho);
  ```
- **Exemplo**:  
  ```c
  int *vetor = (int*) malloc(5 * sizeof(int)); // Aloca espaço para 5 inteiros
  ```
  
### **`free` (Liberação de Memória)**  
- Libera a memória alocada dinamicamente.  
- **Sintaxe**:  
  ```c
  void free(void* ponteiro);
  ```
- **Exemplo**:  
  ```c
  free(vetor); // Libera a memória alocada
  ```

---  

## **3. Comparação Prática**  

### **Exemplo 1: Vetor com Tamanho Fixo (Alocação Estática)**  
```c
#include <stdio.h>

int main() {
    int vetor[5]; // Alocação estática
    for (int i = 0; i < 5; i++) {
        vetor[i] = i + 1;
    }
    for (int i = 0; i < 5; i++) {
        printf("%d ", vetor[i]);
    }
    return 0;
}
```
**Saída**:  
```
1 2 3 4 5
```
**Problema**: O tamanho é fixo e não pode ser alterado em tempo de execução.  

### **Exemplo 2: Vetor com Tamanho Variável (Alocação Dinâmica)**  
```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int tamanho;
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tamanho);

    int *vetor = (int*) malloc(tamanho * sizeof(int)); // Alocação dinâmica
    if (vetor == NULL) {
        printf("Erro na alocação de memória!\n");
        return 1;
    }

    for (int i = 0; i < tamanho; i++) {
        vetor[i] = i + 1;
    }

    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }

    free(vetor); // Libera memória
    return 0;
}
```
**Saída (se o usuário digitar `5`)**:  
```
1 2 3 4 5
```
**Vantagem**: O tamanho é definido em tempo de execução.  

---  

## **4. Boas Práticas**  
1. **Sempre verifique** se `malloc` retorna `NULL`.  
2. **Libere a memória** com `free` para evitar vazamentos.  
3. **Evite acesso fora dos limites** para não causar *buffer overflow*.  

## **Conclusão**  
A alocação dinâmica permite maior flexibilidade no gerenciamento de memória, mas exige cuidado para evitar vazamentos e corrupção de dados. Use `malloc` e `free` com atenção!  
