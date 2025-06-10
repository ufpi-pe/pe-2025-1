# **Aula de Introdução ao Arduino**  
**Tema:** Conceitos Básicos, Componentes e Primeiros Passos  

## **1. Objetivos da Aula**  
- Apresentar o Arduino e suas aplicações.  
- Conhecer os componentes básicos de um kit Arduino.  
- Introduzir a IDE do Arduino e sua estrutura de programação.  
- Realizar um primeiro projeto prático (piscar um LED).  

---  

## **2. O que é o Arduino?**  
- **Definição:** Plataforma de prototipagem eletrônica de hardware e software livre.  
- **Usos:** Automação, robótica, IoT (Internet das Coisas), projetos educacionais, etc.  
- **Vantagens:**  
  - Baixo custo.  
  - Grande comunidade de apoio.  
  - Facilidade de programação (baseada em C/C++).  

---  

## **3. Componentes Básicos**  
### **Hardware:**  
- **Placa Arduino (ex: Uno R3)**  
  - Microcontrolador (ATMega328P).  
  - Entradas/saídas digitais e analógicas.  
  - USB para comunicação e alimentação.  
- **Outros componentes comuns:**  
  - LEDs  
  - Resistores  
  - Potenciômetros  
  - Sensores (temperatura, movimento, luz)  
  - Protoboard (matriz de contatos)  
  - Jumpers (fios de conexão)  

### **Software:**  
- **IDE Arduino** (Integrated Development Environment):  
  - Onde se escreve, compila e envia o código para a placa.  
  - Linguagem baseada em C/C++, com funções simplificadas.  

---  

## **4. Estrutura Básica de um Código Arduino**  
```cpp
void setup() {
  // Configurações iniciais (executa uma vez)
  pinMode(13, OUTPUT); // Define o pino 13 como saída
}

void loop() {
  // Código principal (repete infinitamente)
  digitalWrite(13, HIGH); // Liga o LED
  delay(1000);            // Espera 1 segundo
  digitalWrite(13, LOW);  // Desliga o LED
  delay(1000);            // Espera 1 segundo
}
```
- **`setup()`:** Executado uma vez no início (configura pinos, sensores, etc.).  
- **`loop()`:** Repetido continuamente (controle principal do projeto).  

---  

## **5. Projeto Prático: Piscar um LED**  
### **Materiais Necessários:**  
- Arduino Uno  
- LED  
- Resistor (220Ω)  
- Jumpers  
- Protoboard  

### **Montagem do Circuito:**  
1. Conecte o **ânodo (+) do LED** ao **pino digital 13** do Arduino.  
2. Conecte o **cátodo (-) do LED** a um **resistor (220Ω)**.  
3. Ligue o resistor ao **GND (terra)** do Arduino.  

### **Upload do Código:**  
- Copie o código acima na IDE Arduino.  
- Conecte o Arduino ao computador via USB.  
- Selecione a placa (**Tools > Board > Arduino Uno**) e a porta (**Tools > Port**).  
- Clique em **Upload** (seta para a direita).  

### **Resultado Esperado:**  
- O LED conectado ao pino 13 deve piscar a cada 1 segundo.  

---  

## **6. Expansões e Próximos Passos**  
- **Modificar o tempo** do `delay()` para mudar a velocidade.  
- **Acionar múltiplos LEDs** usando outros pinos.  
- **Ler um botão** para controlar o LED.  
- **Explorar sensores** (ex: sensor de luz acendendo/apagando o LED).  

---  

## **7. Conclusão**  
- O Arduino é uma ferramenta poderosa para aprender eletrônica e programação.  
- Com poucos componentes, já é possível criar projetos interativos.  
- Próximas aulas podem abordar sensores, motores e comunicação serial.  

**Material de Apoio:**  
- [Site Oficial do Arduino](https://www.arduino.cc/)  
- [Tinkercad (simulação online)](https://www.tinkercad.com/)  

---  
**Pronto para a prática? Vamos começar!** 🚀  

Se precisar de ajustes ou mais detalhes, é só pedir!
