#ifndef AIM_H
#define AIM_H

#include "gamemode.h"
#include "../global.h"

void playWinningSound() {
    tone(BUZZER_PIN,261);
    delay(100);
    tone(BUZZER_PIN,349);
    delay(100);
    tone(BUZZER_PIN,220);
    delay(100);
    tone(BUZZER_PIN,174);
    delay(100);
    tone(BUZZER_PIN,261);
    delay(400);
    noTone(BUZZER_PIN);
}

void playLosingSound() {
    tone(BUZZER_PIN,261);
    delay(200);
    tone(BUZZER_PIN,277);
    delay(200);
    tone(BUZZER_PIN,220);
    delay(200);
    tone(BUZZER_PIN,155);
    delay(200);
    tone(BUZZER_PIN,138);
    delay(400);
    noTone(BUZZER_PIN);
}

class AimGame : public Gamemode {
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
    digitalWrite(LIGHT_PIN_BLUE, LOW);
    int throwPause = randomInclusive(1000, 5000);
    int throwWindow = randomInclusive(3000, 6000);

    for (int i = 0; i < throwPause; i++) {
        if (Gamemode::shouldStop()) {
            stop();
            return;
        }
        if (digitalRead(MICROPHONE_PIN) == HIGH) {
            playLosingSound();
        }
        delay(1);
    }

    long startEpoch = millis();
    while (millis() - startEpoch < throwWindow) {
        if (Gamemode::shouldStop()) {
            stop();
            return;
        }
        if ((millis() - startEpoch) % 100 == 1) {
            digitalWrite(LIGHT_PIN_BLUE, HIGH);
        } else if ((millis() - startEpoch) % 100 == 50) {
            digitalWrite(LIGHT_PIN_BLUE, LOW);
        }
        if (digitalRead(MICROPHONE_PIN) == HIGH) {
            digitalWrite(LIGHT_PIN_RED, HIGH);
            playWinningSound();
            delay(500);
            digitalWrite(LIGHT_PIN_RED,LOW);
            break;
        }
    }
    stop();
  }
};

#endif