#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_NAME 100

/* Define um tipo Node para guardar notas */
typedef struct node
{
    float nota;
    struct node *proximo;
} Node;

/* Define um tipo Aluno para guardar alunos */
typedef struct aluno
{
    char nome[MAX_NAME];
    Node *notas;
} Aluno;

/*
    Funcao para liberar a memoria da lista de notas
*/
void libera_notas(Node *lista) {
    while (lista != NULL) {
        Node *temp = lista;
        lista = lista->proximo;
        free(temp);
    }
}

/*
    Funcao para liberar a memoria de um aluno
*/
void libera_aluno(Aluno *aluno) {
    if (aluno != NULL) {
        libera_notas(aluno->notas);
        free(aluno);
    }
}

/*
    Funcao para criar um no de nota
    recebe uma nota
    retorna um novo no de nota
*/
Node *cria_no_nota(float nota)
{
    Node *novo_no = (Node *)malloc(sizeof(Node));
    if (novo_no == NULL) {
        perror("Erro ao alocar memoria para nota");
        exit(EXIT_FAILURE);
    }
    novo_no->nota = nota;
    novo_no->proximo = NULL;
    return novo_no;
}

/*
    Funcao para criar um no de aluno
    recebe nome e lista de notas do aluno
    retorna novo no de aluno
*/
Aluno *cria_no_aluno(char *nome, Node *lista_notas)
{
    Aluno *novo_no = (Aluno *)malloc(sizeof(Aluno));
    if (novo_no == NULL) {
        perror("Erro ao alocar memoria para aluno");
        exit(EXIT_FAILURE);
    }

    strncpy(novo_no->nome, nome, MAX_NAME - 1);
    novo_no->nome[MAX_NAME - 1] = '\0';  // Garante terminação nula
    novo_no->notas = lista_notas;
    return novo_no;
}

/*
    Funcao para inserir nota na lista de notas
    recebe um ponteiro que aponta para lista de notas
    recebe uma nota
    Nao retorna nada, pois passa um ponteiro para lista de notas como referencia
*/
void insere_nota(Node **cabeca_da_lista, float nota)
{
    Node *novo_no = cria_no_nota(nota);
    novo_no->proximo = *cabeca_da_lista;
    *cabeca_da_lista = novo_no;
}

/*
    Funcao para salvar um aluno A em arquivo binario F
    recebe aluno e arquivo
    Nao retorna nada, pois salva os dados direto no arquivo
*/
void salva_aluno_em_arquivo_binario(Aluno *aluno, FILE *file)
{
    if (file == NULL) {
        perror("Arquivo invalido");
        return;
    }

    /* precisa guardar o tamanho em bytes do nome do aluno */
    int tamanho_nome = strlen(aluno->nome) + 1;

    /* grava o tamanho do nome do aluno no arquivo */
    if (fwrite(&tamanho_nome, sizeof(int), 1, file) != 1) {
        perror("Erro ao escrever tamanho do nome");
    }
    /* grava o nome do aluno no arquivo */
    if (fwrite(aluno->nome, sizeof(char), tamanho_nome, file) != tamanho_nome) {
        perror("Erro ao escrever nome do aluno");
    }

    /* precisa guardar a quantidade de notas salvas no aluno */
    int qtd_notas = 0;
    /* percorre a lista de notas para calcular a qtd de notas */
    Node *lista_aux = aluno->notas;
    while (lista_aux != NULL)
    {
        qtd_notas = qtd_notas + 1;
        lista_aux = lista_aux->proximo;
    }

    /* grava a quantidade de notas no arquivo */
    if (fwrite(&qtd_notas, sizeof(int), 1, file) != 1) {
        perror("Erro ao escrever quantidade de notas");
    }
    /* percorre a lista de notas e salva cada nota no arquivo */
    lista_aux = aluno->notas;
    while (lista_aux != NULL)
    {
        if (fwrite(&lista_aux->nota, sizeof(float), 1, file) != 1) {
            perror("Erro ao escrever nota");
        }
        lista_aux = lista_aux->proximo;
    }
}

/*
    Funcao que ler um aluno do arquivo binario
    parametros: arquivo binario que contem os dados dos alunos salvos
    retorna um aluno lido ou NULL se erro ou fim do arquivo
*/
Aluno *ler_aluno_de_arquivo_binario(FILE *file)
{
    if (file == NULL) {
        return NULL;
    }

    /* ler o tamanho em caracteres do nome do aluno */
    int tamanho_nome;
    if (fread(&tamanho_nome, sizeof(int), 1, file) != 1) {
        return NULL;  // Provavelmente fim do arquivo
    }

    /* Verifica se o tamanho do nome é válido */
    if (tamanho_nome <= 0 || tamanho_nome > MAX_NAME) {
        fprintf(stderr, "Tamanho do nome invalido: %d\n", tamanho_nome);
        return NULL;
    }

    char nome[MAX_NAME];
    /* ler o nome do aluno */
    if (fread(nome, sizeof(char), tamanho_nome, file) != tamanho_nome) {
        perror("Erro ao ler nome do aluno");
        return NULL;
    }

    /*Precisa ler as notas do aluno */
    /*E preciso saber a qtd de notas salvas */
    int qtd_notas;
    if (fread(&qtd_notas, sizeof(int), 1, file) != 1) {
        perror("Erro ao ler quantidade de notas");
        return NULL;
    }

    /* Verifica se a quantidade de notas é válida */
    if (qtd_notas < 0) {
        fprintf(stderr, "Quantidade de notas invalida: %d\n", qtd_notas);
        return NULL;
    }

    /*Percorre as notas salvas - qtd de notas */
    Node *lista_notas = NULL;
    float nota_temp;
    for (int i = 0; i < qtd_notas; i++)
    {
        if (fread(&nota_temp, sizeof(float), 1, file) != 1) {
            perror("Erro ao ler nota");
            libera_notas(lista_notas);
            return NULL;
        }
        insere_nota(&lista_notas, nota_temp);
    }

    return cria_no_aluno(nome, lista_notas);
}

int main()
{
    FILE *file_new; /* Cria referencia para arquivo */

    /* Funcao para criar aluno e salvar no arquivo */
    /* Cria aluno com uma lista de notas vazia */
    Aluno *aluno1 = cria_no_aluno("Maria Joaquina", NULL);
    /* Insere 3 notas no aluno1 */
    insere_nota(&aluno1->notas, 10);
    insere_nota(&aluno1->notas, 9);
    insere_nota(&aluno1->notas, 8);
    /* Grava o aluno 1 no arquivo alunos2.bin */
    file_new = fopen("alunos2.bin", "wb");  // "wb" para criar novo arquivo
    if (file_new == NULL) {
        perror("Erro ao abrir arquivo para escrita");
        libera_aluno(aluno1);
        return EXIT_FAILURE;
    }
    salva_aluno_em_arquivo_binario(aluno1, file_new);
    /* fecha o arquivo */
    fclose(file_new);
    libera_aluno(aluno1);

    /* Cria aluno com uma lista de notas vazia */
    Aluno *aluno2 = cria_no_aluno("Ana Julia Silva", NULL);
    /* Insere 4 notas no aluno2 */
    insere_nota(&aluno2->notas, 9);
    insere_nota(&aluno2->notas, 9);
    insere_nota(&aluno2->notas, 7);
    insere_nota(&aluno2->notas, 8.5);
    /* Grava o aluno 2 no arquivo alunos2.bin */
    file_new = fopen("alunos2.bin", "ab");  // "ab" para adicionar ao arquivo existente
    if (file_new == NULL) {
        perror("Erro ao abrir arquivo para escrita adicional");
        libera_aluno(aluno2);
        return EXIT_FAILURE;
    }
    salva_aluno_em_arquivo_binario(aluno2, file_new);
    /* fecha o arquivo */
    fclose(file_new);
    libera_aluno(aluno2);

    /* Abre o arquivo binario para ler os dados binarios */
    FILE *file_to_open = fopen("alunos2.bin", "rb");
    if (file_to_open == NULL) {
        perror("Erro ao abrir arquivo para leitura");
        return EXIT_FAILURE;
    }

    printf("=== Alunos cadastrados ===\n");
    
    while (1) {
        Aluno *dados_aluno = ler_aluno_de_arquivo_binario(file_to_open);
        if (dados_aluno == NULL) {
            break;  // Fim do arquivo ou erro
        }

        printf("\n--- Dados do aluno ---\n");
        printf("Nome: %s\n", dados_aluno->nome);
        printf("Notas: ");
        
        /* Percorre a lista de notas do aluno recuperado */
        Node *lista_notas_aux = dados_aluno->notas;
        while (lista_notas_aux != NULL) {
            printf("%.2f", lista_notas_aux->nota);
            lista_notas_aux = lista_notas_aux->proximo;
            if (lista_notas_aux != NULL) {
                printf(", ");
            }
        }
        printf("\n");
        
        libera_aluno(dados_aluno);
    }

    /* fecha o arquivo de leitura */
    fclose(file_to_open);

    return EXIT_SUCCESS;
}
