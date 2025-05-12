#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define FILE_NAME "alunos.bin"

struct aluno {
  char matricula[15];
  char nome[50];
};
typedef struct aluno Aluno;

void salvarAluno(Aluno aluno) {
  FILE *fp;
  fp = fopen(FILE_NAME, "ab");
  if (fp == NULL) {
    printf("Erro ao abrir o arquivo\n");
    exit(1);
  }
  fwrite(&aluno, sizeof(Aluno), 1, fp);
  fclose(fp);
}

Aluno recuperarAluno(char matricula[]) {
  Aluno aluno;
  FILE *fp;
  fp = fopen(FILE_NAME, "rb");
  if (fp == NULL) {
    printf("Erro ao abrir o arquivo\n");
    exit(1);
  }
  while (fread(&aluno, sizeof(Aluno), 1, fp) == 1) {
    if (strcmp(aluno.matricula, matricula) == 0) {
      fclose(fp);
      return aluno;
    }
  }
  printf("Aluno não encontrado\n");
  fclose(fp);
  exit(1);
}

int main() {
  FILE *file = fopen(FILE_NAME, "rb");
  Aluno aluno1;

  strcpy(aluno1.matricula, "444");
  strcpy(aluno1.nome, "Ana Clara Júlia");
  salvarAluno(aluno1);
  Aluno alunoRecuperado1 = recuperarAluno("444");
  printf("Matrícula: %s\n", alunoRecuperado1.matricula);
  printf("Nome: %s\n", alunoRecuperado1.nome);
  return 0;
}
