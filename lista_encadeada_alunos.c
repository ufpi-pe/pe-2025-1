#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Define um tipo Aluno
    O tipo aluno precisa de: 70 bytes para guardar um aluno
*/
typedef struct {
  char matricula[12]; // 12 * 1 byte = 12 bytes
  char nome[50];      // 50 * 1 byte = 50 bytes
  float notas[2];     // 2 * 4 bytes = 8 bytes
} Aluno;

/*
Define um no de lista dinamica de alunos
*/
struct node {
  Aluno *informacao;
  struct node *proximo;
};

// cria um tipo Lista
typedef struct node Lista;

/* insere uma novo aluno na lista encadeada */
Lista *insere(Aluno aluno, Lista *lista) {
  // aloca espaco para um novo aluno
  Aluno *novo_aluno = (Aluno *)malloc(sizeof(Aluno));
  // aloca espaco para novo no
  Lista *novo_no = (Lista *)malloc(sizeof(Lista));

  // dados de aluno
  strcpy(novo_aluno->matricula, aluno.matricula);
  strcpy(novo_aluno->nome, aluno.nome);
  novo_aluno->notas[0] = aluno.notas[0];
  novo_aluno->notas[1] = aluno.notas[1];

  // dados do no (associa novo aluno ao novo no)
  novo_no->informacao = novo_aluno;
  novo_no->proximo = lista;
  return (novo_no);
}

/* mostra os elementos da lista*/
void mostra_lista(Lista *lista) {
  if (lista != NULL) {
    Lista *lista_aux;
    lista_aux = lista;
    while (lista_aux != NULL) {
      printf("[%s, %s] -> ", lista_aux->informacao->matricula,
             lista_aux->informacao->nome);
      // percorre a lista
      lista_aux = lista_aux->proximo;
    }
  } else {
    printf("Lista vazia! []\n");
  }
}

/* destroi a lista lista liberando todos os elementos da memoria */
void libera_elementos_lista(Lista *lista) {
  Lista *p = lista;

  while (p != NULL) {
    Lista *temp = p->proximo; /* guarda a referencia par a proximo elemento */
    free(p);                  /* libera memoria apontada por p */
    p = temp;
  }
}

int main() {
  Lista *minhalista;

  /* cria uma lista vazia */
  minhalista = NULL;

  printf("Testa lista de alunos\n");
  printf("Cria aluno1 \n");
  Aluno aluno1;
  strcpy(aluno1.matricula, "123456");
  strcpy(aluno1.nome, "Maria Joaquina");
  aluno1.notas[0] = 10;
  aluno1.notas[1] = 8;
  minhalista = insere(aluno1, minhalista);

  printf("Cria aluno2 \n");
  Aluno aluno2;
  strcpy(aluno2.matricula, "234212");
  strcpy(aluno2.nome, "Ana Clara");
  aluno2.notas[0] = 9;
  aluno2.notas[1] = 9;
  minhalista = insere(aluno2, minhalista);

  /* mostra elementos da lista */
  printf("Mostra os elementos da minhalista\n");
  mostra_lista(minhalista);
  printf("\n");
  printf("Libera os elementos da lista\n");
  libera_elementos_lista(minhalista);
  return 0;
}
