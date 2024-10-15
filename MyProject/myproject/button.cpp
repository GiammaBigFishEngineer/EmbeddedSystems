#include "Arduino.h"
#include "config.h"
#include "button.h"
#include "led.h"
#include <EnableInterrupt.h>

void (*button_handlers[4])() = { pressedButton0, pressedButton1, pressedButton2, pressedButton3 };
uint8_t inputPins[] = {BUT01_PIN, BUT02_PIN, BUT03_PIN, BUT04_PIN};
bool buttonPressed[] = { false, false, false, false };
int sequenceLen;
int sequence[10]; 
long lastButtonPressedTimeStamps[NUM_INPUT_POS];

Button buttons[] = {
    {BUT01_PIN, false},  // Bottone 1
    {BUT02_PIN, false},  // Bottone 2
    {BUT03_PIN, false},  // Bottone 3
    {BUT04_PIN, false}   // Bottone 4
};

Button setupButton (int pin, bool pressed) {
  Button b;
  b.pin = pin;
  b.pressed = pressed;
  return b;
}

void button_handler(int i){
  static unsigned long lastInterruptTime = 0;
  unsigned long interruptTime = millis();

  // Se sono passati più di 200 ms dall'ultimo interrupt, aggiorna lo stato
  if (interruptTime - lastInterruptTime > BOUNCING_TIME) {
  if (!buttons[i].pressed) {
      buttons[i].pressed = true;
    }
  }
  lastInterruptTime = interruptTime;
}

void initializeButtonBoard() {
  for (int i = 0; i < NUM_INPUT_POS; i++) {
    pinMode(buttons[i].pin, INPUT);  
    enableInterrupt(buttons[i].pin, button_handlers[i], CHANGE);       
  }  
}

void pressedButton0() { button_handler(0); }
void pressedButton1() { button_handler(1); }
void pressedButton2() { button_handler(2); }
void pressedButton3() { button_handler(3); }