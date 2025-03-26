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

## **Exemplo Completo: Calculando a Hipotenusa**
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

---

### **Resumo**

- **Funções** em C são blocos de código reutilizáveis que ajudam a organizar e modularizar o programa.
- **Recursão** é uma técnica poderosa, mas deve ser usada com cuidado para evitar estouro de pilha.
- **Escopo de variáveis** define onde uma variável pode ser acessada (local ou global).
- **Passagem de argumentos** pode ser por valor (cópia) ou por referência (endereço de memória).
