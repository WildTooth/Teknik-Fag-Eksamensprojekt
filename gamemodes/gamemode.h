#ifndef GAMEMODE_H
#define GAMEMODE_H

#include "../global.h"

class Gamemode {
public:
    virtual void init() {
      // Standard initialiserings logik kan implementeres her
    }

    virtual void run() {
      // Standard run logik, det som skal loopes ;)
      // Gid det var Java det her, Runnable.run() ville gå ret hårdt lige nu 8-( - Kh. Jonathan "Johnny" "John" Holck
    }

    virtual void stop() {
      // Standard stop logik
      for (int i = 0; i < LIGHT_PIN_AMOUNT; i++) {
        digitalWrite(LIGHT_PINS[i], LOW);
      }
      noTone(BUZZER_PIN);
    }

protected:
    virtual boolean shouldStop() {
      bool shouldStop = false;
      for (int i = 0; i < BUTTON_PIN_AMOUNT; i++) {
        if (BUTTON_PINS[i] == BUTTON_PIN_CENTER) {
          continue;
        }
        shouldStop = (digitalRead(BUTTON_PINS[i]) == HIGH);
        if (shouldStop) {
          return true;
        }
      }
      return false;
    }

    virtual void doRound() {
      // Standard runde metode
    }
};

#endif