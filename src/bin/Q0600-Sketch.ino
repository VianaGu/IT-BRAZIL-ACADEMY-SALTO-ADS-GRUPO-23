/*
     CÓDIGO:  Carrinho via bluetooth
     AUTOR:   Grupo 23 
*/

// INCLUSÃO DE BIBLIOTECAS
#include "motor.h"
#include <SoftwareSerial.h>

// DEFINIÇÕES DE PINOS

#define pinRx 5
#define pinTx 6

// DEFINIÇÕES
#define LIGADO HIGH
#define DESLIGADO LOW

// INSTANCIANDO OBJETOS
SoftwareSerial btSerial(pinRx, pinTx); // RX, TX

// DECLARAÇÃO DE VARIÁVEIS
char comando;

void setup() {
  Serial.begin(9600);
  btSerial.begin(9600);

  pinMode(pin1, OUTPUT);
  pinMode(pin2, OUTPUT);
  pinMode(pin3, OUTPUT);
  pinMode(pin4, OUTPUT);

  Serial.println("Fim Setup");
  delay(2000);
}

void loop() {

  if (btSerial.available()) {
    comando = btSerial.read();
  }

  funcaoBasicaDeMovimento();
}

void funcoesBasicasDeMovimento(){
	
// LÓGICA DE COMANDOS 
  switch (comando) {
    case 'F': {
        moveFrente();
        break;
      }
    case 'I': {
        frenteDireita();
        break;
      }
    case 'G': {
        frenteEsquerda();
        break;
      }
    case 'R': {
        direita();
        break;
      }
    case 'L': {
        esquerda();
        break;
      }
    case 'B': {
        moveRe();
        break;
      }
    case 'H': {
        reEsquerda();
        break;
      }
    case 'J': {
        reDireita();
        break;
      }
    default: {
        parar();
        break;
      }
  }
}
// IMPLEMENTO DE FUNÇÕES
