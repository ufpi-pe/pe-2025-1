#include <stdio.h>
#include <stdlib.h> /* Para usar malloc() */

int main(void) {
  int *p;
  int n=1000;
  int i;

  /* Determina o valor de a em algum lugar */
  p = (int *)malloc(n * sizeof(int)); /* Aloca a numeros inteiros
                                         p pode agora ser tratado como um vetor
                                         com n posicoes */
  if (!p) {
    printf("** Erro: Memoria Insuficiente **");
    exit(0);
  }

  for (i = 0; i < n;  
       i++) { /* p pode ser tratado como um vetor com n posicoes */
    p[i] = i * i;
  }

  char opcao;
  printf("Digite s para SAIR: ");
  while (opcao != 's') {
    opcao = getchar();
  }
  return 0;
}
