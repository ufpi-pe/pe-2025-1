# **Simulação no Tinkercad: Controle de Intensidade de LED com Potenciômetro**  

Neste projeto, vamos criar um circuito no **Tinkercad** onde um **potenciômetro** controla a intensidade de um **LED**. Quanto maior o valor do potenciômetro, mais brilhante o LED ficará, e quanto menor o valor, mais fraco ele ficará.  

---

## **🔧 Passo a Passo da Solução**  

### **📌 Componentes Necessários**  
- **Arduino Uno** (placa principal)  
- **1 LED** (qualquer cor)  
- **1 Resistor 220Ω** (para limitar a corrente do LED)  
- **1 Potenciômetro** (10kΩ recomendado)  
- **Fios de conexão**  

---

## **🔌 Montagem do Circuito no Tinkercad**  

### **1. Conectando o Potenciômetro**  
- Conecte **um terminal externo** do potenciômetro ao **5V** do Arduino.  
- Conecte o **outro terminal externo** ao **GND** do Arduino.  
- Conecte o **terminal central (wiper)** ao **pino analógico A0** do Arduino.  

### **2. Conectando o LED**  
- Conecte o **ânodo (perna longa)** do LED ao **pino PWM ~9** do Arduino (permite controle de intensidade).  
- Conecte o **cátodo (perna curta)** do LED a um **resistor 220Ω**.  
- Conecte o outro lado do resistor ao **GND** do Arduino.  

*(O pino ~9 é um pino PWM, essencial para controlar o brilho do LED.)*  

---

## **💻 Programa em C (Sketch do Arduino)**  

```cpp
// Define os pinos utilizados
const int potPin = A0;    // Pino do potenciômetro (entrada analógica)
const int ledPin = 9;     // Pino PWM do LED (saída)

// Variáveis para armazenar valores
int potValue = 0;         // Valor lido do potenciômetro (0-1023)
int brightness = 0;       // Valor de brilho do LED (0-255)

void setup() {
  // Configura o pino do LED como saída PWM
  pinMode(ledPin, OUTPUT);
  
  // Opcional: Inicia a comunicação serial para depuração
  Serial.begin(9600);
}

void loop() {
  // Lê o valor do potenciômetro (0 a 1023)
  potValue = analogRead(potPin);
  
  // Mapeia o valor do potenciômetro (0-1023) para o brilho do LED (0-255)
  brightness = map(potValue, 0, 1023, 0, 255);
  
  // Define o brilho do LED usando PWM
  analogWrite(ledPin, brightness);
  
  // (Opcional) Exibe os valores no Monitor Serial
  Serial.print("Potenciômetro: ");
  Serial.print(potValue);
  Serial.print(" | Brilho LED: ");
  Serial.println(brightness);
  
  // Pequeno atraso para estabilidade
  delay(10);
}
```

---

## **📝 Explicação do Código**  

1. **`const int potPin = A0;`**  
   - Define o pino analógico **A0** para ler o valor do potenciômetro.  

2. **`const int ledPin = 9;`**  
   - Define o pino **PWM ~9** para controlar o LED (só pinos com ~ suportam PWM).  

3. **`analogRead(potPin)`**  
   - Lê o valor do potenciômetro (varia de **0 a 1023**).  

4. **`map(potValue, 0, 1023, 0, 255)`**  
   - Converte o valor do potenciômetro (**0-1023**) para uma escala de brilho (**0-255**), que é o range do PWM.  

5. **`analogWrite(ledPin, brightness)`**  
   - Define o brilho do LED usando **PWM (Pulse Width Modulation)**.  

6. **`Serial.begin(9600)` e `Serial.print()`** *(Opcional)*  
   - Permite visualizar os valores no **Monitor Serial** (ferramenta útil para depuração).  

---

## **🎮 Testando no Tinkercad**  

1. **Clique em "Iniciar Simulação"**.  
2. **Gire o potenciômetro** e observe:  
   - Se girar para um lado, o LED fica **mais brilhante**.  
   - Se girar para o outro, o LED fica **mais fraco**.  
3. **(Opcional)** Abra o **Monitor Serial** (`Ctrl+Shift+M`) para ver os valores em tempo real.  

---

## **🔍 Dicas Extras**  

✅ **Se o LED não variar corretamente:**  
- Verifique se o potenciômetro está conectado nos pinos certos (**5V, GND, A0**).  
- Confirme se o LED está em um pino **PWM (~3, ~5, ~6, ~9, ~10, ~11)**.  

🎛️ **Experimente trocar o potenciômetro por um sensor de luz (LDR)** para um controle automático de brilho!  

🚀 **Quer ir além?**  
- Adicione **mais LEDs** e controle cada um com um potenciômetro diferente.  
- Use **`constrain(brightness, 0, 255)`** para garantir que o valor nunca ultrapasse 255.  

---

### **🎯 Conclusão**  
Agora você tem um **controle de intensidade de LED com potenciômetro** funcionando no Tinkercad! Esse é um ótimo exemplo de **entrada analógica + saída PWM**, muito útil para projetos de iluminação e dimmers.  
