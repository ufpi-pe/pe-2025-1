# Simulação no Tinkercad: LED com Botão Push-Release

Logo abaixo segue um passo a passo para você simular um circuito com Arduino que controla um LED através de um botão push/release no Tinkercad.

## Passo a Passo para a Simulação

### 1. Componentes Necessários:
- 1 Arduino Uno
- 1 LED (qualquer cor)
- 1 Resistor 220Ω
- 1 Botão push/release (pushbutton)
- 1 Resistor 10kΩ (para pull-down)
- Fios de conexão

### 2. Montagem do Circuito:

1. **Botão:**
   - Conecte um terminal do botão ao pino 5V do Arduino
   - Conecte o outro terminal do botão ao pino digital 2 do Arduino
   - Adicione um resistor 10kΩ entre o pino 2 e o GND (configuração pull-down)

2. **LED:**
   - Conecte o ânodo do LED (perna longa) ao pino digital 13 do Arduino
   - Conecte o cátodo do LED (perna curta) a um resistor 220Ω
   - Conecte o outro lado do resistor ao GND do Arduino

### 3. Programa em C (Sketch do Arduino):

```cpp
// Define os pinos
const int buttonPin = 2;     // pino do botão
const int ledPin =  13;      // pino do LED

// Variável para estado do botão
int buttonState = 0;

void setup() {
  // Inicializa o pino do LED como saída
  pinMode(ledPin, OUTPUT);
  // Inicializa o pino do botão como entrada
  pinMode(buttonPin, INPUT);
}

void loop() {
  // Lê o estado do botão
  buttonState = digitalRead(buttonPin);

  // Verifica se o botão está pressionado
  if (buttonState == HIGH) {
    // Liga o LED
    digitalWrite(ledPin, HIGH);
  } else {
    // Desliga o LED
    digitalWrite(ledPin, LOW);
  }
}
```

### 4. Explicação do Código:

1. **Definição dos pinos:** Especificamos quais pinos serão usados para o botão e para o LED.
2. **Setup():**
   - Configuramos o pino do LED como saída (`OUTPUT`)
   - Configuramos o pino do botão como entrada (`INPUT`)
3. **Loop():**
   - Lemos continuamente o estado do botão (`digitalRead`)
   - Se o botão estiver pressionado (HIGH), ligamos o LED
   - Se o botão não estiver pressionado (LOW), desligamos o LED

### 5. Testando no Tinkercad:

1. Clique no botão "Iniciar Simulação"
2. Pressione e segure o botão físico - o LED deve acender
3. Solte o botão - o LED deve apagar

## Dicas Extras:

1. Se quiser inverter a lógica (LED apagado quando pressionar), mude a condição para:
   ```cpp
   if (buttonState == LOW) {
     digitalWrite(ledPin, HIGH);
   } else {
     digitalWrite(ledPin, LOW);
   }
   ```

2. Para evitar "bounce" do botão (falsas leituras), você pode adicionar um pequeno delay após a leitura do botão.

3. No Tinkercad, você pode renomear os componentes para facilitar a identificação.
