# Explicação do Código em C

Este código implementa um sistema simples para armazenar e recuperar registros de alunos em um arquivo binário. Vamos analisar cada parte:

## Estruturas e Definições
```c
#define FILE_NAME "alunos.bin"

struct aluno {
  char matricula[15];
  char nome[50];
};
typedef struct aluno Aluno;
```
- Define o nome do arquivo onde os dados serão armazenados
- Cria uma estrutura `aluno` com dois campos: matrícula (15 caracteres) e nome (50 caracteres)
- Define um tipo `Aluno` para facilitar o uso da estrutura

## Função salvarAluno
```c
void salvarAluno(Aluno aluno) {
  FILE *fp;
  fp = fopen(FILE_NAME, "ab");  // Abre em modo append binário
  if (fp == NULL) {
    printf("Erro ao abrir o arquivo\n");
    exit(1);
  }
  fwrite(&aluno, sizeof(Aluno), 1, fp);  // Escreve o aluno no arquivo
  fclose(fp);
}
```
- Abre o arquivo em modo append binário (adiciona ao final)
- Se houver erro na abertura, exibe mensagem e termina o programa
- Escreve o registro do aluno no arquivo
- Fecha o arquivo

## Função recuperarAluno
```c
Aluno recuperarAluno(char matricula[]) {
  Aluno aluno;
  FILE *fp;
  fp = fopen(FILE_NAME, "rb");  // Abre em modo leitura binária
  if (fp == NULL) {
    printf("Erro ao abrir o arquivo\n");
    exit(1);
  }
  while (fread(&aluno, sizeof(Aluno), 1, fp) == 1) {  // Lê cada aluno
    if (strcmp(aluno.matricula, matricula) == 0) {    // Compara matrículas
      fclose(fp);
      return aluno;  // Retorna o aluno encontrado
    }
  }
  printf("Aluno não encontrado\n");
  fclose(fp);
  exit(1);
}
```
- Abre o arquivo em modo leitura binária
- Lê cada registro de aluno sequencialmente
- Compara a matrícula do aluno lido com a matrícula buscada
- Se encontrar, retorna o registro do aluno
- Se não encontrar após ler todos, exibe mensagem e termina o programa

## Função main
```c
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
```
- Cria um aluno com matrícula "444" e nome "Ana Clara Júlia"
- Salva este aluno no arquivo binário
- Recupera o aluno com matrícula "444" do arquivo
- Imprime os dados do aluno recuperado

## Funcionamento Geral
O programa demonstra um CRUD básico (Create e Read) para registros de alunos em um arquivo binário. Os dados são persistidos em disco, permitindo que sejam recuperados mesmo após o programa ser encerrado.
