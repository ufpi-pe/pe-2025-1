#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_NAME 100

/* Define um tipo Node para guardar notas */
typedef struct node{
    float nota;
    struct node *proximo;
}Node;

/* Define um tipo Aluno para guardar alunos */
typedef struct aluno{
    char nome[MAX_NAME];
    Node *notas;
}Aluno;

/* 
    Funcao para criar um no de nota 
    recebe uma nota 
    retorna um novo no de nota    
*/
Node *cria_no_nota(float nota){
    Node *novo_no = (Node *)malloc(sizeof(Node));
    
    novo_no->nota = nota;
    novo_no->proximo = NULL;
    return novo_no;
}

/*
    Funcao para criar um no de aluno
    recebe nome e lista de notas do aluno
    retorna novo no de aluno
*/
Aluno *cria_no_aluno(char *nome, Node *lista_notas){
    Aluno *novo_no = (Aluno *)malloc(sizeof(Aluno));
    
    strcpy(novo_no->nome, nome);
    novo_no->notas = lista_notas;
    return novo_no;
}

/*
    Funcao para inserir nota na lista de notas
    recebe um ponteiro que aponta para lista de notas
    recebe uma nota
    Nao retorna nada, pois passa um ponteiro para lista de notas como referencia
*/
void insere_nota(Node **cabeca_da_lista, float nota){
    Node *novo_no = cria_no_nota(nota);
    novo_no->proximo = *cabeca_da_lista;
    *cabeca_da_lista = novo_no;
}

/*
    Funcao para salvar um aluno A em arquivo binario F
    recebe aluno e arquivo
    Nao retorna nada, pois salva os dados direto no arquivo
*/
void salva_aluno_em_arquivo_binario(Aluno *aluno, FILE *file){
    /* precisa guardar o tamanho em bytes do nome do aluno */
    int tamanho_nome = strlen(aluno->nome) + 1; 

    /* grava o tamanho do nome do aluno no arquivo */
    fwrite(&tamanho_nome, sizeof(int), 1, file);
    /* grava o nome do aluno no arquivo */
    fwrite(aluno->nome, sizeof(char), tamanho_nome, file);

    /* precisa guardar a quantidade de notas salvas no aluno */
    int qtd_notas=0; 
    /* percorre a lista de notas para calcular a qtd de notas */
    Node *lista_aux = aluno->notas;
    while(lista_aux != NULL){
        qtd_notas = qtd_notas + 1;
        lista_aux = lista_aux->proximo;
    } 

    /* grava a quantidade de notas no arquivo */
    fwrite(&qtd_notas, sizeof(int), 1, file);
    /* percorre a lista de notas e salva cada nota no arquivo */
    lista_aux = NULL;
    lista_aux = aluno->notas;
    while(lista_aux != NULL){
        fwrite(&lista_aux->nota, sizeof(float), 1, file);
        lista_aux = lista_aux->proximo;
    }
}

/*
    Funcao que ler um aluno do arquivo binario
    parametros: arquivo binario que contem os dados dos alunos salvos
    retorna um aluno lido
*/
Aluno *ler_aluno_de_arquivo_binario(FILE *file){
    /* Deve receber o arquivo em modo de leitura */
    
    /* ler o tamanho em caracteres do nome do aluno */
    int tamanho_nome; 
    fread(&tamanho_nome, sizeof(int), 1, file);

    char nome[MAX_NAME];
    /* ler o nome do aluno */
    fread(nome, sizeof(char), tamanho_nome, file);

    /*Precisa ler as notas do aluno */
    /*E preciso saber a qtd de notas salvas */
    int qtd_notas;
    fread(&qtd_notas, sizeof(int), 1, file);

    /*Percorre as notas salvas - qtd de notas */
    Node *lista_notas = NULL;
    float nota_temp;  
    for (int i=0; i<qtd_notas; i++){
        fread(&nota_temp, sizeof(float), 1, file);
        insere_nota(&lista_notas, nota_temp);
    }

    return cria_no_aluno(nome, lista_notas);
}

int main(){
    /* Cria um arquivo binario para inserir registros sempre ao final */
    FILE *file_new = fopen("alunos.bin", "ab");

    /* Cria um aluno com uma lista de notas vazia */
    Aluno *aluno1 = cria_no_aluno("Maria Joaquina", NULL);

    /* Insere 3 notas no aluno1 */
    insere_nota(&aluno1->notas, 10);
    insere_nota(&aluno1->notas, 9);
    insere_nota(&aluno1->notas, 8);

    /* Grava o aluno 1 no arquivo alunos.bin */
    salva_aluno_em_arquivo_binario(aluno1, file_new);
    /* fecha o arquivo */
    fclose(file_new);

    /* Abre o arquivo binario para ler os dados binarios */
    FILE *file_to_open = fopen("alunos.bin", "rb");
    Aluno *dados_aluno;
    dados_aluno = ler_aluno_de_arquivo_binario(file_to_open);
    /* fecha o arquivo */
    fclose(file_to_open);

    printf("--- Dados do aluno ---\n");
    printf("Nome: %s\n", dados_aluno->nome);
    printf("Notas: ");
    /* Percorre a lista de notas do aluno recuperado */
    Node *lista_notas_aux=dados_aluno->notas; 
    while(lista_notas_aux != NULL){
        printf("%.2f ,", lista_notas_aux->nota);
        lista_notas_aux = lista_notas_aux->proximo;
    }
    printf("\n");
}
