#ifndef RYTHM_H
#define RYTHM_H

#include "gamemode.h"
#include "../global.h"

class RythmGame : public Gamemode {
public:

    /**
     * Beskriver rytmehastigheden
     */
    int speed = 100;

    /**
     * Et array der representere en rytme
     */
    byte rythm[32] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

    void init() override {
        Gamemode::init();
        speed = 100;
        for (int i = 0; i < size(rythm); i++) {
          rythm[i] = 0;
        }
    }

    void run() override {
        Gamemode::run();
        doRound();
    }

protected:

  void doRound() override {
      for (int i = 0; i < 2; i++){
          if (Gamemode::shouldStop()) {
            stop();
            return;
          }
          for (int j = 0; j < 32; ++j){
            if (Gamemode::shouldStop()) {
              stop();
              return;
            }
            if (j == 0) { 
              digitalWrite(LIGHT_PIN_BLUE, HIGH); 
              tone(BUZZER_PIN,400);
            }
            if (j == 0 && i ==0) { 
              digitalWrite(LIGHT_PIN_BLUE, HIGH); 
              tone(BUZZER_PIN,1600);
            }
            if ( j == 8 || j == 16 || j == 24) { 
              digitalWrite(LIGHT_PIN_BLUE, HIGH); 
              tone(BUZZER_PIN,100);
            }
            if (rythm[j] == 1 ) {
              digitalWrite(LIGHT_PIN_RED, HIGH);
              tone(BUZZER_PIN,800);
        
              for (int k = 0 ; k < speed; k++) {
                if (Gamemode::shouldStop()) {
                  stop();
                  return;
                }
                if (speed / 2 < k) { 
                  noTone(BUZZER_PIN); 
                  digitalWrite(LIGHT_PIN_RED, LOW); 
                  digitalWrite(LIGHT_PIN_BLUE, LOW);
                }
                if (digitalRead(MICROPHONE_PIN) == HIGH) {
                  rythm[i] = 1;
                  digitalWrite(LIGHT_PIN_RED,HIGH);
                } else {
                  digitalWrite(LIGHT_PIN_RED,LOW);
                }
                delay(1);
              }
            } else {
              for (int k = 0 ; k < speed; k++) {
                if (Gamemode::shouldStop()) {
                  stop();
                  return;
                }
                if (speed / 2 < k) { 
                  noTone(BUZZER_PIN); 
                  digitalWrite(LIGHT_PIN_BLUE, LOW);
                }
                if (digitalRead(MICROPHONE_PIN) == HIGH) {
                  rythm[j] = 1; digitalWrite(LIGHT_PIN_RED,HIGH);
                } else {
                  digitalWrite(LIGHT_PIN_RED,LOW);
                }
                delay(1);
              }
            }
          }
          if (i == 1) {  
              for(int l = 0; l < 32; ++l) {
                  rythm[l] = 0;
              }  
          }
      }
      stop();
  }
};

#endif