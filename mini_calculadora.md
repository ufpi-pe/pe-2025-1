# Explicação do Código da Calculadora Científica em C

Este programa é uma calculadora científica modular que implementa várias operações matemáticas.

## Estrutura do Projeto

O projeto está organizado em 3 arquivos:

1. **operacoes.h** - Cabeçalho com declarações das funções
2. **operacoes.c** - Implementação das funções matemáticas
3. **main.c** - Interface do usuário e lógica principal

## 1. operacoes.h - Definições

```c
#ifndef OPERACOES_H
#define OPERACOES_H

#include <math.h>

#define PI 3.14159265358979323846

// Declarações das funções...
#endif
```

- **#ifndef/#define** - Previne inclusão múltipla do cabeçalho
- **PI** - Constante para conversão graus-radianos
- Declara todas as funções matemáticas disponíveis

## 2. operacoes.c - Implementações

Contém as implementações das funções matemáticas:

### Funções Trigonométricas

```c
double para_radianos(double graus) {
    return graus * PI / 180.0;
}

double seno(double x, int modo) {
    if (modo == 2) x = para_radianos(x);
    return sin(x);
}
// Similar para cosseno e tangente
```

- **para_radianos()** - Converte graus para radianos
- As funções trigonométricas aceitam um parâmetro `modo` (1=radianos, 2=graus)

### Outras Funções

```c
double exponencial(double x) { return exp(x); }
double logaritmo_natural(double x) { return log(x); }
// Demais funções...
```

## 3. main.c - Interface do Usuário

### Estrutura Principal

```c
int main() {
    int opcao;
    do {
        mostrar_menu();
        // Ler opção e processar
    } while(opcao != 0);
    return 0;
}
```

- Loop principal que mostra o menu até o usuário sair (opção 0)

### Tratamento de Entradas

```c
while (scanf("%lf", &valor) != 1) {
    printf("Valor inválido! Digite um número: ");
    limpar_buffer();
}
```

- Verifica se a entrada é válida
- Limpa o buffer se necessário

### Operações Trigonométricas

```c
do {
    printf("Digite 1 para radianos ou 2 para graus: ");
    // Validação do modo
} while(1);
```

- Pede confirmação do modo (radianos/graus) antes do cálculo

## Como Compilar

### Passo a Passo:

1. **Salve os arquivos** em um mesmo diretório:
   - operacoes.h
   - operacoes.c
   - main.c

2. **Abra o terminal** nesse diretório

3. **Compile o programa** com o comando:
   ```bash
   gcc -o calculadora main.c operacoes.c -lm
   ```
   - `-o calculadora` - Nome do executável
   - `main.c operacoes.c` - Arquivos fonte
   - `-lm` - Linka a biblioteca matemática

4. **Execute o programa**:
   ```bash
   ./calculadora
   ```

### Exemplo de Uso:

1. Ao executar, você verá o menu:
   ```
   === MINI CALCULADORA CIENTIFICA ===
   1. Seno
   2. Cosseno
   3. Tangente
   ...
   ```

2. Para calcular um seno em graus:
   - Digite 1 (Seno)
   - Digite 2 (graus)
   - Digite o valor (ex: 90)
   - Resultado: "Seno(90.00) = 1.0000"

3. A calculadora continuará mostrando o menu até você digitar 0 para sair.

## Considerações Finais

- O código está modularizado para facilitar manutenção
- Todas as entradas são validadas
- As funções trigonométricas oferecem flexibilidade de unidades
- A compilação com `-lm` é essencial para as funções matemáticas

Esta estrutura permite fácil expansão para adicionar novas funções matemáticas no futuro.
