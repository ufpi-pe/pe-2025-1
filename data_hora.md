### **Manipulação de Data e Hora em C**

#### **Biblioteca `<time.h>`**

A biblioteca `<time.h>` é a principal ferramenta em C para trabalhar com datas e horas. Ela oferece funções e estruturas para criar, modificar e comparar datas e horas.

---

### **Estruturas Principais**

1. **`tm`:** Estrutura que representa uma data e hora.
   ```c
   struct tm {
       int tm_sec;   // Segundos (0-59)
       int tm_min;   // Minutos (0-59)
       int tm_hour;  // Horas (0-23)
       int tm_mday;  // Dia do mês (1-31)
       int tm_mon;   // Mês (0-11, onde 0 = Janeiro)
       int tm_year;  // Ano (ano atual - 1900)
       int tm_wday;  // Dia da semana (0-6, onde 0 = Domingo)
       int tm_yday;  // Dia do ano (0-365)
       int tm_isdst; // Flag de horário de verão
   };
   ```

2. **`time_t`:** Tipo de dado que armazena o tempo em segundos desde a "época" (1 de Janeiro de 1970).

---

### **Funcionalidades Básicas**

#### **1. Obtendo a Data e Hora Atual**

```c
#include <stdio.h>
#include <time.h>

int main() {
    time_t agora;
    struct tm *info_tempo;

    // Obtém o tempo atual
    time(&agora);

    // Converte para a estrutura tm
    info_tempo = localtime(&agora);

    // Exibe a data e hora
    printf("Data e hora atual: %s", asctime(info_tempo));

    return 0;
}
```

#### **2. Criando uma Data Específica**

```c
#include <stdio.h>
#include <time.h>

int main() {
    struct tm data_nascimento = {0}; // Inicializa com zeros

    // Define a data de nascimento (15 de Janeiro de 1990)
    data_nascimento.tm_year = 1990 - 1900; // Ano - 1900
    data_nascimento.tm_mon = 0;            // Janeiro (0-11)
    data_nascimento.tm_mday = 15;          // Dia 15

    // Converte para time_t
    time_t tempo_nascimento = mktime(&data_nascimento);

    // Exibe a data
    printf("Data de nascimento: %s", asctime(&data_nascimento));

    return 0;
}
```

#### **3. Formatando Datas e Horas**

```c
#include <stdio.h>
#include <time.h>

int main() {
    time_t agora;
    struct tm *info_tempo;
    char buffer[80];

    // Obtém o tempo atual
    time(&agora);
    info_tempo = localtime(&agora);

    // Formata a data e hora
    strftime(buffer, sizeof(buffer), "%d/%m/%Y %H:%M:%S", info_tempo);
    printf("Data e hora formatada: %s\n", buffer);

    return 0;
}
```

#### **4. Operações Aritméticas com Datas**

```c
#include <stdio.h>
#include <time.h>

int main() {
    time_t agora;
    struct tm *info_tempo;

    // Obtém o tempo atual
    time(&agora);
    info_tempo = localtime(&agora);

    // Adiciona 10 dias
    info_tempo->tm_mday += 10;
    mktime(info_tempo); // Normaliza a estrutura tm

    // Exibe a nova data
    printf("Data após 10 dias: %s", asctime(info_tempo));

    return 0;
}
```

#### **5. Comparando Datas**

```c
#include <stdio.h>
#include <time.h>

int main() {
    struct tm data1 = {0};
    struct tm data2 = {0};

    // Define a primeira data (15/01/1990)
    data1.tm_year = 1990 - 1900;
    data1.tm_mon = 0;
    data1.tm_mday = 15;

    // Define a segunda data (20/03/2024)
    data2.tm_year = 2024 - 1900;
    data2.tm_mon = 2;
    data2.tm_mday = 20;

    // Converte para time_t
    time_t tempo1 = mktime(&data1);
    time_t tempo2 = mktime(&data2);

    // Compara as datas
    if (tempo1 > tempo2) {
        printf("Data1 é mais recente que Data2.\n");
    } else if (tempo1 < tempo2) {
        printf("Data1 é mais antiga que Data2.\n");
    } else {
        printf("As datas são iguais.\n");
    }

    return 0;
}
```

#### **6. Extraindo Componentes da Data**

```c
#include <stdio.h>
#include <time.h>

int main() {
    time_t agora;
    struct tm *info_tempo;

    // Obtém o tempo atual
    time(&agora);
    info_tempo = localtime(&agora);

    // Extrai componentes
    int ano = info_tempo->tm_year + 1900;
    int mes = info_tempo->tm_mon + 1;
    int dia = info_tempo->tm_mday;

    // Exibe os componentes
    printf("Ano: %d\n", ano);
    printf("Mês: %d\n", mes);
    printf("Dia: %d\n", dia);

    return 0;
}
```

#### **7. Dia da Semana**

```c
#include <stdio.h>
#include <time.h>

// Função para mostrar o dia da semana
const char* dia_da_semana(int dia_semana) {
    switch (dia_semana) {
        case 0: return "Domingo";
        case 1: return "Segunda-feira";
        case 2: return "Terça-feira";
        case 3: return "Quarta-feira";
        case 4: return "Quinta-feira";
        case 5: return "Sexta-feira";
        case 6: return "Sábado";
        default: return "Desconhecido";
    }
}

int main() {
    time_t agora;
    struct tm *info_tempo;

    // Obtém o tempo atual
    time(&agora);
    info_tempo = localtime(&agora);

    // Exibe o dia da semana
    printf("Hoje é %s.\n", dia_da_semana(info_tempo->tm_wday));

    return 0;
}
```

---

### **Funcionalidades Avançadas**

#### **1. Calculando a Idade de uma Pessoa**

```c
#include <stdio.h>
#include <time.h>

int calcular_idade(int ano_nascimento) {
    time_t agora;
    struct tm *info_tempo;

    // Obtém o tempo atual
    time(&agora);
    info_tempo = localtime(&agora);

    // Calcula a idade
    int ano_atual = info_tempo->tm_year + 1900;
    return ano_atual - ano_nascimento;
}

int main() {
    int ano_nascimento = 1990;
    int idade = calcular_idade(ano_nascimento);
    printf("Idade: %d anos\n", idade);

    return 0;
}
```

#### **2. Formatando Datas para Relatórios**

```c
#include <stdio.h>
#include <time.h>

int main() {
    time_t agora;
    struct tm *info_tempo;
    char buffer[80];

    // Obtém o tempo atual
    time(&agora);
    info_tempo = localtime(&agora);

    // Formata a data e hora
    strftime(buffer, sizeof(buffer), "%A, %d de %B de %Y - %H:%M:%S", info_tempo);
    printf("Data e hora formatada: %s\n", buffer);

    return 0;
}
```

---

### **Resumo**

- Em C, a manipulação de datas e horas é feita com a biblioteca `<time.h>`.
- A estrutura `tm` é usada para representar datas e horas.
- Funções como `time`, `localtime`, `mktime`, `strftime` e `asctime` são essenciais para trabalhar com tempo.
- É possível realizar operações como formatação, comparação e cálculos de diferenças entre datas.
