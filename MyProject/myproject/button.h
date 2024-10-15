#ifndef __BUTTON__
#define __BUTTON__
#define BOUNCING_TIME 50

#include "Arduino.h"

struct Button {
    int pin;
    boolean pressed;
};

extern Button buttons[];
Button setupButton (int pin, bool pressed);
void initializeButtonBoard();
void pressedButton0();
void pressedButton1();
void pressedButton2();
void pressedButton3();

#endif
