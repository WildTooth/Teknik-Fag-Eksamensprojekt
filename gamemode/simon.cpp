#include "simon.h"
#include "../global.h"

int randomPin() {
  return random(0,LIGHT_PIN_AMOUNT);
}

void doRound(int speed, int sequenceLength) {
  for (int i = 0; i < sequenceLength; i++) {
    int pin = LIGHT_PINS[randomPin()];
    digitalWrite(pin, HIGH);
    delay(speed);
    digitalWrite(pin, LOW);
    delay(SPEED_FASTEST);
  }
  delay(5000);
}

void SimonSays::init() {
    Gamemode::init();
}

void SimonSays::run() {
    Gamemode::run();
    if (digitalRead(YES_INPUT) == HIGH) {
        doRound(SPEED_VERY_FAST, count++);
    }
}