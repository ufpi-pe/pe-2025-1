#include <stdio.h>
#include <stdlib.h>

int main() {
    int tamanho;
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tamanho);

    int *vetor = (int*) malloc(tamanho * sizeof(int)); // Alocação dinâmica
  
    if (vetor == NULL) {
        printf("Erro na alocação de memória!\n");
        return 1;
    }

    for (int i = 0; i < tamanho; i++) {
        vetor[i] = i + 1;
    }

    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }

    free(vetor); // Libera memória
    return 0;
}
