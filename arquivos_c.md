# Trabalhando com Arquivos em C

## Introdução

Vamos explorar como manipular arquivos em C, desde a abertura até a leitura e escrita de dados. Arquivos são essenciais para armazenar informações de forma persistente e serão abordados através de exemplos práticos.

---

## 1. Conceitos Básicos
- **O que é um arquivo em C?**  
  Um arquivo é uma sequência de bytes armazenada em um meio permanente, como um disco. Ele permite que dados persistam entre execuções de programas.

- **Biblioteca padrão**  
  Funções como `fopen()`, `fread()`, `fwrite()` e `fclose()` são usadas para manipular arquivos, tratando-os como matrizes de bytes.

---

## 2. Estrutura `FILE`
- **Declaração**  
  Em C, arquivos são manipulados através do ponteiro para a estrutura `FILE`, definida em `stdio.h`:
  ```c
  FILE *fp;  // Ponteiro para um arquivo
  ```

---

## 3. Abrindo e Fechando Arquivos
- **Abertura**  
  A função `fopen()` abre um arquivo e retorna um ponteiro para ele. Se houver erro, retorna `NULL`.
  ```c
  FILE *file = fopen("arquivo.txt", "r");  // Modo leitura ("r")
  if (file == NULL) {
      printf("Erro ao abrir o arquivo!\n");
      exit(1);  // Encerra o programa em caso de erro
  }
  ```

- **Fechamento**  
  Sempre feche o arquivo com `fclose()` para liberar recursos e garantir que os dados sejam salvos:
  ```c
  fclose(file);
  ```

---

## 4. Modos de Abertura
Principais modos para arquivos texto:
- `"r"`: Leitura (arquivo deve existir).
- `"w"`: Escrita (cria ou sobrescreve o arquivo).
- `"a"`: Append (adiciona dados ao final do arquivo).

Exemplo para arquivos binários:
- `"rb"`, `"wb"`, `"ab"`.

---

## 5. Leitura e Escrita
### Caractere a Caractere
- **`getc()`**: Lê um caractere.
  ```c
  char ch = getc(file);
  ```
- **`putc()`**: Escreve um caractere.
  ```c
  putc('A', file);
  ```

### Linha a Linha
- **`fgets()`**: Lê uma linha.
  ```c
  char buffer[100];
  fgets(buffer, 100, file);
  ```
- **`fputs()`**: Escreve uma linha.
  ```c
  fputs("Texto\n", file);
  ```

### Blocos de Dados
- **`fread()`**: Lê blocos de dados.
  ```c
  int dados[10];
  fread(dados, sizeof(int), 10, file);
  ```
- **`fwrite()`**: Escreve blocos de dados.
  ```c
  int valores[] = {1, 2, 3};
  fwrite(valores, sizeof(int), 3, file);
  ```

---

---

## 6. Função `exit()`
- **Propósito**: Encerra o programa imediatamente.
- **Uso típico**: Em erros críticos, como falha ao abrir arquivos.
  ```c
  if (file == NULL) {
      printf("Erro!\n");
      exit(1);  // Código de retorno 1 indica erro
  }
  ```

---

# Exemplo de Manipulação de Arquivos em C

Programa que demonstra as operações básicas com arquivos em C:

```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *arquivo;
    char nome_arquivo[] = "exemplo.txt";
    char conteudo_escrita[] = "Este é um exemplo de conteúdo para o arquivo.\nLinha 2 do arquivo.\n";
    char buffer[100]; // Buffer para leitura

    // 1. Criar e escrever no arquivo
    arquivo = fopen(nome_arquivo, "w"); // Modo escrita ("w" cria ou sobrescreve)
    
    if (arquivo == NULL) {
        printf("Erro ao criar o arquivo!\n");
        exit(1);
    }

    // Escreve a string no arquivo
    fputs(conteudo_escrita, arquivo);
    printf("Conteúdo escrito no arquivo com sucesso!\n\n");
    
    fclose(arquivo); // Fecha o arquivo após escrita

    // 2. Ler o conteúdo do arquivo
    arquivo = fopen(nome_arquivo, "r"); // Modo leitura ("r")
    
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para leitura!\n");
        exit(1);
    }

    printf("Conteúdo do arquivo '%s':\n", nome_arquivo);
    printf("--------------------------------\n");
    
    // Lê e exibe o conteúdo linha por linha
    while (fgets(buffer, sizeof(buffer), arquivo) {
        printf("%s", buffer);
    }
    printf("--------------------------------\n");
    
    fclose(arquivo); // Fecha o arquivo após leitura

    return 0;
}
```

## Explicação do Código:

1. **Escrita no Arquivo**:
   - Abrimos o arquivo no modo `"w"` (escrita)
   - Usamos `fputs()` para escrever uma string no arquivo
   - Fechamos o arquivo com `fclose()`

2. **Leitura do Arquivo**:
   - Reabrimos o mesmo arquivo no modo `"r"` (leitura)
   - Usamos `fgets()` para ler o conteúdo linha por linha
   - Imprimimos cada linha no terminal
   - Fechamos o arquivo novamente

## Como Executar:

1. Copie este código para um arquivo `.c` (por exemplo, `arquivos.c`)
2. Compile com: `gcc arquivos.c -o arquivos`
3. Execute com: `./arquivos`

## Saída Esperada:

```
Conteúdo escrito no arquivo com sucesso!

Conteúdo do arquivo 'exemplo.txt':
--------------------------------
Este é um exemplo de conteúdo para o arquivo.
Linha 2 do arquivo.
--------------------------------
```

## Observações:

- O arquivo `exemplo.txt` será criado no mesmo diretório do programa
- Se o arquivo já existir, seu conteúdo será substituído (devido ao modo `"w"`)
- Para adicionar conteúdo sem substituir, use o modo `"a"` (append)

# Exemplo de programa que copia o conteúdo de um arquivo

Programa que copia o conteúdo de um arquivo de origem para um arquivo de destino. 

```c
#include <stdio.h>
#include <stdlib.h>
#define BUFSIZE 100

int main() {
    FILE *infile, *outfile;
    char buffer[BUFSIZE];
    size_t bytes_read;

    infile = fopen("origem.txt", "r");
    outfile = fopen("destino.txt", "w");

    if (infile == NULL || outfile == NULL) {
        printf("Erro ao abrir arquivos!\n");
        exit(1);
    }

    while ((bytes_read = fread(buffer, 1, BUFSIZE, infile)) > 0) {
        fwrite(buffer, 1, bytes_read, outfile);
    }

    fclose(infile);
    fclose(outfile);
    return 0;
}
```


## Inclusões e Definição
```c
#include <stdio.h>
#include <stdlib.h>
#define BUFSIZE 100
```
- `stdio.h`: Biblioteca padrão para operações de entrada/saída
- `stdlib.h`: Biblioteca para funções gerais como `exit()`
- `BUFSIZE 100`: Define o tamanho do buffer como 100 bytes

## Variáveis
```c
FILE *infile, *outfile;
char buffer[BUFSIZE];
size_t bytes_read;
```
- `infile`: Ponteiro para o arquivo de origem
- `outfile`: Ponteiro para o arquivo de destino
- `buffer`: Array de caracteres para armazenar dados lidos
- `bytes_read`: Variável para armazenar quantos bytes foram lidos

## Abertura dos Arquivos
```c
infile = fopen("origem.txt", "r");
outfile = fopen("destino.txt", "w");
```
- Abre "origem.txt" em modo leitura ("r")
- Abre "destino.txt" em modo escrita ("w"), criando o arquivo se não existir ou truncando se existir

## Verificação de Erros
```c
if (infile == NULL || outfile == NULL) {
    printf("Erro ao abrir arquivos!\n");
    exit(1);
}
```
- Se qualquer um dos arquivos falhar ao abrir, imprime mensagem de erro e termina o programa com código 1

## Loop de Cópia
```c
    while ((bytes_read = fread(buffer, 1, BUFSIZE, infile)) > 0) {
        fwrite(buffer, 1, bytes_read, outfile);
    }
```
- `fread()` lê até `BUFSIZE` bytes (100) do arquivo de origem para o buffer
- `bytes_read` recebe o número de bytes realmente lidos
- `fwrite()` escreve os bytes lidos no arquivo de destino
- O loop continua até que `fread()` retorne 0 (fim do arquivo)

## Fechamento dos Arquivos
```c
fclose(infile);
fclose(outfile);
```
- Libera os recursos dos arquivos abertos

## Conclusão
- Arquivos em C são essenciais para persistência de dados.
- Funções como `fopen()`, `fclose()`, `fread()` e `fwrite()` simplificam a manipulação.
- Sempre verifique erros ao abrir arquivos e feche-os após o uso.
