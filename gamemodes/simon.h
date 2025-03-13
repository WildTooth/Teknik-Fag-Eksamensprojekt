#ifndef SIMON_H
#define SIMON_H

#include "gamemode.h"
#include "../global.h"

#include <vector>

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

void playMatchingSound(int pin, int speed) {
  switch(pin) {
    case LIGHT_PIN_YELLOW:
      tone(BUZZER_PIN, 987, speed);
      break;
    case LIGHT_PIN_BLUE:
      tone(BUZZER_PIN, 220, speed);
      break;
    case LIGHT_PIN_RED:
      tone(BUZZER_PIN, 415, speed);
      break;
    case LIGHT_PIN_GREEN:
      tone(BUZZER_PIN, 659, speed);
      break;
  }
}

class SimonSays : public Gamemode {
public:
    int speed = 0;
    std::vector<int> sequence = {};

    void init() override {
        Gamemode::init();
        speed = SPEED_VERY_FAST;
        if (!sequence.empty()) {
            sequence.clear();
        }
    }
    
    void run() override {
      Gamemode::run();
      if (digitalRead(BUTTON_PIN_CENTER) == HIGH) {
          sequence.push_back(LIGHT_PINS[randomPin()]);
          doRound();
      }
    }

    void stop() override {
      Gamemode::stop();
    }

protected:
  void doRound() override {
    for (int i = 0; i < sequence.size(); i++) {
        if (Gamemode::shouldStop()) {
          stop();
          return;
        }
        int pin = sequence.at(i);
        digitalWrite(pin, HIGH);
        playMatchingSound(pin, speed);
        delay(speed);
        digitalWrite(pin, LOW);
        delay(SPEED_FAST);
    }
    stop();
  }
};

#endif
