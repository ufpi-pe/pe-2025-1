## **Arrays e Matrizes em C: Armazenando Coleções de Dados**

### **O que são Arrays?**

Um **array** (ou vetor) é uma coleção de elementos do mesmo tipo, armazenados em posições contíguas de memória. Cada elemento pode ser acessado por um índice.

**Características:**
1. **Tipo fixo:** Todos os elementos de um array devem ser do mesmo tipo.
2. **Tamanho fixo:** O tamanho do array é definido no momento da declaração e não pode ser alterado.
3. **Índices:** Os elementos são acessados por índices, começando em 0.

---

### **Declaração e Inicialização de Arrays**

**Sintaxe:**
```c
tipo nome_array[tamanho];
```

**Exemplo:**
```c
#include <stdio.h>

int main() {
    int numeros[5]; // Declara um array de 5 inteiros
    numeros[0] = 10; // Atribui o valor 10 ao primeiro elemento
    numeros[1] = 20; // Atribui o valor 20 ao segundo elemento

    printf("Primeiro elemento: %d\n", numeros[0]); // Saída: 10
    printf("Segundo elemento: %d\n", numeros[1]); // Saída: 20

    return 0;
}
```

**Inicialização direta:**
```c
int numeros[] = {10, 20, 30, 40, 50}; // Tamanho inferido automaticamente
```

---

### **Acessando Elementos de um Array**

Os elementos de um array são acessados usando índices. O índice do primeiro elemento é 0, e o índice do último elemento é `tamanho - 1`.

**Exemplo:**
```c
#include <stdio.h>

int main() {
    int numeros[] = {10, 20, 30, 40, 50};

    for (int i = 0; i < 5; i++) {
        printf("Elemento %d: %d\n", i, numeros[i]);
    }

    return 0;
}
```

**Saída:**
```
Elemento 0: 10
Elemento 1: 20
Elemento 2: 30
Elemento 3: 40
Elemento 4: 50
```

---

### **O que são Matrizes?**

Uma **matriz** é um array multidimensional, ou seja, um array de arrays. A matriz mais comum é a bidimensional (2D), que pode ser vista como uma tabela com linhas e colunas.

**Características:**
1. **Duas dimensões:** Linhas e colunas.
2. **Tamanho fixo:** O número de linhas e colunas é definido na declaração.

---

### **Declaração e Inicialização de Matrizes**

**Sintaxe:**
```c
tipo nome_matriz[linhas][colunas];
```

**Exemplo:**
```c
#include <stdio.h>

int main() {
    int matriz[2][3]; // Declara uma matriz 2x3

    // Atribuindo valores
    matriz[0][0] = 1;
    matriz[0][1] = 2;
    matriz[0][2] = 3;
    matriz[1][0] = 4;
    matriz[1][1] = 5;
    matriz[1][2] = 6;

    // Acessando valores
    printf("Elemento [0][0]: %d\n", matriz[0][0]); // Saída: 1
    printf("Elemento [1][2]: %d\n", matriz[1][2]); // Saída: 6

    return 0;
}
```

**Inicialização direta:**
```c
int matriz[2][3] = {
    {1, 2, 3},
    {4, 5, 6}
};
```

---

### **Acessando Elementos de uma Matriz**

Os elementos de uma matriz são acessados usando dois índices: um para a linha e outro para a coluna.

**Exemplo:**
```c
#include <stdio.h>

int main() {
    int matriz[2][3] = {
        {1, 2, 3},
        {4, 5, 6}
    };

    for (int i = 0; i < 2; i++) { // Loop pelas linhas
        for (int j = 0; j < 3; j++) { // Loop pelas colunas
            printf("Elemento [%d][%d]: %d\n", i, j, matriz[i][j]);
        }
    }

    return 0;
}
```

**Saída:**
```
Elemento [0][0]: 1
Elemento [0][1]: 2
Elemento [0][2]: 3
Elemento [1][0]: 4
Elemento [1][1]: 5
Elemento [1][2]: 6
```

---

### **Arrays e Matrizes como Parâmetros de Funções**

Em C, arrays e matrizes podem ser passados como parâmetros para funções. No caso de matrizes, é necessário especificar o número de colunas.

**Exemplo com Array:**
```c
#include <stdio.h>

// Função que imprime um array
void imprimirArray(int arr[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int numeros[] = {10, 20, 30, 40, 50};
    imprimirArray(numeros, 5); // Passa o array e seu tamanho
    return 0;
}
```

**Exemplo com Matriz:**
```c
#include <stdio.h>

// Função que imprime uma matriz
void imprimirMatriz(int matriz[][3], int linhas) {
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int matriz[2][3] = {
        {1, 2, 3},
        {4, 5, 6}
    };
    imprimirMatriz(matriz, 2); // Passa a matriz e o número de linhas
    return 0;
}
```

---

### **Resumo**

- **Arrays** são coleções de elementos do mesmo tipo, acessados por índices.
- **Matrizes** são arrays multidimensionais, comumente usadas para representar tabelas.
- Arrays e matrizes têm tamanho fixo, definido na declaração.
- Podem ser passados como parâmetros para funções, mas o tamanho das colunas em matrizes deve ser especificado.

---

### **Exemplo Completo**

Aqui está um exemplo completo que combina arrays e matrizes:

```c
#include <stdio.h>

// Função para somar dois arrays
void somarArrays(int arr1[], int arr2[], int resultado[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        resultado[i] = arr1[i] + arr2[i];
    }
}

// Função para multiplicar duas matrizes
void multiplicarMatrizes(int mat1[][3], int mat2[][3], int resultado[][3], int linhas) {
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < 3; j++) {
            resultado[i][j] = mat1[i][j] * mat2[i][j];
        }
    }
}

int main() {
    // Arrays
    int arr1[] = {1, 2, 3};
    int arr2[] = {4, 5, 6};
    int resultadoArr[3];
    somarArrays(arr1, arr2, resultadoArr, 3);

    printf("Soma dos arrays: ");
    for (int i = 0; i < 3; i++) {
        printf("%d ", resultadoArr[i]);
    }
    printf("\n");

    // Matrizes
    int mat1[2][3] = {
        {1, 2, 3},
        {4, 5, 6}
    };
    int mat2[2][3] = {
        {2, 2, 2},
        {3, 3, 3}
    };
    int resultadoMat[2][3];
    multiplicarMatrizes(mat1, mat2, resultadoMat, 2);

    printf("Multiplicação das matrizes:\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", resultadoMat[i][j]);
        }
        printf("\n");
    }

    return 0;
}
```

**Saída:**
```
Soma dos arrays: 5 7 9 
Multiplicação das matrizes:
2 4 6 
12 15 18 
```

---

### **Exemplo: Lendo Elementos de um Array com `scanf`**

```c
#include <stdio.h>

int main() {
    int tamanho;

    // Solicita o tamanho do array
    printf("Digite o tamanho do array: ");
    scanf("%d", &tamanho);

    // Declara o array com o tamanho fornecido
    int array[tamanho];

    // Loop para ler os elementos do array
    for (int i = 0; i < tamanho; i++) {
        printf("Digite o valor para a posição %d: ", i);
        scanf("%d", &array[i]); // Lê o valor e armazena no array
    }

    // Exibe os elementos do array
    printf("Elementos do array:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("array[%d] = %d\n", i, array[i]);
    }

    return 0;
}
```

---

### **Explicação do Código**

1. **Solicitação do Tamanho do Array:**
   - O programa pergunta ao usuário o tamanho do array.
   - O valor é armazenado na variável `tamanho`.

2. **Declaração do Array:**
   - O array é declarado com o tamanho fornecido pelo usuário.

3. **Leitura dos Elementos:**
   - Um loop `for` é usado para percorrer o array.
   - Em cada iteração, o programa solicita ao usuário que digite um valor.
   - O valor é armazenado na posição correspondente do array usando `scanf`.

4. **Exibição dos Elementos:**
   - Outro loop `for` é usado para exibir os valores armazenados no array.

---

### **Exemplo de Execução**

Se o usuário digitar o seguinte:

```
Digite o tamanho do array: 4
Digite o valor para a posição 0: 10
Digite o valor para a posição 1: 20
Digite o valor para a posição 2: 30
Digite o valor para a posição 3: 40
```

A saída será:

```
Elementos do array:
array[0] = 10
array[1] = 20
array[2] = 30
array[3] = 40
```

---

### **Observações**

1. **Validação de Entrada:**
   - Em um programa real, é importante validar a entrada do usuário para garantir que o tamanho do array seja um número positivo e que os valores digitados sejam do tipo esperado.

2. **Uso de `&` no `scanf`:**
   - O operador `&` é usado para passar o endereço da variável onde o valor será armazenado. No caso de arrays, `array[i]` já é um endereço, mas como estamos lidando com elementos individuais, usamos `&array[i]`.

3. **Arrays Multidimensionais:**
   - Para ler elementos de uma matriz (array bidimensional), você pode usar dois loops `for` aninhados, um para as linhas e outro para as colunas.

---

### **Exemplo com Matriz (Array Bidimensional)**

Aqui está um exemplo de como ler elementos de uma matriz:

```c
#include <stdio.h>

int main() {
    int linhas, colunas;

    // Solicita o número de linhas e colunas da matriz
    printf("Digite o número de linhas: ");
    scanf("%d", &linhas);
    printf("Digite o número de colunas: ");
    scanf("%d", &colunas);

    // Declara a matriz com as dimensões fornecidas
    int matriz[linhas][colunas];

    // Loop para ler os elementos da matriz
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("Digite o valor para a posição [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }

    // Exibe os elementos da matriz
    printf("Elementos da matriz:\n");
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    return 0;
}
```

**Exemplo de Execução:**

Se o usuário digitar o seguinte:

```
Digite o número de linhas: 2
Digite o número de colunas: 3
Digite o valor para a posição [0][0]: 1
Digite o valor para a posição [0][1]: 2
Digite o valor para a posição [0][2]: 3
Digite o valor para a posição [1][0]: 4
Digite o valor para a posição [1][1]: 5
Digite o valor para a posição [1][2]: 6
```

A saída será:

```
Elementos da matriz:
1 2 3 
4 5 6 
```

---
