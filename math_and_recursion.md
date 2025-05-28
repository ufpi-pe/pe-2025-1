### Funções Matemáticas e Recursão em C

#### **1. Funções Matemáticas em C (Biblioteca math.h)**
- **Funções Trigonométricas**:  
  - `sin()`, `cos()`, `tan()`: Calculam seno, cosseno e tangente de um ângulo em radianos.  
  - `asin()`, `acos()`, `atan()`: Calculam arco seno, arco cosseno e arco tangente.  
  - Exemplo:  
    ```c
    double result = sin(1.0); // Retorna 0.841471
    ```

- **Funções Exponenciais e Logarítmicas**:  
  - `exp()`: Retorna \( e^x \).  
  - `log()`, `log10()`, `log2()`: Calculam logaritmos natural, base 10 e base 2.  
  - Exemplo:  
    ```c
    double result = exp(1.0); // Retorna 2.718282
    ```

- **Funções de Potência e Raiz**:  
  - `pow(x, y)`: Calcula \( x^y \).  
  - `sqrt()`: Calcula a raiz quadrada.  
  - Exemplo:  
    ```c
    double result = pow(2.0, 3.0); // Retorna 8.0
    ```

- **Funções de Arredondamento**:  
  - `ceil()`: Arredonda para cima.  
  - `floor()`: Arredonda para baixo.  
  - Exemplo:  
    ```c
    double result = ceil(1.8); // Retorna 2.0
    ```

- **Mini Calculadora Científica Modularizada**:  
  - Demonstração de como organizar funções matemáticas em módulos (`operacoes.c` e `operacoes.h`).  

---

#### **2. Recursão em C**
- **Conceito**:  
  - Técnica onde uma função chama a si mesma para resolver subproblemas até atingir um caso base.  
  - Exemplo clássico: **Fatorial** (recursivo vs. iterativo).  
    ```c
    int factorial(int n) {
        if (n == 1) return 1;
        return n * factorial(n-1);
    }
    ```

- **Sequência de Fibonacci**:  
  - Definição recursiva: \( F_n = F_{n-1} + F_{n-2} \) (com \( F_1 = 1 \), \( F_2 = 1 \)).  
  - Exemplo de implementação recursiva (menos eficiente que a versão iterativa).  

- **Vantagens da Recursão**:  
  - Clareza para problemas com estrutura recursiva (e.g., árvores, backtracking).  
  - Código mais conciso e elegante.  

- **Desvantagens**:  
  - Overhead de memória (pilha de chamadas).  
  - Risco de estouro de pilha (*stack overflow*) se não houver caso base adequado.  
  - Pode ser menos eficiente que iteração para problemas simples.  

- **Comparação com Iteração**:  
  - **Iteração**: Usa loops (`for`, `while`), mais eficiente em memória e desempenho para repetições simples.  
  - **Recursão**: Ideal para problemas divididos em subproblemas (e.g., algoritmos de divisão e conquista como *Merge Sort*).  

---

#### **3. Aplicações Práticas de Recursão**
- **Algoritmos Clássicos**:  
  - **Pesquisa Binária**: Divide o array recursivamente.  
  - **Merge Sort**: Divide o array em metades até ordenar.  
  - **Backtracking**: Gera soluções tentativas (e.g., permutações, labirintos).  
- **Estruturas de Dados**:  
  - Percursos em árvores (pré-ordem, pós-ordem).  

---

### **Pontos-Chave**:
1. **Biblioteca `math.h`** oferece funções matemáticas prontas para cálculos complexos.  
2. **Recursão** é poderosa para problemas hierárquicos, mas exige cuidado com casos base e desempenho.  
3. **Iteração** é preferível para loops simples e eficiência.  
4. **Modularização** (como na calculadora) melhora organização e reutilização de código.  

**Dica**: Use recursão para problemas naturais (e.g., árvores) e iteração para repetições diretas. Sempre avalie trade-offs entre clareza e desempenho.
