#include "config.h"
#include "button.h"
#include "led.h" 
#include "logic.h"

void setup() {
  Serial.begin(9600);
  initializeButtonBoard();
  initializeLedBoard();
}

void loop() {
  if (buttons[3].pressed) {
    digitalWrite(leds[0].pin, HIGH);
  } else {
    digitalWrite(leds[0].pin, LOW);
  }

  if (buttons[2].pressed) {
    digitalWrite(leds[1].pin, HIGH);
  } else {
    digitalWrite(leds[1].pin, LOW);
  }
}