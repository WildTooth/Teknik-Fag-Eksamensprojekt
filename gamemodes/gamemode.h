#ifndef GAMEMODE_H
#define GAMEMODE_H

#include "../global.h"

class Gamemode {
public:

    /**
     * Initialiserings funktion for alle spillene, dette fungere også som en "reset" funktion.
     * Denne returnere ikke mere information.
     */
    virtual void init() {
      // Standard initialiserings logik kan implementeres her
    }

    /**
     * Standard "loop" logik for spillene, dette er en samlende funktion der loopes i runneren.
     */
    virtual void run() {
      // Standard run logik, det som skal loopes ;)
      // Gid det var Java det her, Runnable.run() ville gå ret hårdt lige nu 8-( - Kh. Jonathan "Johnny" "John" Holck
    }

    /**
     * Standard stop logik for spillene, denne er nyttige for at kunne skifte spil, midt i runderne.
     */
    virtual void stop() {
      // Standard stop logik
      for (int i = 0; i < LIGHT_PIN_AMOUNT; i++) {
        digitalWrite(LIGHT_PINS[i], LOW);
      }
      noTone(BUZZER_PIN);
    }

protected:

    /**
     * Booleansk funktion som beskriver standardlogikken bag hvorvidt et spil skal afbrydes.
     */
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

    /**
     * Standard metode til at håndtere en runde i et spil
     */
    virtual void doRound() {
      // Standard runde metode
    }
};

#endif