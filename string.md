## **Strings em C: Definição e Manipulação**

### **O que são Strings?**

Em C, uma **string** é uma sequência de caracteres armazenada em um array de `char`, terminada pelo caractere especial `\0` (null character). Esse caractere marca o fim da string e é essencial para que as funções de manipulação de strings saibam onde a string termina.

**Exemplo de String:**
```c
char nome[] = "João";
```
Aqui, `nome` é um array de caracteres que contém `'J'`, `'o'`, `'ã'`, `'o'` e `'\0'`.

---

### **Declaração e Inicialização de Strings**

**1. Declaração com Tamanho Fixo:**
```c
char nome[50]; // Array de 50 caracteres
```

**2. Inicialização Direta:**
```c
char nome[] = "João"; // Tamanho inferido automaticamente
```

**3. Inicialização Caractere por Caractere:**
```c
char nome[] = {'J', 'o', 'ã', 'o', '\0'};
```

---

### **Entrada e Saída de Strings**

#### **Saída de Strings com `printf`**
Use o especificador `%s` para exibir strings.

**Exemplo:**
```c
#include <stdio.h>

int main() {
    char nome[] = "Maria";
    printf("Nome: %s\n", nome); // Saída: Nome: Maria
    return 0;
}
```

#### **Entrada de Strings com `scanf`**
O `scanf` pode ler strings, mas para de ler no primeiro espaço em branco.

**Exemplo:**
```c
#include <stdio.h>

int main() {
    char nome[50];
    printf("Digite seu nome: ");
    scanf("%s", nome); // Lê até o primeiro espaço
    printf("Nome: %s\n", nome);
    return 0;
}
```

**Problema:** Se o usuário digitar `"Maria Silva"`, apenas `"Maria"` será armazenado.

#### **Entrada de Strings com `fgets`**
Para ler strings com espaços, use `fgets`.

**Exemplo:**
```c
#include <stdio.h>

int main() {
    char nome[50];
    printf("Digite seu nome completo: ");
    fgets(nome, 50, stdin); // Lê a string com espaços
    printf("Nome completo: %s", nome);
    return 0;
}
```

**Observação:** `fgets` inclui o caractere de nova linha (`\n`) se o usuário pressionar Enter. Para removê-lo:
```c
nome[strcspn(nome, "\n")] = '\0';
```

---

### **Funções de Manipulação de Strings**

A biblioteca `string.h` fornece várias funções úteis para manipular strings. Para usá-las, inclua `#include <string.h>` no início do programa.

#### **1. `strlen`: Tamanho da String**
Retorna o número de caracteres na string (sem contar o `\0`).

**Exemplo:**
```c
#include <stdio.h>
#include <string.h>

int main() {
    char nome[] = "João";
    printf("Tamanho: %zu\n", strlen(nome)); // Saída: 4
    return 0;
}
```

#### **2. `strcpy`: Copiar Strings**
Copia o conteúdo de uma string para outra.

**Exemplo:**
```c
#include <stdio.h>
#include <string.h>

int main() {
    char origem[] = "Olá, mundo!";
    char destino[50];
    strcpy(destino, origem); // Copia "Olá, mundo!" para destino
    printf("Destino: %s\n", destino);
    return 0;
}
```

#### **3. `strcat`: Concatenar Strings**
Concatena (junta) duas strings.

**Exemplo:**
```c
#include <stdio.h>
#include <string.h>

int main() {
    char str1[50] = "Olá, ";
    char str2[] = "mundo!";
    strcat(str1, str2); // Concatena str2 em str1
    printf("Resultado: %s\n", str1); // Saída: Olá, mundo!
    return 0;
}
```

#### **4. `strcmp`: Comparar Strings**
Compara duas strings. Retorna:
- `0` se forem iguais.
- Um valor negativo se a primeira for menor que a segunda.
- Um valor positivo se a primeira for maior que a segunda.

**Exemplo:**
```c
#include <stdio.h>
#include <string.h>

int main() {
    char str1[] = "abc";
    char str2[] = "abd";
    int resultado = strcmp(str1, str2);
    printf("Resultado: %d\n", resultado); // Saída: -1 (abc < abd)
    return 0;
}
```

#### **5. `strchr`: Localizar Caractere**
Retorna um ponteiro para a primeira ocorrência de um caractere na string.

**Exemplo:**
```c
#include <stdio.h>
#include <string.h>

int main() {
    char str[] = "Olá, mundo!";
    char *ptr = strchr(str, 'm'); // Procura 'm' na string
    if (ptr != NULL) {
        printf("Encontrado: %s\n", ptr); // Saída: mundo!
    } else {
        printf("Caractere não encontrado.\n");
    }
    return 0;
}
```

#### **6. `strstr`: Localizar Substring**
Retorna um ponteiro para a primeira ocorrência de uma substring na string.

**Exemplo:**
```c
#include <stdio.h>
#include <string.h>

int main() {
    char str[] = "Olá, mundo!";
    char *ptr = strstr(str, "mundo"); // Procura "mundo" na string
    if (ptr != NULL) {
        printf("Encontrado: %s\n", ptr); // Saída: mundo!
    } else {
        printf("Substring não encontrada.\n");
    }
    return 0;
}
```

---

### **Exemplo Completo: Manipulação de Strings**

Aqui está um exemplo que combina várias operações com strings:

```c
#include <stdio.h>
#include <string.h>

int main() {
    char nome[50];
    char sobrenome[50];
    char nomeCompleto[100];

    // Entrada de dados
    printf("Digite seu nome: ");
    fgets(nome, 50, stdin);
    nome[strcspn(nome, "\n")] = '\0'; // Remove o \n do fgets

    printf("Digite seu sobrenome: ");
    fgets(sobrenome, 50, stdin);
    sobrenome[strcspn(sobrenome, "\n")] = '\0'; // Remove o \n do fgets

    // Concatenação
    strcpy(nomeCompleto, nome);
    strcat(nomeCompleto, " ");
    strcat(nomeCompleto, sobrenome);

    // Saída de dados
    printf("Nome completo: %s\n", nomeCompleto);
    printf("Tamanho do nome completo: %zu\n", strlen(nomeCompleto));

    // Comparação
    if (strcmp(nome, sobrenome) == 0) {
        printf("Nome e sobrenome são iguais.\n");
    } else {
        printf("Nome e sobrenome são diferentes.\n");
    }

    return 0;
}
```

**Exemplo de Execução:**
```
Digite seu nome: Carlos
Digite seu sobrenome: Silva
Nome completo: Carlos Silva
Tamanho do nome completo: 12
Nome e sobrenome são diferentes.
```

---

### **Resumo**

- **Strings** em C são arrays de caracteres terminados por `\0`.
- Use `printf` e `scanf` para saída e entrada básica de strings.
- Para ler strings com espaços, use `fgets`.
- A biblioteca `string.h` fornece funções úteis como `strlen`, `strcpy`, `strcat`, `strcmp`, `strchr` e `strstr`.

---
