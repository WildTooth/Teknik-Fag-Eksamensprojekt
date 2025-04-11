#ifndef DEMO_H
#define DEMO_H

#include "gamemode.h"
#include "../global.h"

/**
 * Funktion der spiller en lyd baseret på farven af pin der er valgt
 * @param pin en integer repræsentation af det valgte pin
 * @param speed hvor lang tid tonen skal afspilles
 * @see https://www.szynalski.com/tone-generator/ - Her kan tonerne testes
 */
void sound(int pin, int duration) {
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

class DemoGame : public Gamemode {
public:

    void init() override {
        Gamemode::init();
    }

    void run() override {
        Gamemode::run();
        doRound();
    }

    void stop() override {
        Gamemode::stop();
    }

protected:

    void doRound() override {
        for (int i = 0; i < LIGHT_PIN_AMOUNT; i++) {
            digitalWrite(LIGHT_PINS[i], HIGH);
            sound(LIGHT_PINS[i], 250);
            delay(250);
            digitalWrite(LIGHT_PINS[i], LOW);
            delay(250);
        }
    }
};

#endif