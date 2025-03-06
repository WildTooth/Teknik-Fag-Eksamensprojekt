#ifndef SIMON_H
#define SIMON_H

#include "gamemode.h"
#include "../global.h"

#define YES_INPUT 6

#define SPEED_FASTEST 250
#define SPEED_VERY_FAST 500
#define SPEED_FAST 750
#define SPEED_NORMAL 1000
#define SPEED_SLOW 1250
#define SPEED_SLOWER_THAN_SLOW 1500
#define SPEED_VERY_SLOW 1750
#define SPEED_SLOWEST 2000

int randomPin() {
  return random(0, LIGHT_PIN_AMOUNT);
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

class SimonSays : public Gamemode {
public:
    int count = 1;

    void init() override {
        Gamemode::init();  // Call the base class init function
    }
    void run() override {
      Gamemode::run();  // Call the base class run function
      if (digitalRead(YES_INPUT) == HIGH) {
          doRound(SPEED_VERY_FAST, count++);
      }
    }
};

#endif