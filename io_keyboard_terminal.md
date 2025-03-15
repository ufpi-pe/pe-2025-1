## **Entrada e Saída de Dados em C: `printf` e `scanf`**

### **Introdução**

Em C, a entrada e saída de dados são realizadas principalmente usando as funções `printf` (para saída) e `scanf` (para entrada). Essas funções são parte da biblioteca padrão `stdio.h`, que deve ser incluída no início do programa.

---

### **Saída de Dados com `printf`**

A função `printf` é usada para exibir dados na tela. Ela permite formatar a saída de acordo com o tipo de dado que está sendo exibido.

**Sintaxe:**
```c
printf("Texto de formatação", argumentos);
```

**Exemplo:**
```c
#include <stdio.h>

int main() {
    int idade = 25;
    float altura = 1.75;
    char nome[] = "João";

    printf("Nome: %s\n", nome);       // %s para strings
    printf("Idade: %d anos\n", idade); // %d para inteiros
    printf("Altura: %.2f metros\n", altura); // %.2f para floats com 2 casas decimais

    return 0;
}
```

**Saída:**
```
Nome: João
Idade: 25 anos
Altura: 1.75 metros
```

**Especificadores de Formato Comuns:**
- `%d`: Inteiro.
- `%f`: Float (ponto flutuante).
- `%c`: Caractere.
- `%s`: String (cadeia de caracteres).
- `%.2f`: Float com 2 casas decimais.

---

### **Entrada de Dados com `scanf`**

A função `scanf` é usada para capturar dados digitados pelo usuário. Ela permite ler valores e armazená-los em variáveis.

**Sintaxe:**
```c
scanf("Texto de formatação", &variavel);
```

**Exemplo:**
```c
#include <stdio.h>

int main() {
    int idade;
    float altura;
    char nome[50];

    printf("Digite seu nome: ");
    scanf("%s", nome); // Lê uma string (sem espaços)

    printf("Digite sua idade: ");
    scanf("%d", &idade); // Lê um inteiro

    printf("Digite sua altura: ");
    scanf("%f", &altura); // Lê um float

    printf("Nome: %s\n", nome);
    printf("Idade: %d anos\n", idade);
    printf("Altura: %.2f metros\n", altura);

    return 0;
}
```

**Exemplo de Execução:**
```
Digite seu nome: Maria
Digite sua idade: 30
Digite sua altura: 1.68
Nome: Maria
Idade: 30 anos
Altura: 1.68 metros
```

**Observações:**
1. **Uso de `&`:**  
   O operador `&` é usado para passar o endereço da variável onde o valor será armazenado. No caso de strings (arrays de caracteres), o `&` não é necessário, pois o nome do array já é um ponteiro.

2. **Leitura de Strings com Espaços:**  
   Para ler strings com espaços, use `fgets` em vez de `scanf`.

---

### **Exemplo Completo: Entrada e Saída de Dados**

Aqui está um exemplo completo que combina `printf` e `scanf` para capturar e exibir informações do usuário:

```c
#include <stdio.h>

int main() {
    char nome[50];
    int idade;
    float altura;

    // Entrada de dados
    printf("Digite seu nome: ");
    scanf("%s", nome);

    printf("Digite sua idade: ");
    scanf("%d", &idade);

    printf("Digite sua altura (em metros): ");
    scanf("%f", &altura);

    // Saída de dados
    printf("\nDados informados:\n");
    printf("Nome: %s\n", nome);
    printf("Idade: %d anos\n", idade);
    printf("Altura: %.2f metros\n", altura);

    return 0;
}
```

**Exemplo de Execução:**
```
Digite seu nome: Carlos
Digite sua idade: 28
Digite sua altura (em metros): 1.82

Dados informados:
Nome: Carlos
Idade: 28 anos
Altura: 1.82 metros
```

---

### **Leitura de Strings com Espaços**

O `scanf` não é ideal para ler strings com espaços, pois ele para de ler no primeiro espaço em branco. Para ler strings completas, use `fgets`.

**Exemplo:**
```c
#include <stdio.h>

int main() {
    char nome[50];

    printf("Digite seu nome completo: ");
    fgets(nome, 50, stdin); // Lê uma string com espaços

    printf("Nome completo: %s", nome);

    return 0;
}
```

**Exemplo de Execução:**
```
Digite seu nome completo: Carlos Silva
Nome completo: Carlos Silva
```

---

### **Conversão de Tipos**

A função `scanf` já faz a conversão de tipos automaticamente com base no especificador de formato (`%d`, `%f`, etc.). No entanto, você pode converter explicitamente usando **casting**.

**Exemplo:**
```c
#include <stdio.h>

int main() {
    float numero;
    printf("Digite um número decimal: ");
    scanf("%f", &numero);

    int inteiro = (int)numero; // Converte float para int
    printf("Parte inteira: %d\n", inteiro);

    return 0;
}
```

**Exemplo de Execução:**
```
Digite um número decimal: 3.14
Parte inteira: 3
```

---

### **Resumo**

- **`printf`:** Usado para exibir dados na tela. Permite formatação com especificadores como `%d`, `%f`, `%s`, etc.
- **`scanf`:** Usado para capturar dados do usuário. Requer o uso de `&` para passar o endereço da variável (exceto para strings).
- **Leitura de Strings com Espaços:** Use `fgets` em vez de `scanf`.
- **Conversão de Tipos:** Use casting para converter explicitamente entre tipos.

---

### **Exemplo Prático: Calculadora Simples**

Aqui está um exemplo prático que usa `printf` e `scanf` para criar uma calculadora simples:

```c
#include <stdio.h>

int main() {
    float num1, num2;
    char operacao;

    printf("Digite o primeiro número: ");
    scanf("%f", &num1);

    printf("Digite a operação (+, -, *, /): ");
    scanf(" %c", &operacao); // Espaço antes de %c para evitar problemas com o buffer

    printf("Digite o segundo número: ");
    scanf("%f", &num2);

    float resultado;
    switch (operacao) {
        case '+':
            resultado = num1 + num2;
            break;
        case '-':
            resultado = num1 - num2;
            break;
        case '*':
            resultado = num1 * num2;
            break;
        case '/':
            if (num2 != 0) {
                resultado = num1 / num2;
            } else {
                printf("Erro: Divisão por zero!\n");
                return 1;
            }
            break;
        default:
            printf("Operação inválida!\n");
            return 1;
    }

    printf("Resultado: %.2f\n", resultado);

    return 0;
}
```

**Exemplo de Execução:**
```
Digite o primeiro número: 10
Digite a operação (+, -, *, /): *
Digite o segundo número: 5
Resultado: 50.00
```

---
