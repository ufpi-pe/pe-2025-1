# **Exemplos de Funções com Ponteiros e Arrays em C**

Vamos explorar três exemplos práticos que envolvem **ponteiros**, **arrays unidimensionais (vetores)** e **arrays multidimensionais (matrizes)**. Cada exemplo será explicado passo a passo.

---

## **1. Soma de Dois Vetores (Array Unidimensional)**
**Objetivo:** Criar uma função que recebe dois vetores de inteiros e retorna um terceiro vetor com a soma dos elementos.

### **Código:**
```c
#include <stdio.h>

// Função que soma dois vetores e armazena o resultado em um terceiro vetor
void soma_vetores(int *vetor1, int *vetor2, int *resultado, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        resultado[i] = vetor1[i] + vetor2[i];  // Soma elemento a elemento
    }
}

int main() {
    int vetor1[] = {1, 2, 3, 4, 5};
    int vetor2[] = {6, 7, 8, 9, 10};
    int resultado[5];  // Vetor para armazenar a soma

    soma_vetores(vetor1, vetor2, resultado, 5);

    // Imprime o resultado
    printf("Soma dos vetores: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", resultado[i]);
    }
    printf("\n");

    return 0;
}
```

### **Explicação:**
1. **Parâmetros da função:**
   - `int *vetor1` e `int *vetor2`: Ponteiros para os vetores de entrada.
   - `int *resultado`: Ponteiro para o vetor que armazenará a soma.
   - `int tamanho`: Tamanho dos vetores.

2. **Processamento:**
   - A função percorre os vetores e soma os elementos correspondentes.

3. **Saída:**
   ```
   Soma dos vetores: 7 9 11 13 15
   ```

---

## **2. Soma de Duas Matrizes (Array Bidimensional)**
**Objetivo:** Criar uma função que soma duas matrizes e armazena o resultado em uma terceira matriz.

### **Código:**
```c
#include <stdio.h>

// Função que soma duas matrizes e armazena o resultado em uma terceira matriz
void soma_matrizes(int linhas, int colunas, int (*matriz1)[3], int (*matriz2)[3], int (*resultado)[3]) {
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            resultado[i][j] = matriz1[i][j] + matriz2[i][j];  // Soma elemento a elemento
        }
    }
}

int main() {
    int matriz1[2][3] = {{1, 2, 3}, {4, 5, 6}};
    int matriz2[2][3] = {{7, 8, 9}, {10, 11, 12}};
    int resultado[2][3];  // Matriz para armazenar a soma

    soma_matrizes(2, 3, matriz1, matriz2, resultado);

    // Imprime o resultado
    printf("Soma das matrizes:\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", resultado[i][j]);
        }
        printf("\n");
    }

    return 0;
}
```

### **Explicação:**
1. **Parâmetros da função:**
   - `int linhas` e `int colunas`: Dimensões da matriz.
   - `int (*matriz1)[3]` e `int (*matriz2)[3]`: Ponteiros para matrizes 2D (o número `3` é o tamanho da segunda dimensão).
   - `int (*resultado)[3]`: Ponteiro para a matriz de resultado.

2. **Processamento:**
   - Dois loops `for` aninhados percorrem as matrizes e somam os elementos.

3. **Saída:**
   ```
   Soma das matrizes:
   8 10 12
   14 16 18
   ```

---

## **3. Matriz de Alunos e Notas**


```c
#include <stdio.h>
#include <string.h>

// Função para imprimir o nome e as notas de um aluno
void imprimir_aluno(int indice, char nomes[][50], float notas[][3]) {
    printf("Nome: %s\n", nomes[indice]);
    printf("Notas: %.1f, %.1f, %.1f\n", notas[indice][0], notas[indice][1], notas[indice][2]);
}

int main() {
    char nomes[2][50];       // Matriz para nomes (2 alunos, 50 caracteres cada)
    float notas[2][3];       // Matriz para notas (2 alunos, 3 notas cada)

    // Preenche os dados do primeiro aluno
    strcpy(nomes[0], "João");
    notas[0][0] = 7.5;
    notas[0][1] = 8.0;
    notas[0][2] = 6.5;

    // Preenche os dados do segundo aluno
    strcpy(nomes[1], "Maria");
    notas[1][0] = 9.0;
    notas[1][1] = 8.5;
    notas[1][2] = 10.0;

    // Imprime os dados
    for (int i = 0; i < 2; i++) {
        imprimir_aluno(i, nomes, notas);
        printf("\n");
    }

    return 0;
}

**Explicação Detalhada do Código**

Gerencia dados de alunos usando **matrizes** (arrays bidimensionais) para armazenar nomes e notas separadamente.

---

**1. Estrutura Geral**
O código possui:
- Uma função `imprimir_aluno()` para exibir os dados.
- A função principal `main()` onde os dados são armazenados e processados.

---

**2. Declaração das Matrizes**
```c
char nomes[2][50];       // Armazena nomes de 2 alunos (cada nome com até 50 caracteres)
float notas[2][3];       // Armazena 3 notas para cada um dos 2 alunos
```
- **`nomes[2][50]`**: 
  - 2 linhas (1 para cada aluno).
  - 50 colunas (tamanho máximo do nome + terminador `\0`).
- **`notas[2][3]`**:
  - 2 linhas (1 para cada aluno).
  - 3 colunas (1 para cada nota).

---

**3. Preenchimento dos Dados**
**Primeiro Aluno (Índice 0)**
```c
strcpy(nomes[0], "João");         // Copia "João" para nomes[0]
notas[0][0] = 7.5;                // Primeira nota do João
notas[0][1] = 8.0;                // Segunda nota
notas[0][2] = 6.5;                // Terceira nota
```
**Segundo Aluno (Índice 1)**
```c
strcpy(nomes[1], "Maria");        // Copia "Maria" para nomes[1]
notas[1][0] = 9.0;                // Primeira nota da Maria
notas[1][1] = 8.5;                // Segunda nota
notas[1][2] = 10.0;               // Terceira nota
```

---

**4. Função `imprimir_aluno()`**
```c
void imprimir_aluno(int indice, char nomes[][50], float notas[][3]) {
    printf("Nome: %s\n", nomes[indice]);
    printf("Notas: %.1f, %.1f, %.1f\n", notas[indice][0], notas[indice][1], notas[indice][2]);
}
```
- **Parâmetros**:
  - `indice`: Posição do aluno nas matrizes (0 ou 1).
  - `nomes[][50]`: Matriz de nomes (tamanho flexível na primeira dimensão).
  - `notas[][3]`: Matriz de notas (sempre 3 notas por aluno).
- **Ação**:
  - Imprime o nome e as 3 notas do aluno no `indice` especificado.
---

**5. Loop de Impressão (em `main()`)**
```c
for (int i = 0; i < 2; i++) {
    imprimir_aluno(i, nomes, notas);  // Chama a função para cada aluno
    printf("\n");                     // Espaço entre alunos
}
```
- O loop percorre os índices `0` e `1`.
- Para cada iteração, chama `imprimir_aluno()` com o índice atual.

---

**6. Saída do Programa**
```
Nome: João
Notas: 7.5, 8.0, 6.5

Nome: Maria
Notas: 9.0, 8.5, 10.0
```

---

**7. Diagrama de Memória**
```
nomes[0]: "João\0____________________..."  // 50 caracteres no total
nomes[1]: "Maria\0___________________..."  

notas[0]: [7.5][8.0][6.5]                // 3 notas do João
notas[1]: [9.0][8.5][10.0]               // 3 notas da Maria
```
---

**8. Pontos-Chave**
1. **Matrizes vs. Structs**:
   - Aqui, usamos matrizes separadas para simular um "banco de dados" simples.
   - Em problemas reais, `structs` são mais organizadas (agrupam dados logicamente).

2. **Passagem de Matrizes para Funções**:
   - A primeira dimensão pode ser omitida (`nomes[][50]`).
   - A segunda dimensão deve ser especificada (`notas[][3]`).

3. **`strcpy()`**:
   - Necessário para copiar strings em C (não use `=`).

4. **Índices**:
   - `nomes[0]` e `notas[0]` referem-se ao João.
   - `nomes[1]` e `notas[1]` referem-se à Maria.

---

## **Exercício Proposto**
Modifique o programa para:
1. Adicionar um terceiro aluno.
2. Calcular a média das notas de cada aluno.
3. Armazenar as médias em um novo array `float medias[2]`.

**Dica:** Use um loop para calcular `medias[i] = (notas[i][0] + notas[i][1] + notas[i][2]) / 3`.
---

## **Conclusão**
1. **Vetores (1D):** Usamos ponteiros para percorrer e manipular arrays unidimensionais.
2. **Matrizes (2D):** Usamos ponteiros para arrays multidimensionais, especificando o tamanho das dimensões.

Esses exemplos são fundamentais para entender **ponteiros** e **arrays**
