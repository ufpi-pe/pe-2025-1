# Comentários do Programa (simplificado) de Manipulação de Contatos

Este código implementa um programa de gerenciamento simplificado de contatos com persistência em arquivo binário.

## Estruturas de Dados

```c
typedef struct telefone {
    char numero[MAX_PHONE_LENGTH];  // Armazena o número de telefone
    struct telefone *proximo;      // Ponteiro para o próximo telefone (lista encadeada)
} Telefone;

typedef struct contato {
    char nome[MAX_NAME_LENGTH];    // Nome do contato
    char email[MAX_EMAIL_LENGTH];  // E-mail do contato
    Telefone *telefones;           // Lista de telefones do contato
} Contato;

typedef struct node {
    Contato *dados;                // Dados do contato
    struct node *proximo;          // Ponteiro para o próximo contato (lista encadeada)
} node_contato;
```

## Funções Principais

### 1. Gerenciamento de Memória
```c
void libera_telefones(Telefone *lista);      // Libera lista de telefones
void libera_contato(Contato *contato);       // Libera um contato e seus telefones
void libera_lista_contatos(node_contato *lista); // Libera toda a lista de contatos
```

### 2. Manipulação de Contatos
```c
void adicionar_telefone(Contato *contato, char *numero);  // Adiciona telefone a um contato
node_contato *insere_contato(Contato contato, node_contato *lista); // Insere novo contato
void mostra_lista_contatos(node_contato *lista);          // Exibe todos os contatos
```

### 3. Persistência em Arquivo
```c
void salva_contato_arquivo_binario(node_contato *contato, FILE *file);
void salva_lista_contatos_arquivo_binario(node_contato *lista, const char *nome_arquivo);
Contato *ler_contato_arquivo_binario(FILE *file);
node_contato *ler_lista_contatos_arquivo_binario(const char *nome_arquivo);
```

## Fluxo Principal (main())

O programa oferece um menu interativo com as seguintes opções:

1. **Adicionar novo contato**: Solicita nome, e-mail e telefones (múltiplos)
2. **Listar todos os contatos**: Exibe todos os contatos cadastrados
3. **Salvar contatos em arquivo**: Grava a lista atual no arquivo binário
4. **Carregar contatos do arquivo**: Lê contatos do arquivo binário
5. **Sair**: Encerra o programa

## Formato do Arquivo Binário

Para cada contato, o arquivo armazena:
1. Tamanho do nome + nome
2. Tamanho do e-mail + e-mail
3. Quantidade de telefones + lista de telefones (cada um com seu tamanho)

Este código demonstra um uso avançado de estruturas de dados em C, com listas encadeadas, manipulação de arquivos binários e gerenciamento cuidadoso de memória.
