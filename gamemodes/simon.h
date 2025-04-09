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

/**
 * Funktion der returnere værdien på et tilfældigt LED-pin.
 * @return tilfædlig LED-pin værdi.
 */
int randomPin() {
    return random(0, LIGHT_PIN_AMOUNT);
}

/**
 * Funktion der spiller en lyd baseret på farven af pin der er valgt
 * @param pin en integer repræsentation af det valgte pin
 * @param speed hvor lang tid tonen skal afspilles
 * @see https://www.szynalski.com/tone-generator/ - Her kan tonerne testes
 */
void playMatchingSound(int pin, int duration) {
  switch(pin) {
    case LIGHT_PIN_YELLOW:
      tone(BUZZER_PIN, 987, duration);
      break;
    case LIGHT_PIN_BLUE:
      tone(BUZZER_PIN, 220, duration);
      break;
    case LIGHT_PIN_RED:
      tone(BUZZER_PIN, 415, duration);
      break;
    case LIGHT_PIN_GREEN:
      tone(BUZZER_PIN, 659, duration);
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
      if (digitalRead(BUTTON_PIN_CENTER) == LOW) {
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