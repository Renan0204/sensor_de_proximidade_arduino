#include <Ultrasonic.h>

int pino_Trig = 13;
int pino_Echo = 12;

Ultrasonic Sensor(pino_Trig, pino_Echo);

int distancia;

const int ledAzul = 8;
const int ledVerde = 7;
const int ledAmarelo = 6;
const int ledVermelho = 5;
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

  digitalWrite(ledAzul, LOW);
  digitalWrite(ledVerde, LOW);
  digitalWrite(ledAmarelo, LOW);
  digitalWrite(ledVermelho, LOW);
  digitalWrite(buzzer, LOW);

  if (distancia > 50) {
    digitalWrite(ledAzul, HIGH);
    delay(800);
  } 
  else if (distancia > 30) {
    digitalWrite(ledVerde, HIGH);
    digitalWrite(buzzer, HIGH);
    delay(100);
    digitalWrite(buzzer, LOW);
    delay(600);
  } 
  else if (distancia > 15) {
    digitalWrite(ledAmarelo, HIGH);
    digitalWrite(buzzer, HIGH);
    delay(150);
    digitalWrite(buzzer, LOW);
    delay(250);
  } 
  else if (distancia > 0) {
    digitalWrite(ledVermelho, HIGH);
    digitalWrite(buzzer, HIGH);
    delay(200);
  }

}
