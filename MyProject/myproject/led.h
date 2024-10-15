#ifndef __LED__
#define __LED__

#include "Arduino.h"

struct Led {
    int pin;
    int intensity;
    int pulseDelta;
};
extern Led leds[];
extern Led startLed;
void setIntensity(Led* led, int value);
void initializeLedBoard();
Led setupLed (int pin, int intensity, int pulseDelta);

#endif
