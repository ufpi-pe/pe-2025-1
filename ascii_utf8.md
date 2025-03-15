## **Tabela ASCII e Formatação UTF-8 em C**

### **O que é a Tabela ASCII?**

A **Tabela ASCII** (American Standard Code for Information Interchange) é um padrão que define a representação numérica de caracteres, como letras, números, símbolos e caracteres de controle. Cada caractere é associado a um número entre 0 e 127.

**Características:**
- **Caracteres de 0 a 31:** Caracteres de controle (não imprimíveis).
- **Caracteres de 32 a 126:** Caracteres imprimíveis (letras, números, símbolos).
- **Caractere 127:** Delete (não imprimível).

**Exemplos:**
- `65` → `'A'`
- `97` → `'a'`
- `48` → `'0'`
- `32` → `' '` (espaço)

---

### **Usando a Tabela ASCII em C**

Em C, você pode usar valores ASCII diretamente para manipular caracteres.

#### **Exemplo 1: Exibindo Caracteres a Partir de Valores ASCII**
```c
#include <stdio.h>

int main() {
    printf("ASCII 65: %c\n", 65); // Saída: A
    printf("ASCII 97: %c\n", 97); // Saída: a
    printf("ASCII 48: %c\n", 48); // Saída: 0
    return 0;
}
```

#### **Exemplo 2: Convertendo Caracteres para Valores ASCII**
```c
#include <stdio.h>

int main() {
    char letra = 'B';
    printf("Valor ASCII de 'B': %d\n", letra); // Saída: 66
    return 0;
}
```

#### **Exemplo 3: Usando Valores ASCII em Operações**
```c
#include <stdio.h>

int main() {
    char letra = 'A';
    letra = letra + 1; // Incrementa o valor ASCII
    printf("Nova letra: %c\n", letra); // Saída: B
    return 0;
}
```

---

### **O que é UTF-8?**

**UTF-8** (Unicode Transformation Format 8-bit) é um padrão de codificação de caracteres que permite representar todos os caracteres Unicode usando de 1 a 4 bytes. Ele é compatível com ASCII, ou seja, os primeiros 128 caracteres Unicode são idênticos aos da tabela ASCII.

**Características:**
- **Compatível com ASCII:** Os primeiros 128 caracteres usam 1 byte.
- **Suporte a Caracteres Especiais:** Permite representar caracteres de diferentes idiomas, emojis, etc.
- **Eficiente:** Usa de 1 a 4 bytes por caractere, dependendo do símbolo.

---

### **Usando UTF-8 em C**

Em C, você pode trabalhar com UTF-8 usando strings normais, mas é importante garantir que o ambiente de execução (terminal, editor de texto, etc.) suporte UTF-8.

#### **Exemplo 1: Exibindo Caracteres UTF-8**
```c
#include <stdio.h>

int main() {
    printf("Caractere UTF-8: ☺\n"); // Emoji de sorriso
    printf("Caractere UTF-8: é\n"); // Letra com acento
    return 0;
}
```

#### **Exemplo 2: Manipulando Strings UTF-8**
UTF-8 pode usar mais de 1 byte por caractere. Para manipular strings UTF-8, você pode usar bibliotecas como `wchar.h` ou `uchar.h`.

**Exemplo com `wchar.h`:**
```c
#include <stdio.h>
#include <wchar.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, ""); // Configura o locale para suportar UTF-8

    wchar_t str[] = L"Olá, mundo! ☺";
    wprintf(L"%ls\n", str); // Exibe a string UTF-8

    return 0;
}
```

**Explicação:**
- `wchar_t` é um tipo de caractere largo que suporta Unicode.
- `setlocale(LC_ALL, "")` configura o ambiente para suportar UTF-8.
- `wprintf` é usado para exibir strings de caracteres largos.

---

### **Diferenças entre ASCII e UTF-8**

| Característica       | ASCII                     | UTF-8                          |
|----------------------|---------------------------|--------------------------------|
| **Tamanho**          | 1 byte por caractere      | 1 a 4 bytes por caractere      |
| **Caracteres**       | 128 caracteres            | Mais de 1 milhão de caracteres |
| **Compatibilidade**  | Limitada a inglês básico  | Suporta todos os idiomas       |
| **Uso em C**         | `char`                    | `char` ou `wchar_t`            |

---

### **Exemplo Completo: Trabalhando com ASCII e UTF-8**

Aqui está um exemplo que combina o uso de ASCII e UTF-8:

```c
#include <stdio.h>
#include <wchar.h>
#include <locale.h>

int main() {
    // Configura o locale para suportar UTF-8
    setlocale(LC_ALL, "");

    // Exemplo com ASCII
    printf("ASCII 65: %c\n", 65); // Saída: A
    printf("ASCII 97: %c\n", 97); // Saída: a

    // Exemplo com UTF-8
    wchar_t str[] = L"Olá, mundo! ☺";
    wprintf(L"String UTF-8: %ls\n", str); // Saída: Olá, mundo! ☺

    // Exibindo valores Unicode
    wchar_t letra = L'é';
    wprintf(L"Valor Unicode de 'é': %d\n", letra); // Saída: 233

    return 0;
}
```

**Saída:**
```
ASCII 65: A
ASCII 97: a
String UTF-8: Olá, mundo! ☺
Valor Unicode de 'é': 233
```

---

### **Resumo**

- **Tabela ASCII:** Representa caracteres básicos usando valores de 0 a 127.
- **UTF-8:** Permite representar todos os caracteres Unicode, usando de 1 a 4 bytes por caractere.
- Em C, você pode usar `char` para ASCII e `wchar_t` para UTF-8.
- Use `setlocale(LC_ALL, "")` e funções como `wprintf` para trabalhar com UTF-8.

---

### **Exercícios Práticos**

1. **Conversão de ASCII para Caractere:**
   Escreva um programa que solicite ao usuário um valor ASCII e exiba o caractere correspondente.

2. **Exibição de Emojis:**
   Use UTF-8 para exibir uma lista de emojis no terminal.

3. **Manipulação de Strings UTF-8:**
   Crie um programa que leia uma string UTF-8 do usuário e conte o número de caracteres (não bytes).

---
