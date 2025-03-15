## **Variáveis, Tipos e Operações em C**

### **Variáveis em C**
**Conceito:**  
Uma variável em C é um espaço na memória do computador reservado para armazenar um valor. Cada variável tem um tipo específico que define o tipo de dado que ela pode armazenar.

**Declaração:**  
Em C, você **precisa declarar explicitamente o tipo** de uma variável antes de usá-la. A declaração inclui o tipo da variável e seu nome.

**Atribuição:**  
Utiliza-se o sinal de igual (`=`) para atribuir um valor a uma variável.

**Exemplo:**
```c
int idade = 30;
```

**Atribuindo valores a variáveis:**
```c
char nome[] = "João"; // String em C é um array de caracteres
int idade = 30;
float altura = 1.75;
```

---

### **Tipos de Dados em C**
C possui tipos de dados básicos (primitivos) e derivados. Os mais comuns são:

#### **Tipos Primitivos:**
1. **Números:**
   - `int`: Números inteiros (ex: `42`, `-10`).
   - `float`: Números de ponto flutuante (ex: `3.14`, `-2.5`).
   - `double`: Números de ponto flutuante com maior precisão (ex: `3.1415926535`).
   - `char`: Caracteres (ex: `'A'`, `'b'`).

2. **Booleanos:**  
   Em C, não existe um tipo `bool` nativo (em versões antigas). Usamos `int` com valores `0` (falso) e `1` (verdadeiro).  
   Exemplo:
   ```c
   int ehVerdadeiro = 1; // Verdadeiro
   int ehFalso = 0;      // Falso
   ```

3. **Void:**  
   O tipo `void` é usado para indicar a ausência de tipo, comum em funções que não retornam valor.

#### **Tipos Derivados:**
1. **Arrays:**  
   Coleções de elementos do mesmo tipo (ex: `int numeros[5] = {1, 2, 3, 4, 5};`).

2. **Strings:**  
   Em C, strings são arrays de caracteres terminados com `\0` (ex: `char nome[] = "João";`).

3. **Ponteiros:**  
   Variáveis que armazenam endereços de memória (ex: `int *ptr;`).

4. **Estruturas (`struct`):**  
   Coleções de variáveis de tipos diferentes agrupadas sob um único nome.

---

### **Operações em C**

#### **Operadores Aritméticos:**
- `+`: Adição
- `-`: Subtração
- `*`: Multiplicação
- `/`: Divisão
- `%`: Resto da divisão (apenas para inteiros)

**Exemplo:**
```c
int soma = 10 + 5;       // 15
int subtracao = 20 - 3;  // 17
int multiplicacao = 4 * 2; // 8
float divisao = 10 / 2;  // 5.0
```

#### **Operadores de Comparação:**
- `==`: Igual a
- `!=`: Diferente de
- `<`: Menor que
- `>`: Maior que
- `<=`: Menor ou igual a
- `>=`: Maior ou igual a

**Exemplo:**
```c
int a = 5, b = 10;
if (a < b) {
    printf("a é menor que b\n");
}
```

#### **Operadores Lógicos:**
- `&&`: E lógico
- `||`: Ou lógico
- `!`: Negação

**Exemplo:**
```c
int x = 1, y = 0;
if (x && !y) {
    printf("x é verdadeiro e y é falso\n");
}
```

#### **Operadores de Atribuição:**
- `=`: Atribuição simples
- `+=`: Acrescenta e atribui
- `-=`: Subtrai e atribui
- `*=`: Multiplica e atribui
- `/=`: Divide e atribui
- `%=`: Resto da divisão e atribui

**Exemplo:**
```c
int num = 10;
num += 5; // num = num + 5 → 15
```

---

### **Entrada e Saída de Dados em C**

#### **Entrada de Dados:**
Em C, a função `scanf()` é usada para capturar dados do usuário.

**Sintaxe:**
```c
scanf("%tipo", &variavel);
```

**Exemplo:**
```c
int idade;
printf("Digite sua idade: ");
scanf("%d", &idade); // Captura um inteiro
```

#### **Saída de Dados:**
A função `printf()` é usada para exibir dados na tela.

**Sintaxe:**
```c
printf("Mensagem com %tipo", variavel);
```

**Exemplo:**
```c
printf("Olá, %s! Você tem %d anos e %.2f de altura.\n", nome, idade, altura);
```

#### **Conversão de Tipos:**
Em C, a função `scanf()` já faz a conversão de tipos automaticamente com base no especificador de formato (`%d`, `%f`, etc.). No entanto, você pode converter explicitamente usando **casting**.

**Exemplo:**
```c
float numero = 3.14;
int inteiro = (int)numero; // Converte float para int
```

---

### **Exemplo Completo em C**

```c
#include <stdio.h>

int main() {
    // Declaração de variáveis
    char nome[50];
    int idade;
    float altura;

    // Entrada de dados
    printf("Digite seu nome: ");
    scanf("%s", nome); // Captura uma string (sem espaços)

    printf("Digite sua idade: ");
    scanf("%d", &idade);

    printf("Digite sua altura: ");
    scanf("%f", &altura);

    // Saída de dados
    printf("Olá, %s! Você tem %d anos e %.2f de altura.\n", nome, idade, altura);

    // Operações
    int soma = idade + 10;
    printf("Daqui a 10 anos, você terá %d anos.\n", soma);

    return 0;
}
```

---

### **Observações:**
1. **Tipagem Estática:**  
   Em C, o tipo de uma variável é fixo e deve ser declarado explicitamente.

2. **Conversão de Tipos:**  
   Use `(tipo)` para fazer conversões explícitas (casting).

3. **Strings:**  
   Em C, strings são arrays de caracteres terminados com `\0`. Use `scanf("%s", nome)` para capturar strings sem espaços e `fgets(nome, 50, stdin)` para capturar strings com espaços.

4. **Precisão:**  
   Para números de ponto flutuante, use `%.2f` para exibir duas casas decimais.

---
