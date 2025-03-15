# Revisão 1

Tipos, variáveis, operadores, comandos condicionais (if), loops (for, while, do).

### **Exercício 1: Verificação de Número Positivo, Negativo ou Zero**

```c
#include <stdio.h>

int main() {
    int numero;

    printf("Digite um número: ");
    scanf("%d", &numero);

    if (numero > 0) {
        printf("O número é positivo.\n");
    } else if (numero < 0) {
        printf("O número é negativo.\n");
    } else {
        printf("O número é zero.\n");
    }

    return 0;
}
```

**Explicação:**
- O programa solicita ao usuário um número.
- Usa uma estrutura `if-else` para verificar se o número é positivo, negativo ou zero.
- Dependendo do valor, imprime a mensagem correspondente.

---

### **Exercício 2: Contagem de 1 a 10**

```c
#include <stdio.h>

int main() {
    for (int i = 1; i <= 10; i++) {
        printf("%d ", i);
    }
    printf("\n");

    return 0;
}
```

**Explicação:**
- O loop `for` é usado para iterar de 1 a 10.
- A cada iteração, o valor de `i` é impresso.
- No final, uma nova linha é impressa para melhorar a formatação.

---

### **Exercício 3: Soma de Números**

```c
#include <stdio.h>

int main() {
    int numero, soma = 0;

    while (1) {
        printf("Digite um número (0 para sair): ");
        scanf("%d", &numero);

        if (numero == 0) {
            break;
        }

        soma = soma + numero;
    }

    printf("A soma dos números é: %d\n", soma);

    return 0;
}
```

**Explicação:**
- O programa usa um loop `while` para continuar solicitando números até que o usuário digite 0.
- A variável `soma` acumula o valor de todos os números digitados.
- Quando o usuário digita 0, o loop é interrompido com `break`, e a soma é exibida.

---

### **Exercício 4: Tabela de Multiplicação**

```c
#include <stdio.h>

int main() {
    for (int i = 1; i <= 10; i++) {
        for (int j = 1; j <= 10; j++) {
            printf("%2d ", i * j);
        }
        printf("\n");
    }

    return 0;
}
```

**Explicação:**
- Dois loops `for` aninhados são usados para gerar a tabela de multiplicação.
- O loop externo (`i`) controla as linhas, e o loop interno (`j`) controla as colunas.
- `%2d` é usado para formatar os números com dois dígitos.

---

### **Exercício 5: Verificação de Número Primo**

```c
#include <stdio.h>

int main() {
    int numero, ehPrimo = 1;

    printf("Digite um número: ");
    scanf("%d", &numero);

    for (int i = 2; i <= numero / 2; i++) {
        if (numero % i == 0) {
            ehPrimo = 0;
            break;
        }
    }

    if (ehPrimo && numero > 1) {
        printf("%d é um número primo.\n", numero);
    } else {
        printf("%d não é um número primo.\n", numero);
    }

    return 0;
}
```

**Explicação:**
- O programa verifica se o número é divisível por algum valor entre 2 e `numero / 2`.
- Se for divisível, `ehPrimo` é definido como 0 (falso).
- No final, o programa imprime se o número é primo ou não.

---

### **Exercício 6: Adivinhe o Número**

```c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0));
    int numeroAleatorio = rand() % 100 + 1;
    int palpite;

    do {
        printf("Adivinhe o número (entre 1 e 100): ");
        scanf("%d", &palpite);

        if (palpite > numeroAleatorio) {
            printf("Muito alto!\n");
        } else if (palpite < numeroAleatorio) {
            printf("Muito baixo!\n");
        }
    } while (palpite != numeroAleatorio);

    printf("Parabéns! Você acertou o número!\n");

    return 0;
}
```

**Explicação:**
- O programa gera um número aleatório entre 1 e 100 usando `rand()`.
- O loop `do-while` continua pedindo palpites até que o usuário acerte o número.
- Dicas são fornecidas se o palpite for muito alto ou muito baixo.

---

### **Exercício 7: Fatorial de um Número**

```c
#include <stdio.h>

int main() {
    int numero, fatorial = 1;

    printf("Digite um número: ");
    scanf("%d", &numero);

    int i = 1;
    while (i <= numero) {
        fatorial = fatorial * i;
        i++;
    }

    printf("O fatorial de %d é: %d\n", numero, fatorial);

    return 0;
}
```

**Explicação:**
- O programa calcula o fatorial de um número usando um loop `while`.
- A variável `fatorial` acumula o produto dos números de 1 até `numero`.

---

### **Exercício 8: Sequência de Fibonacci**

```c
#include <stdio.h>

int main() {
    int n, a = 0, b = 1, proximo;

    printf("Digite o número de termos: ");
    scanf("%d", &n);

    printf("Sequência de Fibonacci: ");
    for (int i = 1; i <= n; i++) {
        printf("%d ", a);
        proximo = a + b;
        a = b;
        b = proximo;
    }
    printf("\n");

    return 0;
}
```

**Explicação:**
- O programa gera a sequência de Fibonacci usando um loop `for`.
- A cada iteração, o próximo termo é calculado como a soma dos dois termos anteriores.

---

### **Exercício 9: Soma de Dígitos**

```c
#include <stdio.h>

int main() {
    int numero, soma = 0;

    printf("Digite um número: ");
    scanf("%d", &numero);

    while (numero != 0) {
        soma += numero % 10;
        numero /= 10;
    }

    printf("A soma dos dígitos é: %d\n", soma);

    return 0;
}
```

**Explicação:**
- O programa usa um loop `while` para somar os dígitos de um número.
- A cada iteração, o último dígito é extraído usando `numero % 10` e adicionado à soma.
- O número é então dividido por 10 para remover o último dígito.

---

### **Exercício 10: Padrão de Asteriscos**

```c
#include <stdio.h>

int main() {
    for (int i = 1; i <= 5; i++) {
        for (int j = 1; j <= i; j++) {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}
```

**Explicação:**
- Dois loops `for` aninhados são usados para imprimir o padrão de asteriscos.
- O loop externo controla o número de linhas, e o loop interno imprime os asteriscos em cada linha.

---
