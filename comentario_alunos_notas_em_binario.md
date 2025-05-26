# Explicação do Código: Sistema de Alunos com Notas

Este código implementa um sistema para gerenciar alunos e suas notas, com persistência em arquivo binário. Vamos analisá-lo em partes:

## Estruturas de Dados

```c
typedef struct node {
    float nota;
    struct node *proximo;
} Node;

typedef struct aluno {
    char nome[MAX_NAME];
    Node *notas;
} Aluno;
```

1. **Node**: Representa uma nota individual com:
   - `nota` (float): valor da nota
   - `proximo` (ponteiro): aponta para a próxima nota na lista

2. **Aluno**: Armazena informações do aluno com:
   - `nome` (string): nome do aluno (até 100 caracteres)
   - `notas` (ponteiro): aponta para a lista de notas do aluno

## Funções Principais

### Manipulação de Memória
- `libera_notas()`: Libera memória de uma lista encadeada de notas
- `libera_aluno()`: Libera memória de um aluno e suas notas
- `cria_no_nota()`: Aloca memória para uma nova nota
- `cria_no_aluno()`: Aloca memória para um novo aluno

### Operações com Listas
- `insere_nota()`: Adiciona uma nova nota no início da lista de notas

### Operações com Arquivos
- `salva_aluno_em_arquivo_binario()`: Escreve os dados de um aluno em um arquivo binário
- `ler_aluno_de_arquivo_binario()`: Lê os dados de um aluno de um arquivo binário

## Fluxo do Programa (main())

1. **Criação e salvamento de alunos**:
   - Cria dois alunos (Maria Joaquina e Ana Julia Silva)
   - Adiciona notas a cada aluno
   - Salva no arquivo "alunos.bin" (primeiro em modo "wb", depois em "ab")

2. **Leitura e exibição**:
   - Abre o arquivo em modo leitura ("rb")
   - Lê e exibe todos os alunos armazenados
   - Para cada aluno, mostra nome e lista de notas

## Formato do Arquivo Binário

Para cada aluno, o arquivo armazena:
1. Tamanho do nome (int)
2. Nome do aluno (chars)
3. Quantidade de notas (int)
4. Lista de notas (floats)

## Observações Importantes
- Uso de lista encadeada para armazenar notas de forma dinâmica.
- Tratamento de erros em operações de arquivo e alocação de memória.
- Garante que strings sejam terminadas corretamente com '\0'
- Verifica limites de tamanho para evitar overflow
- Libera toda memória alocada quando não é mais necessária

## Exemplo de Saída

```
=== Alunos cadastrados ===

--- Dados do aluno ---
Nome: Maria Joaquina
Notas: 8.00, 9.00, 10.00

--- Dados do aluno ---
Nome: Ana Julia Silva
Notas: 8.50, 7.00, 9.00, 9.00
```

Este código é um exemplo completo de como gerenciar estruturas de dados complexas (com alocação dinâmica) e persistí-las em arquivos binários, com todas as verificações necessárias para robustez.
