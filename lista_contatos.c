#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PHONE_LENGTH 14
#define MAX_NAME_LENGTH 50
#define MAX_EMAIL_LENGTH 60

/* Definição da estrutura de telefone */
typedef struct telefone {
    char numero[MAX_PHONE_LENGTH];
    struct telefone *proximo;
} Telefone;

/* Definicao da estrutura contato */
typedef struct contato {
    char nome[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
    Telefone *telefones;
} Contato;

/* Definicao do node_contato */
typedef struct node {
    Contato *dados;
    struct node *proximo;
} node_contato;

/* Funções para liberar memória */
void libera_telefones(Telefone *lista) {
    while (lista != NULL) {
        Telefone *temp = lista;
        lista = lista->proximo;
        free(temp);
    }
}

void libera_contato(Contato *contato) {
    if (contato != NULL) {
        libera_telefones(contato->telefones);
        free(contato);
    }
}

void libera_lista_contatos(node_contato *lista) {
    while (lista != NULL) {
        node_contato *temp = lista;
        lista = lista->proximo;
        libera_contato(temp->dados);
        free(temp);
    }
}

/* Função para adicionar um telefone à lista de telefones do contato */
void adicionar_telefone(Contato *contato, char *numero) {
    if (contato == NULL || numero == NULL) return;

    Telefone *novo_telefone = (Telefone*)malloc(sizeof(Telefone));
    if (novo_telefone == NULL) {
        perror("Erro ao alocar memória para novo telefone");
        return;
    }
    
    strncpy(novo_telefone->numero, numero, MAX_PHONE_LENGTH - 1);
    novo_telefone->numero[MAX_PHONE_LENGTH - 1] = '\0';
    novo_telefone->proximo = contato->telefones;
    contato->telefones = novo_telefone;
}

/* insere uma novo contato na lista encadeada */
node_contato *insere_contato(Contato contato, node_contato *lista) {
    // aloca espaco para um novo contato
    Contato *novo_contato = (Contato *)malloc(sizeof(Contato));
    if (novo_contato == NULL) {
        perror("Erro ao alocar memória para novo contato");
        return lista;
    }

    // aloca espaco para novo no
    node_contato *novo_no = (node_contato *)malloc(sizeof(node_contato));
    if (novo_no == NULL) {
        perror("Erro ao alocar memória para novo nó");
        free(novo_contato);
        return lista;
    }

    // dados de contato
    strncpy(novo_contato->nome, contato.nome, MAX_NAME_LENGTH - 1);
    novo_contato->nome[MAX_NAME_LENGTH - 1] = '\0';
    
    strncpy(novo_contato->email, contato.email, MAX_EMAIL_LENGTH - 1);
    novo_contato->email[MAX_EMAIL_LENGTH - 1] = '\0';

    novo_contato->telefones = NULL;

    /* Insere telefone usando um loop */
    char telefone[MAX_PHONE_LENGTH];
    do {
        printf("Telefone (ou 0 para sair): ");
        if (fgets(telefone, MAX_PHONE_LENGTH, stdin) == NULL) break;
        telefone[strcspn(telefone, "\n")] = '\0'; // Remove newline
        
        if (strcmp(telefone, "0") != 0) {
            adicionar_telefone(novo_contato, telefone);
        } else {
            break;
        }
    } while (1);

    // dados do no (associa novo contato ao novo no)
    novo_no->dados = novo_contato;
    novo_no->proximo = lista;
    return novo_no;
}

void mostra_lista_contatos(node_contato *lista) {
    if (lista == NULL) {
        printf("Lista de contatos vazia.\n");
        return;
    }

    node_contato *lista_aux = lista;
    int contador = 1;
    
    printf("\n=== LISTA DE CONTATOS ===\n");
    while(lista_aux != NULL) {
        printf("\nContato #%d\n", contador++);
        printf("Nome: %s\n", lista_aux->dados->nome);
        printf("E-mail: %s\n", lista_aux->dados->email);
        
        if (lista_aux->dados->telefones != NULL) {
            printf("Telefones:\n");
            Telefone *tel_aux = lista_aux->dados->telefones;
            int tel_num = 1;
            while (tel_aux != NULL) {
                printf("  %d. %s\n", tel_num++, tel_aux->numero);
                tel_aux = tel_aux->proximo;
            }
        } else {
            printf("Nenhum telefone cadastrado.\n");
        }
        
        lista_aux = lista_aux->proximo;
    }
    printf("\n=== FIM DA LISTA ===\n");
}

void salva_contato_arquivo_binario(node_contato *contato, FILE *file) {
    if (contato == NULL || contato->dados == NULL || file == NULL) {
        fprintf(stderr, "Erro: Parametros invalidos para salvar contato\n");
        return;
    }

    /* Salva nome */
    int tamanho_nome = strlen(contato->dados->nome) + 1;
    if (fwrite(&tamanho_nome, sizeof(int), 1, file) != 1) {
        perror("Erro ao escrever tamanho do nome");
        return;
    }
    if (fwrite(contato->dados->nome, sizeof(char), tamanho_nome, file) != tamanho_nome) {
        perror("Erro ao escrever nome do contato");
        return;
    }

    /* Salva email */
    int tamanho_email = strlen(contato->dados->email) + 1;
    if (fwrite(&tamanho_email, sizeof(int), 1, file) != 1) {
        perror("Erro ao escrever tamanho do email");
        return;
    }
    if (fwrite(contato->dados->email, sizeof(char), tamanho_email, file) != tamanho_email) {
        perror("Erro ao escrever email do contato");
        return;
    }

    /* Salva telefones */
    int qtd_telefones = 0;
    Telefone *tel_aux = contato->dados->telefones;
    while (tel_aux != NULL) {
        qtd_telefones++;
        tel_aux = tel_aux->proximo;
    }

    if (fwrite(&qtd_telefones, sizeof(int), 1, file) != 1) {
        perror("Erro ao escrever quantidade de telefones");
        return;
    }

    tel_aux = contato->dados->telefones;
    while (tel_aux != NULL) {
        int tamanho_tel = strlen(tel_aux->numero) + 1;
        if (fwrite(&tamanho_tel, sizeof(int), 1, file) != 1) {
            perror("Erro ao escrever tamanho do telefone");
            return;
        }
        if (fwrite(tel_aux->numero, sizeof(char), tamanho_tel, file) != tamanho_tel) {
            perror("Erro ao escrever numero do telefone");
            return;
        }
        tel_aux = tel_aux->proximo;
    }
}

void salva_lista_contatos_arquivo_binario(node_contato *lista, const char *nome_arquivo) {
    if (lista == NULL || nome_arquivo == NULL) {
        fprintf(stderr, "Erro: Parametros invalidos para salvar lista\n");
        return;
    }

    FILE *file = fopen(nome_arquivo, "wb");
    if (file == NULL) {
        perror("Erro ao abrir arquivo para escrita");
        return;
    }

    node_contato *aux = lista;
    while (aux != NULL) {
        salva_contato_arquivo_binario(aux, file);
        aux = aux->proximo;
    }

    fclose(file);
    printf("Contatos salvos com sucesso no arquivo '%s'\n", nome_arquivo);
}

Contato *ler_contato_arquivo_binario(FILE *file) {
    if (file == NULL) {
        return NULL;
    }

    Contato *novo_contato = (Contato *)malloc(sizeof(Contato));
    if (novo_contato == NULL) {
        perror("Erro ao alocar memória para novo contato");
        return NULL;
    }

    /* Ler nome */
    int tamanho_nome;
    if (fread(&tamanho_nome, sizeof(int), 1, file) != 1) {
        if (feof(file)) {
            free(novo_contato);
            return NULL;
        }
        perror("Erro ao ler tamanho do nome");
        free(novo_contato);
        return NULL;
    }

    if (tamanho_nome <= 0 || tamanho_nome > MAX_NAME_LENGTH) {
        fprintf(stderr, "Tamanho do nome invalido: %d\n", tamanho_nome);
        free(novo_contato);
        return NULL;
    }

    if (fread(novo_contato->nome, sizeof(char), tamanho_nome, file) != tamanho_nome) {
        perror("Erro ao ler nome do contato");
        free(novo_contato);
        return NULL;
    }

    /* Ler email */
    int tamanho_email;
    if (fread(&tamanho_email, sizeof(int), 1, file) != 1) {
        perror("Erro ao ler tamanho do email");
        free(novo_contato);
        return NULL;
    }

    if (tamanho_email <= 0 || tamanho_email > MAX_EMAIL_LENGTH) {
        fprintf(stderr, "Tamanho do email invalido: %d\n", tamanho_email);
        free(novo_contato);
        return NULL;
    }

    if (fread(novo_contato->email, sizeof(char), tamanho_email, file) != tamanho_email) {
        perror("Erro ao ler email do contato");
        free(novo_contato);
        return NULL;
    }

    /* Ler telefones */
    int qtd_telefones;
    if (fread(&qtd_telefones, sizeof(int), 1, file) != 1) {
        perror("Erro ao ler quantidade de telefones");
        free(novo_contato);
        return NULL;
    }

    novo_contato->telefones = NULL;
    
    for (int i = 0; i < qtd_telefones; i++) {
        int tamanho_tel;
        if (fread(&tamanho_tel, sizeof(int), 1, file) != 1) {
            perror("Erro ao ler tamanho do telefone");
            libera_telefones(novo_contato->telefones);
            free(novo_contato);
            return NULL;
        }

        if (tamanho_tel <= 0 || tamanho_tel > MAX_PHONE_LENGTH) {
            fprintf(stderr, "Tamanho do telefone invalido: %d\n", tamanho_tel);
            libera_telefones(novo_contato->telefones);
            free(novo_contato);
            return NULL;
        }

        char telefone[MAX_PHONE_LENGTH];
        if (fread(telefone, sizeof(char), tamanho_tel, file) != tamanho_tel) {
            perror("Erro ao ler numero do telefone");
            libera_telefones(novo_contato->telefones);
            free(novo_contato);
            return NULL;
        }

        adicionar_telefone(novo_contato, telefone);
    }

    return novo_contato;
}

node_contato *ler_lista_contatos_arquivo_binario(const char *nome_arquivo) {
    if (nome_arquivo == NULL) {
        return NULL;
    }

    FILE *file = fopen(nome_arquivo, "rb");
    if (file == NULL) {
        perror("Erro ao abrir arquivo para leitura");
        return NULL;
    }

    node_contato *lista = NULL;
    Contato *contato;

    while ((contato = ler_contato_arquivo_binario(file)) != NULL) {
        node_contato *novo_no = (node_contato *)malloc(sizeof(node_contato));
        if (novo_no == NULL) {
            perror("Erro ao alocar memória para novo nó");
            libera_contato(contato);
            libera_lista_contatos(lista);
            fclose(file);
            return NULL;
        }

        novo_no->dados = contato;
        novo_no->proximo = lista;
        lista = novo_no;
    }

    if (!feof(file)) {
        perror("Erro ao ler arquivo");
        libera_lista_contatos(lista);
        fclose(file);
        return NULL;
    }

    fclose(file);
    return lista;
}

void menu() {
    printf("\n=== MENU ===\n");
    printf("1. Adicionar novo contato\n");
    printf("2. Listar todos os contatos\n");
    printf("3. Salvar contatos em arquivo\n");
    printf("4. Carregar contatos do arquivo\n");
    printf("5. Sair\n");
    printf("Escolha uma opcao: ");
}

int main() {
    node_contato *lista_contatos = NULL;
    const char *nome_arquivo = "contatos.bin";
    int opcao = 0;
    
    do {
        menu();
        scanf("%d", &opcao);
        while (getchar() != '\n'); // Limpa buffer do teclado
        
        switch(opcao) {
            case 1: {
                Contato novo;
                printf("\nNome: ");
                fgets(novo.nome, MAX_NAME_LENGTH, stdin);
                novo.nome[strcspn(novo.nome, "\n")] = '\0';
                
                printf("E-mail: ");
                fgets(novo.email, MAX_EMAIL_LENGTH, stdin);
                novo.email[strcspn(novo.email, "\n")] = '\0';
                
                printf("Telefones (digite 0 para parar):\n");
                lista_contatos = insere_contato(novo, lista_contatos);
                printf("Contato adicionado com sucesso!\n");
                break;
            }
            case 2:
                mostra_lista_contatos(lista_contatos);
                break;
            case 3:
                salva_lista_contatos_arquivo_binario(lista_contatos, nome_arquivo);
                break;
            case 4: {
                node_contato *nova_lista = ler_lista_contatos_arquivo_binario(nome_arquivo);
                if (nova_lista != NULL) {
                    libera_lista_contatos(lista_contatos);
                    lista_contatos = nova_lista;
                    printf("Contatos carregados com sucesso!\n");
                }
                break;
            }
            case 5:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while (opcao != 5);

    libera_lista_contatos(lista_contatos);
    return 0;
}
