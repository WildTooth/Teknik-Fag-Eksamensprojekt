#ifndef SIMON_H
#define SIMON_H

#include "gamemode.h"
#include "../global.h"

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

void doRound(int speed, vector<int> sequence) {
    sequence.push_back(LIGHT_PINS[randomPin()]);
    for (int i = 0; i < sequence.size(); i++) {
        int pin = sequence.at(i);
        digitalWrite(pin, HIGH);
        delay(speed);
        digitalWrite(pin, LOW);
        delay(SPEED_FASTEST);
    }
}

class SimonSays : public Gamemode {
public:
    vector<int> sequence = {};

    void init() override {
        Gamemode::init();
        if (!sequence.empty()) {
            sequence.clear();
        }
    }
    void run() override {
      Gamemode::run();
      if (digitalRead(BUTTON_PIN_CENTER) == HIGH) {
          doRound(SPEED_VERY_FAST, sequence);
      }
    }
};

#endif