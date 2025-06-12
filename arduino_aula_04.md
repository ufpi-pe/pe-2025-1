# **Simulação no Tinkercad: Controle de Cores de um LED RGB com 3 Potenciômetros**  

Neste projeto, vamos criar um circuito no **Tinkercad** onde **três potenciômetros** controlam as cores **R (Red), G (Green) e B (Blue)** de um **LED RGB**. Cada potenciômetro ajusta uma cor, permitindo criar **qualquer cor no espectro RGB**.  

---

## **🔧 Passo a Passo da Solução**  

### **📌 Componentes Necessários**  
- **Arduino Uno**  
- **1 LED RGB (cátodo comum ou ânodo comum)** *(usaremos **cátodo comum** neste exemplo)*  
- **3 Resistores 220Ω** *(um para cada cor do LED RGB)*  
- **3 Potenciômetros (10kΩ cada)** *(um para R, outro para G e outro para B)*  
- **Fios de conexão**  

---

## **🔌 Montagem do Circuito no Tinkercad**  

### **1. Conectando os Potenciômetros**  
- **Potenciômetro A (Vermelho - R):**  
  - Terminal externo 1 → **5V**  
  - Terminal externo 2 → **GND**  
  - Terminal central (wiper) → **A0** (entrada analógica)  

- **Potenciômetro B (Verde - G):**  
  - Terminal externo 1 → **5V**  
  - Terminal externo 2 → **GND**  
  - Terminal central → **A1**  

- **Potenciômetro C (Azul - B):**  
  - Terminal externo 1 → **5V**  
  - Terminal externo 2 → **GND**  
  - Terminal central → **A2**  

*(Todos os potenciômetros estão em configuração de divisor de tensão, fornecendo valores de 0 a 1023 ao Arduino.)*  

### **2. Conectando o LED RGB (Cátodo Comum)**  
- **Ânodo do Vermelho (R)** → **Pino PWM ~9** (com resistor 220Ω)  
- **Ânodo do Verde (G)** → **Pino PWM ~10** (com resistor 220Ω)  
- **Ânodo do Azul (B)** → **Pino PWM ~11** (com resistor 220Ω)  
- **Cátodo Comum (perna longa ou marcada)** → **GND**  

*(Se o seu LED RGB for **ânodo comum**, conecte o ânodo ao **5V** e os cátodos aos pinos PWM com resistores.)*  

---

## **💻 Programa em C (Sketch do Arduino)**  

```cpp
// Define os pinos dos potenciômetros
const int potR = A0;   // Potenciômetro Vermelho (Red)
const int potG = A1;   // Potenciômetro Verde (Green)
const int potB = A2;   // Potenciômetro Azul (Blue)

// Define os pinos do LED RGB (PWM)
const int ledR = 9;    // Pino do Vermelho (Red)
const int ledG = 10;   // Pino do Verde (Green)
const int ledB = 11;   // Pino do Azul (Blue)

// Variáveis para armazenar os valores lidos
int valorR = 0;
int valorG = 0;
int valorB = 0;

// Variáveis para os valores de brilho (0-255)
int brilhoR = 0;
int brilhoG = 0;
int brilhoB = 0;

void setup() {
  // Configura os pinos do LED como saída PWM
  pinMode(ledR, OUTPUT);
  pinMode(ledG, OUTPUT);
  pinMode(ledB, OUTPUT);
  
  // Inicia a comunicação serial (opcional para depuração)
  Serial.begin(9600);
}

void loop() {
  // Lê os valores dos potenciômetros (0-1023)
  valorR = analogRead(potR);
  valorG = analogRead(potG);
  valorB = analogRead(potB);
  
  // Converte os valores (0-1023) para brilho (0-255)
  brilhoR = map(valorR, 0, 1023, 0, 255);
  brilhoG = map(valorG, 0, 1023, 0, 255);
  brilhoB = map(valorB, 0, 1023, 0, 255);
  
  // Define as cores do LED RGB usando PWM
  analogWrite(ledR, brilhoR);
  analogWrite(ledG, brilhoG);
  analogWrite(ledB, brilhoB);
  
  // (Opcional) Exibe os valores no Monitor Serial
  Serial.print("R: ");
  Serial.print(brilhoR);
  Serial.print(" | G: ");
  Serial.print(brilhoG);
  Serial.print(" | B: ");
  Serial.println(brilhoB);
  
  // Pequeno atraso para estabilidade
  delay(50);
}
```

---

## **📝 Explicação do Código**  

1. **Definição dos pinos:**  
   - `potR`, `potG`, `potB` → Entradas analógicas dos potenciômetros.  
   - `ledR`, `ledG`, `ledB` → Saídas PWM para o LED RGB.  

2. **Leitura dos potenciômetros (`analogRead`)**  
   - Lê valores entre **0 e 1023** para cada cor.  

3. **Conversão para escala PWM (`map`)**  
   - Converte **0-1023 → 0-255** (faixa do PWM).  

4. **Aplicação do brilho (`analogWrite`)**  
   - Define a intensidade de cada cor no LED RGB.  

5. **Monitor Serial (opcional)**  
   - Mostra os valores de R, G e B em tempo real.  

---

## **🎮 Testando no Tinkercad**  

1. **Clique em "Iniciar Simulação"**.  
2. **Gire os potenciômetros** e observe:  
   - **Potenciômetro A (A0)** → Controla o **Vermelho (R)**.  
   - **Potenciômetro B (A1)** → Controla o **Verde (G)**.  
   - **Potenciômetro C (A2)** → Controla o **Azul (B)**.  
3. **Misture as cores** girando os potenciômetros para criar **roxo, amarelo, ciano, branco, etc.**  

*(Exemplo: Máximo de R + Máximo de G = Amarelo | Máximo de R + Máximo de B = Roxo)*  

---

## **🔍 Dicas Extras**  

✅ **Se o LED não acender corretamente:**  
- Verifique se o LED RGB é **cátodo comum** ou **ânodo comum** e ajuste as conexões.  
- Confira se os resistores (220Ω) estão conectados corretamente.  

🎨 **Experimente:**  
- Troque os potenciômetros por **sensores de luz (LDR)** para criar um LED que muda com a luminosidade.  
- Use **`constrain()`** para garantir que os valores PWM nunca ultrapassem 255.  

🚀 **Desafio avançado:**  
- Substitua os potenciômetros por **um joystick analógico** para controlar cores em 2 eixos (X e Y).  

---

### **🎯 Conclusão**  
Agora você tem um **controle completo de cores RGB** usando potenciômetros no Tinkercad! Esse projeto é ótimo para entender:  
✔ **Entradas analógicas** (potenciômetros)  
✔ **Saídas PWM** (controle de brilho)  
✔ **LED RGB** (mistura de cores)  
