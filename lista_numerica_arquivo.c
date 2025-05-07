#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    int info;
    struct node* proximo;
};

typedef struct node Lista;

/* declara e inicia a lista de inteiros */
Lista *lista_de_inteiros = NULL;

/* funcao que cria uma nova lista de inteiros */
Lista *cria_lista_vazia() {
    return NULL;
}

/* 
    testa se a lista esta vazia
    retorna 1 se vazia
    retorna 0 se nao vazia
*/
int testa_lista_vazia(Lista *lista) {
    return (lista == NULL);
}

/* insere um novo elemento no inicio da lista */
Lista *insere(Lista *lista, int valor) {
    Lista *novo = (Lista *)malloc(sizeof(Lista));
    novo->info = valor;
    novo->proximo = lista;
    return novo;
}

/* mostra os elementos da lista */
void mostra_elementos(Lista *lista) {
    Lista *p;

    if (testa_lista_vazia(lista)) {
        printf("Lista vazia.\n");
        return;
    }

    printf("Elementos da lista:\n");
    for (p = lista; p != NULL; p = p->proximo) {
        printf("%d\n", p->info);
    }
}

/*
    Busca um elemento na lista
    se elemento for encontrado, retorna o elemento
    se elemento nao for encontrado retorna NULL
*/
Lista *busca_na_lista(Lista *lista, int valor) {
    Lista *p;
    for (p = lista; p != NULL; p = p->proximo) {
        if (p->info == valor) {
            return p;
        }
    }
    return NULL;
}

/* salva os elementos da lista em um arquivo */
void salva_lista_arquivo(Lista *lista, const char *nome_arquivo) {
    FILE *arquivo = fopen(nome_arquivo, "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para escrita.\n");
        return;
    }

    Lista *p;
    for (p = lista; p != NULL; p = p->proximo) {
        fprintf(arquivo, "%d\n", p->info);
    }

    fclose(arquivo);
    printf("Lista salva no arquivo %s com sucesso.\n", nome_arquivo);
}

/* carrega os elementos de um arquivo para a lista */
Lista *carrega_lista_arquivo(const char *nome_arquivo) {
    FILE *arquivo = fopen(nome_arquivo, "r");
    if (arquivo == NULL) {
        return NULL;
    }

    Lista *lista = cria_lista_vazia();
    int valor;

    while (fscanf(arquivo, "%d", &valor) != EOF) {
        lista = insere(lista, valor);
    }

    fclose(arquivo);
    return lista;
}

/* destroi a lista liberando todos os elementos da memoria */
void libera_elementos_lista(Lista *lista) {
    Lista *p = lista;

    while (p != NULL) {
        Lista *temp = p->proximo; /* guarda a referencia para o proximo elemento */
        free(p); /* libera memoria apontada por p */
        p = temp;
    }
}

/* exibe o menu de opcoes */
void exibe_menu() {
    printf("\nMenu de Opcoes:\n");
    printf("1 - Inserir numero\n");
    printf("2 - Buscar numero\n");
    printf("3 - Mostrar lista\n");
    printf("4 - Salvar lista em arquivo\n");
    printf("5 - Sair\n");
    printf("Escolha uma opcao: ");
}

int main() {
    const char *nome_arquivo = "minha_lista.txt";
    
    /* Verifica se o arquivo existe e carrega os dados */
    lista_de_inteiros = carrega_lista_arquivo(nome_arquivo);
    if (lista_de_inteiros != NULL) {
        printf("Dados carregados do arquivo %s.\n", nome_arquivo);
    }

    int opcao, valor;
    Lista *resultado_busca;

    do {
        exibe_menu();
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o numero a ser inserido: ");
                scanf("%d", &valor);
                lista_de_inteiros = insere(lista_de_inteiros, valor);
                printf("Numero %d inserido na lista.\n", valor);
                break;
                
            case 2:
                printf("Digite o numero a ser buscado: ");
                scanf("%d", &valor);
                resultado_busca = busca_na_lista(lista_de_inteiros, valor);
                if (resultado_busca != NULL) {
                    printf("Numero %d encontrado na lista.\n", valor);
                } else {
                    printf("Numero %d nao encontrado na lista.\n", valor);
                }
                break;
                
            case 3:
                mostra_elementos(lista_de_inteiros);
                break;
                
            case 4:
                salva_lista_arquivo(lista_de_inteiros, nome_arquivo);
                break;
                
            case 5:
                printf("Saindo do programa...\n");
                break;
                
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
    } while (opcao != 5);

    /* Libera a memoria alocada para a lista antes de sair */
    libera_elementos_lista(lista_de_inteiros);

    return 0;
}
