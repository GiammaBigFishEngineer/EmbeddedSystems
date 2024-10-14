Button buttons[] = {
    {BUT01_PIN, false},  // Bottone 1
    {BUT02_PIN, false},  // Bottone 2
    {BUT03_PIN, false},  // Bottone 3
    {BUT04_PIN, false}   // Bottone 4
};

Led leds[] = {
    {LED01_PIN, 0, 0},  // Bottone 1
    {LED02_PIN, 0, 0},  // Bottone 2
    {LED03_PIN, 0, 0},  // Bottone 3
    {LED04_PIN, 0, 0}   // Bottone 4
};

struct Button {
    int pin;
    boolean pressed;
};

struct Led {
    int pin;
    int intensity;
    int pulseDelta;
};

Button setupButton (int pin, boolean pressed) {
  Button b;
  b.pin = pin;
  b.pressed = pressed
  return b;
}

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

void setPressed(Button* button, boolean value) {
    if (button != nullptr) {  // Controllo se il puntatore non è nullo
        button->pressed = value;
    }
}


void () {

}

void setup() {
    Serial.begin(9600);

    attachInterrupt(digitalPinToInterrupt(buttons[0].pin), setPressed(buttons[0],true), FALLING);
    attachInterrupt(digitalPinToInterrupt(buttons[1].pin), setPressed(buttons[1],true), FALLING);
    attachInterrupt(digitalPinToInterrupt(buttons[2].pin), setPressed(buttons[2],true), FALLING);
    attachInterrupt(digitalPinToInterrupt(buttons[3].pin), setPressed(buttons[3],true), FALLING);

}

void loop() {
  
}
