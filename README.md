# Trena Digital com Sensor Ultrassônico + LEDs + Buzzer

Projeto desenvolvido em Arduino que mede a **distância de um objeto** usando um **sensor ultrassônico (HC-SR04)** e exibe o resultado através de **LEDs coloridos** e **um buzzer** — funcionando como um **sensor de estacionamento**.

---

## Objetivo

Criar uma **trena digital interativa**, que indica a distância do objeto usando luzes e sons:
- Quanto mais longe → LED azul acende (sem som)  
- Ao se aproximar → LED verde e bipes lentos  
- Quase perto → LED amarelo e bipes rápidos  
- Muito próximo → LED vermelho e som contínuo  

---

## Componentes Utilizados

| Componente | Quantidade | Função |
|-------------|-------------|--------|
| Arduino UNO | 1 | Microcontrolador principal |
| Sensor Ultrassônico HC-SR04 | 1 | Mede a distância até o objeto |
| LED Vermelho | 1 | Indica objeto muito próximo |
| LED Amarelo | 1 | Indica distância média |
| LED Verde | 1 | Indica objeto longe |
| LED Azul | 1 | Indica que não há objeto detectado |
| Buzzer | 1 | Emite som proporcional à distância |
| Resistores 220 Ω | 4 | Protegem os LEDs |
| Jumpers | — | Conexões entre os componentes |
| Protoboard | 1 | Montagem do circuito |

---

## Esquema de Ligação

| Componente | Pino do Arduino |
|-------------|-----------------|
| Trig (HC-SR04) | 13 |
| Echo (HC-SR04) | 12 |
| LED Azul | 8 |
| LED Verde | 7 |
| LED Amarelo | 6 |
| LED Vermelho | 5 |
| Buzzer | 4 |
| GND (todos os componentes) | GND do Arduino |

> Lembre-se de usar resistores entre o pino e o LED, e conectar **todos os GNDs** juntos.

---

## Código Principal

```cpp
#include <Ultrasonic.h>

int pino_Trig = 13;
int pino_Echo = 12;
Ultrasonic Sensor(pino_Trig, pino_Echo);

int distancia;

// LEDs
const int ledAzul = 8;
const int ledVerde = 7;
const int ledAmarelo = 6;
const int ledVermelho = 5;

// Buzzer
const int buzzer = 4;

void setup() {
  Serial.begin(9600);
  pinMode(ledAzul, OUTPUT);
  pinMode(ledVerde, OUTPUT);
  pinMode(ledAmarelo, OUTPUT);
  pinMode(ledVermelho, OUTPUT);
  pinMode(buzzer, OUTPUT);
}

void loop() {
  distancia = Sensor.read();
  Serial.print("Distancia: ");
  Serial.print(distancia);
  Serial.println(" cm");

  // Apaga todos os LEDs
  digitalWrite(ledAzul, LOW);
  digitalWrite(ledVerde, LOW);
  digitalWrite(ledAmarelo, LOW);
  digitalWrite(ledVermelho, LOW);
  digitalWrite(buzzer, LOW);

  if (distancia > 100) {
    digitalWrite(ledAzul, HIGH);
    delay(800);
  } 
  else if (distancia > 70) {
    digitalWrite(ledVerde, HIGH);
    digitalWrite(buzzer, HIGH);
    delay(100);
    digitalWrite(buzzer, LOW);
    delay(600);
  } 
  else if (distancia > 30) {
    digitalWrite(ledAmarelo, HIGH);
    digitalWrite(buzzer, HIGH);
    delay(150);
    digitalWrite(buzzer, LOW);
    delay(250);
  } 
  else if (distancia > 0) {
    digitalWrite(ledVermelho, HIGH);
    digitalWrite(buzzer, HIGH); // som contínuo
    delay(200);
  }
}
