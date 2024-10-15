#include "Arduino.h"
#include "config.h"
#include "led.h"

Led leds[] = {
    {LED01_PIN, 0, 0},  // Bottone 1
    {LED02_PIN, 0, 0},  // Bottone 2
    {LED03_PIN, 0, 0},  // Bottone 3
    {LED04_PIN, 0, 0}   // Bottone 4
};

Led startLed = {LED_START, 0, 0};

Led setupLed (int pin, int intensity, int pulseDelta) {
  Led l;
  l.pin = pin;
  l.intensity = intensity;
  l.pulseDelta = pulseDelta;
  return l;
}

void setIntensity(Led* led, int value) {
    if (led != nullptr) {  // Controllo se il puntatore non è nullo
        led->intensity = value;  // Imposta il valore di intensity
    }
}

void initializeLedBoard() {
  for (int i = 0; i < NUM_INPUT_POS; i++) {
    pinMode(leds[i].pin, OUTPUT);       
  } 
}