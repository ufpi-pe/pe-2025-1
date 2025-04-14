# **Structs (Estruturas) na Linguagem de Programação C**  

## **Objetivos da Aula**  
1. Compreender o conceito de **structs** em C.  
2. Declarar, inicializar e acessar membros de uma struct.  
3. Utilizar structs com funções (passagem por valor e referência).  
4. Criar estruturas aninhadas e arrays de structs.  

---

## **Conteúdo**  

### **1. Introdução a Structs**  
- **Definição:**  
  - Uma **struct** (estrutura) é um tipo de dado que permite agrupar variáveis de tipos diferentes sob um único nome.  
  - Útil para representar entidades complexas (ex.: aluno, produto, ponto 2D).  

- **Comparação com outros tipos:**  
  - **Array:** Armazena vários elementos do **mesmo tipo**.  
  - **Struct:** Armazena elementos de **tipos diferentes**.  

### **2. Declaração e Uso Básico**  
#### **Sintaxe:**  
```c
struct NomeDaStruct {
    tipo1 membro1;
    tipo2 membro2;
    // ...
};
```

#### **Exemplo Prático:**  
```c
#include <stdio.h>

// Declaração da struct
struct Aluno {
    char nome[50];
    int idade;
    float nota;
};

int main() {
    // Criando uma variável do tipo struct Aluno
    struct Aluno aluno1;

    // Atribuindo valores
    strcpy(aluno1.nome, "João Silva");
    aluno1.idade = 20;
    aluno1.nota = 8.5;

    // Acessando valores
    printf("Nome: %s\n", aluno1.nome);
    printf("Idade: %d\n", aluno1.idade);
    printf("Nota: %.2f\n", aluno1.nota);

    return 0;
}
```

---

### **3. Inicialização de Structs**  
- Pode ser feita diretamente na declaração:  
```c
struct Aluno aluno2 = {"Maria Souza", 22, 9.0};
```

---

### **4. Structs e Funções**  
#### **Passagem por Valor (cópia):**  
```c
void imprimirAluno(struct Aluno a) {
    printf("Nome: %s\n", a.nome);
    printf("Idade: %d\n", a.idade);
    printf("Nota: %.2f\n", a.nota);
}
```

#### **Passagem por Referência (ponteiro):**  
```c
void alterarNota(struct Aluno *a, float novaNota) {
    a->nota = novaNota; // Usa-se "->" para acessar membros via ponteiro
}
```

---

### **5. Structs Aninhadas**  
- Uma struct pode conter outra struct como membro.  
```c
struct Endereco {
    char rua[50];
    int numero;
};

struct Pessoa {
    char nome[50];
    struct Endereco endereco;
};
```

---

### **6. Array de Structs**  
- Útil para armazenar múltiplas instâncias (ex.: lista de alunos).  
```c
struct Aluno turma[30]; // Array de 30 alunos

// Exemplo de uso:
turma[0].idade = 19;
strcpy(turma[0].nome, "Carlos");
```

---

### **7. Typedef com Structs**  
- Simplifica a declaração eliminando a necessidade de usar `struct` toda vez.  
```c
typedef struct {
    int x;
    int y;
} Ponto;

// Agora podemos declarar diretamente:
Ponto p1 = {10, 20};
```

---

### **8. Exemplos**

Exemplo1: Cadastra N alunos em um vetor de alunos

```c
#include <stdio.h>
#include <string.h>

// Definição da struct Aluno
struct Aluno {
    char nome[50];
    int idade;
    float nota;
};

int main() {
    int quantidade;
    printf("Quantos alunos deseja cadastrar? ");
    scanf("%d", &quantidade);
    getchar(); // Limpa o buffer do teclado

    struct Aluno turma[quantidade]; // Array de structs

    // Cadastro dos alunos
    for (int i = 0; i < quantidade; i++) {
        printf("\nAluno %d:\n", i + 1);
        
        printf("Nome: ");
        fgets(turma[i].nome, 50, stdin);
        turma[i].nome[strcspn(turma[i].nome, "\n")] = '\0'; // Remove o \n do fgets

        printf("Idade: ");
        scanf("%d", &turma[i].idade);

        printf("Nota: ");
        scanf("%f", &turma[i].nota);
        getchar(); // Limpa o buffer
    }

    // Listagem dos alunos cadastrados
    printf("\n--- ALUNOS CADASTRADOS ---\n");
    for (int i = 0; i < quantidade; i++) {
        printf("\nAluno %d:\n", i + 1);
        printf("Nome: %s\n", turma[i].nome);
        printf("Idade: %d\n", turma[i].idade);
        printf("Nota: %.2f\n", turma[i].nota);
    }

    // Cálculo da média da turma
    float soma = 0;
    for (int i = 0; i < quantidade; i++) {
        soma += turma[i].nota;
    }
    float media = soma / quantidade;
    printf("\nMédia da turma: %.2f\n", media);

    return 0;
}
```

Exemplo2: Cadastra N alunos em um vetor de alunos, refatorado para ser organizado em funções

```c
#include <stdio.h>
#include <string.h>

// Definição da struct Aluno
struct Aluno {
    char nome[50];
    int idade;
    float nota;
};

// Função para cadastrar alunos
void cadastrarAlunos(struct Aluno turma[], int quantidade) {
    for (int i = 0; i < quantidade; i++) {
        printf("\nAluno %d:\n", i + 1);
        
        printf("Nome: ");
        fgets(turma[i].nome, 50, stdin);
        turma[i].nome[strcspn(turma[i].nome, "\n")] = '\0'; // Remove o \n do fgets

        printf("Idade: ");
        scanf("%d", &turma[i].idade);

        printf("Nota: ");
        scanf("%f", &turma[i].nota);
        getchar(); // Limpa o buffer
    }
}

// Função para listar alunos
void listarAlunos(struct Aluno turma[], int quantidade) {
    printf("\n--- ALUNOS CADASTRADOS ---\n");
    for (int i = 0; i < quantidade; i++) {
        printf("\nAluno %d:\n", i + 1);
        printf("Nome: %s\n", turma[i].nome);
        printf("Idade: %d\n", turma[i].idade);
        printf("Nota: %.2f\n", turma[i].nota);
    }
}

// Função para calcular a média
float calcularMedia(struct Aluno turma[], int quantidade) {
    float soma = 0;
    for (int i = 0; i < quantidade; i++) {
        soma += turma[i].nota;
    }
    return soma / quantidade;
}

int main() {
    int quantidade;
    
    printf("Quantos alunos deseja cadastrar? ");
    scanf("%d", &quantidade);
    getchar(); // Limpa o buffer do teclado

    struct Aluno turma[quantidade]; // Array de structs

    // Cadastro dos alunos
    cadastrarAlunos(turma, quantidade);

    // Listagem dos alunos cadastrados
    listarAlunos(turma, quantidade);

    // Cálculo e exibição da média da turma
    float media = calcularMedia(turma, quantidade);
    printf("\nMédia da turma: %.2f\n", media);

    return 0;
}
```

---

## **Conclusão**  
- Structs são fundamentais para organizar dados complexos em C.  
- Permitem modelar entidades do mundo real de forma eficiente.  
- Combinam-se bem com funções, ponteiros e arrays.  
