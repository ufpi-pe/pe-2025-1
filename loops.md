## **Estruturas de Seleção e Repetição em C**

### **Estruturas de Seleção (if)**

As estruturas de seleção em C, principalmente o comando `if`, permitem que seu programa tome decisões com base em condições. Elas avaliam uma expressão booleana e executam um bloco de código se a condição for verdadeira.

**Sintaxe básica:**
```c
if (condição) {
    // Código a ser executado se a condição for verdadeira
} else {
    // Código a ser executado se a condição for falsa
}
```

**Exemplo:**
```c
int idade = 18;
if (idade >= 18) {
    printf("Você é maior de idade.\n");
} else {
    printf("Você é menor de idade.\n");
}
```

**Características:**
1. **Condição:**  
   Deve ser uma expressão que resulte em um valor booleano (`1` para verdadeiro, `0` para falso).

2. **Blocos de código:**  
   Delimitados por chaves `{}`.

3. **else if:**  
   Pode ser usado para adicionar mais condições.

4. **else:**  
   Executado se nenhuma das condições anteriores for verdadeira.

**Exemplo com `else if`:**
```c
int nota = 85;
if (nota >= 90) {
    printf("Aprovado com A.\n");
} else if (nota >= 80) {
    printf("Aprovado com B.\n");
} else if (nota >= 70) {
    printf("Aprovado com C.\n");
} else {
    printf("Reprovado.\n");
}
```

---

### **Estruturas de Repetição (Loops)**

As estruturas de repetição permitem que um bloco de código seja executado repetidamente enquanto uma determinada condição for verdadeira.

#### **1. for**

Utilizado para iterar sobre uma sequência de valores (números, arrays, etc.).

**Sintaxe:**
```c
for (inicialização; condição; incremento) {
    // Código a ser executado em cada iteração
}
```

**Exemplo:**
```c
for (int i = 0; i < 5; i++) {
    printf("%d\n", i);
}
```

**Exemplo com array:**
```c
int numeros[] = {10, 20, 30, 40, 50};
for (int i = 0; i < 5; i++) {
    printf("%d\n", numeros[i]);
}
```

#### **2. while**

Continua a executar um bloco de código enquanto uma condição for verdadeira.

**Sintaxe:**
```c
while (condição) {
    // Código a ser executado enquanto a condição for verdadeira
}
```

**Exemplo:**
```c
int contador = 0;
while (contador < 5) {
    printf("%d\n", contador);
    contador++;
}
```

**Características:**
1. **Condição:**  
   Deve ser uma expressão que resulte em um valor booleano (`1` para verdadeiro, `0` para falso).

2. **Iteração:**  
   O loop continua até que a condição se torne falsa.

3. **break:**  
   Interrompe o loop imediatamente.

4. **continue:**  
   Pula para a próxima iteração do loop.

**Exemplo com `break` e `continue`:**
```c
int i = 0;
while (i < 10) {
    i++;
    if (i == 5) {
        continue; // Pula a iteração quando i == 5
    }
    if (i == 8) {
        break; // Interrompe o loop quando i == 8
    }
    printf("%d\n", i);
}
```

---

### **Exemplo Completo em C**

Aqui está um exemplo que combina estruturas de seleção e repetição para somar os números pares de um array:

```c
#include <stdio.h>

int main() {
    int numeros[] = {1, 2, 3, 4, 5};
    int soma = 0;

    for (int i = 0; i < 5; i++) {
        if (numeros[i] % 2 == 0) {
            soma += numeros[i];
        }
    }

    printf("A soma dos números pares é: %d\n", soma);

    return 0;
}
```

**Explicação:**
1. O array `numeros` contém os valores `{1, 2, 3, 4, 5}`.
2. O loop `for` percorre cada elemento do array.
3. A estrutura `if` verifica se o número é par (`numeros[i] % 2 == 0`).
4. Se for par, o número é adicionado à variável `soma`.
5. No final, o programa imprime a soma dos números pares.

---
