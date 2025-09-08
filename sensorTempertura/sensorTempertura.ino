#include <math.h>
#include "AdafruitIO_WiFi.h"
#include "NewPing.h" // instalar bibiotacas *

//Configuração da rede WIFI
#define WIFI_SSID 
#define WIFI_PASS 

// Autenticação Adafruit IO
#define IO_USERNAME 
#define IO_KEY 

AdafruitIO_WiFi io(IO_USERNAME, IO_KEY, WIFI_SSID, WIFI_PASS);

#define pinNTC 34 // pino do sensor de temperatura
//#define pinLed 14 // pino do led

#define BUZZER_PIN 27
#define LED_ALARME 13
#define BOTAO_FISICO 26
#define TRIG_PIN 12
#define ECHO_PIN 14

//Configuração Ultrassonico
#define MAX_DISTANCE 100
NewPing sonar(TRIG_PIN, ECHO_PIN, MAX_DISTANCE);

// Controle de envio de dados 
float temp_atual = 0;
float temp_anterior = -1;

//Variavel / ponteiro para referenciar o feed temperatura
AdafruitIO_Feed *temperatura = io.feed("Temperatura");
AdafruitIO_Feed *ledFeed = io.feed("botaoled");


const float Rfixo = 10000.0; // Resistor do projeto 
const float Beta = 3950.0; 
const float R0 = 10000.0; // nominal do NTC
const float T0_kelvin = 298.15; // 25°C em Kelvin
const float Vcc = 3.3;

void setup() {
  pinMode(pinNTC, INPUT);
  //pinMode(pinLed, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(LED_ALARME, OUTPUT);
  pinMode(BOTAO_FISICO, INPUT);
  Serial.begin(115200);

  while(!Serial);

  Serial.print("Conectando ao adafruit IO");
  io.connect();

  while(io.status() < AIO_CONNECTED){
    Serial.print(".");
    delay(500);
  }

  Serial.println();
  Serial.println(io.statusText());

  // Configuração do callback, quando o feed receber(atualizar) um valor
  // temperatura -> onMessage(handleTemperatura);
  ledFeed->onMessage(handleBotaoLed);
  //registra a função de callback 
  // ela será chamada sempre que o feed receber um novo dado



  delay(2000);
}

void loop() {
  //Manter a coneção com o Adafruit IO ativa
  //io.run();
  //publicacao(); //chamada da função publish

  // Serial.print(F("Distancia lida: "));
  // Serial.println(sonar.ping_cm());
  delay(500);
}