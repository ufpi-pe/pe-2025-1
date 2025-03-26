## **Funções em C: Blocos Reutilizáveis de Código**

### **O que são Funções em C?**

Em C, funções são blocos de código reutilizáveis que realizam uma tarefa específica. Elas permitem organizar o código, torná-lo mais legível e evitar a repetição de código.

**Por que usar funções?**
1. **Reutilização:** Uma vez definida, uma função pode ser chamada várias vezes em diferentes partes do seu programa.
2. **Modularidade:** Dividir o código em funções menores torna o programa mais fácil de entender e manter.
3. **Abstração:** As funções podem ocultar a complexidade interna, permitindo que você se concentre na lógica geral do programa.

---

### **Como Definir uma Função em C**

Para definir uma função em C, você precisa especificar:
1. O **tipo de retorno** da função (ou `void` se não retornar nada).
2. O **nome** da função.
3. Os **parâmetros** (se houver), entre parênteses.
4. O **corpo** da função, delimitado por chaves `{}`.

**Sintaxe:**
```c
tipo_retorno nome_funcao(tipo_parametro1 param1, tipo_parametro2 param2) {
    // Código da função
    return valor; // Opcional, dependendo do tipo de retorno
}
```

**Exemplo:**
```c
#include <stdio.h>

// Função que imprime uma saudação
void saudacao(char nome[]) {
    printf("Olá, %s!\n", nome);
}

int main() {
    saudacao("Maria"); // Chamada da função
    return 0;
}
```

---

### **Parâmetros e Argumentos**

- **Parâmetros:** São as variáveis declaradas na definição da função.
- **Argumentos:** São os valores passados para a função quando ela é chamada.

**Exemplo:**
```c
#include <stdio.h>

// Função que soma dois números
int soma(int a, int b) {
    return a + b;
}

int main() {
    int resultado = soma(3, 5); // Argumentos: 3 e 5
    printf("Resultado: %d\n", resultado); // Saída: 8
    return 0;
}
```

---

### **Retorno de Valores**

Uma função pode retornar um valor usando a palavra-chave `return`.

**Exemplo:**
```c
#include <stdio.h>

// Função que calcula o quadrado de um número
int quadrado(int x) {
    return x * x;
}

int main() {
    int resultado = quadrado(4); // Chamada da função
    printf("Quadrado: %d\n", resultado); // Saída: 16
    return 0;
}
```

---

### **Tipos de Argumentos**

1. **Argumentos Posicionais:** A ordem dos argumentos importa.
2. **Argumentos Nomeados:** Não existe em C. Em C, os argumentos são sempre posicionais.
3. **Argumentos com Valores Padrão:** Não existe em C. Todos os argumentos devem ser passados explicitamente.

---

### **Funções Recursivas em C**

Uma função recursiva é aquela que, durante sua execução, chama a si mesma. Essa técnica é útil para resolver problemas que podem ser divididos em subproblemas menores e idênticos ao problema original.

**Exemplo: Fatorial**
```c
#include <stdio.h>

// Função recursiva para calcular o fatorial
int fatorial(int n) {
    if (n == 0) { // Caso base
        return 1;
    } else { // Caso recursivo
        return n * fatorial(n - 1);
    }
}

int main() {
    int resultado = fatorial(5); // Chamada da função
    printf("Fatorial: %d\n", resultado); // Saída: 120
    return 0;
}
```

**Explicação:**
- **Caso base:** Se `n` for 0, o fatorial é 1.
- **Caso recursivo:** Se `n` for diferente de 0, o fatorial de `n` é `n * fatorial(n - 1)`.
  
**Fatorial de um número usando loop (for)**

```c
#include <stdio.h>

// Função iterativa para calcular o fatorial usando loop
int fatorial(int n) {
    int resultado = 1; // Inicializa o resultado com 1 (fatorial de 0 e 1 é 1)
    
    // Loop que multiplica os números de 1 até n
    for (int i = 1; i <= n; i++) {
        resultado *= i; // Equivalente a: resultado = resultado * i
    }
    
    return resultado;
}

int main() {
    int numero = 5;
    int resultado = fatorial(numero); // Chamada da função
    printf("Fatorial de %d: %d\n", numero, resultado); // Saída: 120
    return 0;
}
```

---

### **Escopo de Variáveis em C: Local e Global**

O escopo de uma variável define onde ela pode ser acessada dentro de um programa.

1. **Variáveis Locais:**
   - Onde são definidas: Dentro de uma função.
   - Visibilidade: Somente dentro da função onde foram definidas.

**Exemplo:**
```c
#include <stdio.h>

void minha_funcao() {
    int x = 10; // Variável local
    printf("Dentro da função: %d\n", x);
}

int main() {
    minha_funcao(); // Saída: 10
    // printf("%d\n", x); // Erro: x não está definida fora da função
    return 0;
}
```

2. **Variáveis Globais:**
   - Onde são definidas: Fora de qualquer função.
   - Visibilidade: Podem ser acessadas de qualquer lugar do programa.

**Exemplo:**
```c
#include <stdio.h>

int x = 20; // Variável global

void minha_funcao() {
    printf("Dentro da função: %d\n", x); // Saída: 20
}

int main() {
    minha_funcao();
    printf("Fora da função: %d\n", x); // Saída: 20
    return 0;
}
```

---

### **Passagem de Argumentos por Valor e por Referência**

1. **Passagem por Valor:**
   - Uma cópia do valor é passada para a função.
   - Modificações na cópia não afetam o valor original.

**Exemplo:**
```c
#include <stdio.h>

void dobrar_numero(int x) {
    x = x * 2;
    printf("Dentro da função: %d\n", x); // Saída: 10
}

int main() {
    int numero = 5;
    dobrar_numero(numero);
    printf("Fora da função: %d\n", numero); // Saída: 5
    return 0;
}
```

2. **Passagem por Referência:**
   - O endereço de memória da variável é passado para a função.
   - Modificações afetam o valor original.

Em **C**, um **ponteiro** é uma variável que armazena o **endereço de memória** de outra variável. Ele "aponta" para a localização onde um valor está guardado na memória RAM do computador, permitindo acesso e modificação indireta desse dado. Ponteiros são usados para manipular estruturas complexas (como arrays e strings), passar argumentos por referência (modificando o valor original) e alocar memória dinamicamente (com `malloc` e `free`).  

**Exemplo simples:**  
```c
#include <stdio.h>

int main(){
    int x = 10;
    int *ptr = &x; // ptr armazena o endereço de x
    printf("%p", ptr); // Imprime o endereco da celula que guarda o valor 10
    printf("\n");
    printf("%d", *ptr); // Imprime 10 (valor no endereço apontado)
    return 0;
}
```  

Em resumo, ponteiros são ferramentas poderosas que dão controle direto sobre a memória, mas exigem cuidado para evitar erros como acesso inválido ou vazamentos.
   

**Exemplo:**
```c
#include <stdio.h>

void adicionar_elemento(int *minha_lista, int tamanho) {
    minha_lista[tamanho - 1] = 4; // Modifica o array original
}

int main() {
    int minha_lista[] = {1, 2, 3};
    adicionar_elemento(minha_lista, 3);
    printf("Lista modificada: %d, %d, %d\n", minha_lista[0], minha_lista[1], minha_lista[2]); // Saída: 1, 2, 4
    return 0;
}
```

---

## **Funções Matemáticas e a Biblioteca math.h em C**

**Introdução à Biblioteca math.h**

A linguagem C oferece uma biblioteca padrão chamada **math.h**, que contém uma variedade de funções matemáticas prontas para uso. Essa biblioteca é útil para realizar operações matemáticas avançadas, como cálculos trigonométricos, exponenciais, logarítmicos, arredondamentos e muito mais.

Para utilizar essas funções, é necessário incluir a biblioteca no início do código:
```c
#include <math.h>
```
Além disso, ao compilar programas que usam `math.h`, pode ser necessário linkar a biblioteca matemática com a flag `-lm`:
```sh
gcc meu_programa.c -o meu_programa -lm
```

---

## **Principais Funções da math.h**
Aqui estão algumas das funções mais utilizadas da biblioteca `math.h`:

### **1. Funções Trigonométricas**
- `sin(x)` → Retorna o seno de um ângulo em radianos.
- `cos(x)` → Retorna o cosseno de um ângulo em radianos.
- `tan(x)` → Retorna a tangente de um ângulo em radianos.
- `asin(x)` → Retorna o arco-seno (inverso do seno) em radianos.
- `acos(x)` → Retorna o arco-cosseno (inverso do cosseno) em radianos.
- `atan(x)` → Retorna o arco-tangente (inverso da tangente) em radianos.

**Exemplo:**
```c
#include <stdio.h>
#include <math.h>

int main() {
    double angulo = 45.0;
    double radianos = angulo * (M_PI / 180.0); // Converte graus para radianos
    printf("Seno de %.2f graus: %.2f\n", angulo, sin(radianos));
    return 0;
}
```

### **2. Funções Exponenciais e Logarítmicas**
- `exp(x)` → Retorna o valor de **e^x** (exponencial).
- `log(x)` → Retorna o logaritmo natural (base *e*) de `x`.
- `log10(x)` → Retorna o logaritmo na base 10 de `x`.
- `pow(x, y)` → Retorna **x^y** (x elevado a y).

**Exemplo:**
```c
#include <stdio.h>
#include <math.h>

int main() {
    double base = 2.0, expoente = 3.0;
    printf("%.2f elevado a %.2f = %.2f\n", base, expoente, pow(base, expoente));
    return 0;
}
```

### **3. Funções de Arredondamento e Valor Absoluto**
- `ceil(x)` → Arredonda para cima (retorna o menor inteiro maior ou igual a `x`).
- `floor(x)` → Arredonda para baixo (retorna o maior inteiro menor ou igual a `x`).
- `fabs(x)` → Retorna o valor absoluto (módulo) de `x` (para números reais).
- `abs(x)` → Retorna o valor absoluto de um inteiro (da biblioteca `stdlib.h`).

**Exemplo:**
```c
#include <stdio.h>
#include <math.h>

int main() {
    double num = 3.7;
    printf("Arredondando %.2f para cima: %.2f\n", num, ceil(num));
    printf("Arredondando %.2f para baixo: %.2f\n", num, floor(num));
    printf("Valor absoluto de -%.2f: %.2f\n", num, fabs(-num));
    return 0;
}
```

### **4. Raiz Quadrada e Outras Funções**
- `sqrt(x)` → Retorna a raiz quadrada de `x`.
- `hypot(x, y)` → Retorna a hipotenusa de um triângulo retângulo com catetos `x` e `y` (equivalente a `sqrt(x² + y²)`).

**Exemplo:**
```c
#include <stdio.h>
#include <math.h>

int main() {
    double numero = 25.0;
    printf("Raiz quadrada de %.2f: %.2f\n", numero, sqrt(numero));
    printf("Hipotenusa de catetos 3 e 4: %.2f\n", hypot(3, 4)); // Saída: 5.00
    return 0;
}
```

---

## **Considerações Importantes**
- **Tipo de dados:** A maioria das funções em `math.h` trabalha com `double`. Se você passar um `int` ou `float`, o compilador fará a conversão automaticamente, mas é recomendado usar `double` para maior precisão.
- **Erros matemáticos:** Algumas funções (como `sqrt` ou `log`) podem gerar erros se receberem valores inválidos (ex: raiz de número negativo). Nesses casos, a função pode retornar um valor especial como `NaN` (Not a Number) ou `INF` (infinito).
- **Constantes matemáticas:** A biblioteca também define constantes úteis, como:
  - `M_PI` → Valor de π (pi).
  - `M_E` → Valor de *e* (base do logaritmo natural).

---

### **Exemplo : Calculando a Hipotenusa**
```c
#include <stdio.h>
#include <math.h>

int main() {
    double cateto1, cateto2, hipotenusa;
    
    printf("Digite o valor do primeiro cateto: ");
    scanf("%lf", &cateto1);
    
    printf("Digite o valor do segundo cateto: ");
    scanf("%lf", &cateto2);
    
    hipotenusa = hypot(cateto1, cateto2);
    printf("A hipotenusa é: %.2f\n", hipotenusa);
    
    return 0;
}
```

## Programa Calculadora Simples (sem usar funções)

```c
#include <stdio.h>

int main() {
    float num1, num2;
    int opcao;
    
    printf("Calculadora Simples\n");
    printf("Digite o primeiro número: ");
    scanf("%f", &num1);
    printf("Digite o segundo número: ");
    scanf("%f", &num2);
    
    printf("\nOperações disponíveis:\n");
    printf("1 - Soma\n");
    printf("2 - Subtração\n");
    printf("3 - Multiplicação\n");
    printf("4 - Divisão\n");
    printf("Escolha a operação (1-4): ");
    scanf("%d", &opcao);
    
    switch(opcao) {
        case 1:
            printf("\nResultado: %.2f + %.2f = %.2f\n", num1, num2, num1 + num2);
            break;
        case 2:
            printf("\nResultado: %.2f - %.2f = %.2f\n", num1, num2, num1 - num2);
            break;
        case 3:
            printf("\nResultado: %.2f * %.2f = %.2f\n", num1, num2, num1 * num2);
            break;
        case 4:
            if(num2 != 0) {
                printf("\nResultado: %.2f / %.2f = %.2f\n", num1, num2, num1 / num2);
            } else {
                printf("\nErro: Divisão por zero!\n");
            }
            break;
        default:
            printf("\nOpção inválida!\n");
    }
    
    return 0;
}
```

## **Menu de Opções em C usando Funções**

Aqui está um exemplo completo de um programa em C que usa funções para criar um menu interativo com 4 opções (1, 2, 3 e 4 para sair). Se o usuário digitar uma opção inválida, o programa exibe uma mensagem de erro e pede novamente a entrada.

```c
#include <stdio.h>

// Funções das opções
void opcao1() {
    printf("Você escolheu a Opção 1!\n");
}

void opcao2() {
    printf("Você escolheu a Opção 2!\n");
}

void opcao3() {
    printf("Você escolheu a Opção 3!\n");
}

// Função que exibe o menu
void exibirMenu() {
    printf("\n----- MENU -----\n");
    printf("1. Opção 1\n");
    printf("2. Opção 2\n");
    printf("3. Opção 3\n");
    printf("4. Sair\n");
}

int main() {
    int escolha;

    do {
        exibirMenu();
        printf("Digite sua opção: ");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                opcao1();
                break;
            case 2:
                opcao2();
                break;
            case 3:
                opcao3();
                break;
            case 4:
                printf("Saindo do programa...\n");
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    } while (escolha != 4); // Repete até o usuário escolher sair (4)

    return 0;
}

```

---

## **Como Funciona?**
1. **`exibirMenu()`** → Mostra as opções disponíveis.
2. **`main()`** →  
   - Usa um loop `do-while` para repetir até o usuário digitar **4 (Sair)**.
   - Lê a entrada do usuário (`scanf`) e usa `switch` para chamar a função correspondente.
   - Se a opção for inválida (`default`), imprime uma mensagem de erro.
3. **`opcao1()`, `opcao2()`, `opcao3()`** → Funções que executam ações específicas (aqui apenas imprimem mensagens, mas podem ser expandidas).

---

## **Exemplo de Saída**
```
----- MENU -----
1. Opção 1
2. Opção 2
3. Opção 3
4. Sair
Digite sua opção: 1
Você escolheu a Opção 1!

----- MENU -----
1. Opção 1
2. Opção 2
3. Opção 3
4. Sair
Digite sua opção: 5
Opção inválida! Tente novamente.

----- MENU -----
1. Opção 1
2. Opção 2
3. Opção 3
4. Sair
Digite sua opção: 4
Saindo do programa...
```

---

## Alterando o programa para permitir a leitura de caracteres

```c
#include <stdio.h>
#include <ctype.h> // Para a função tolower()

// Funções das opções
void opcao1() {
    printf("Você escolheu a Opção A!\n");
}

void opcao2() {
    printf("Você escolheu a Opção B!\n");
}

void opcao3() {
    printf("Você escolheu a Opção C!\n");
}

// Função que exibe o menu
void exibirMenu() {
    printf("\n----- MENU -----\n");
    printf("A. Opção A\n");
    printf("B. Opção B\n");
    printf("C. Opção C\n");
    printf("S. Sair\n");
}

int main() {
    char escolha;

    do {
        exibirMenu();
        printf("Digite sua opção: ");
        scanf(" %c", &escolha);  // Espaço antes do %c para ignorar whitespace
        escolha = tolower(escolha); // Converte para minúsculo

        switch (escolha) {
            case 'a':
                opcao1();
                break;
            case 'b':
                opcao2();
                break;
            case 'c':
                opcao3();
                break;
            case 's':
                printf("Saindo do programa...\n");
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
        }
        
        // Limpa o buffer de entrada
        while(getchar() != '\n');
        
    } while (escolha != 's');

    return 0;
}
```

### Funcionamento do Programa:

- Exibe menu com opções A, B, C e S (sair)
- Lê um caractere do usuário
- Converte para minúsculo (aceita 'A' ou 'a')
- Executa a função correspondente ou sai do programa
- Repete até o usuário digitar 's' ou 'S'

Esta versão é mais adequada para menus baseados em letras e trata melhor a entrada de caracteres.

### **Resumo**

- **Funções** em C são blocos de código reutilizáveis que ajudam a organizar e modularizar o programa.
- **Recursão** é uma técnica poderosa, mas deve ser usada com cuidado para evitar estouro de pilha.
- **Escopo de variáveis** define onde uma variável pode ser acessada (local ou global).
- **Passagem de argumentos** pode ser por valor (cópia) ou por referência (endereço de memória).
