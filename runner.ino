#include "gamemodes/gamemode.h"
#include "gamemodes/simon.h"
#include "global.h"

Gamemode* obj;

void setup() {
  Serial.begin(9600);
  initializeInputs();
  initializeOutputs();
  
  obj = new SimonSays();
  obj->init();
}

void loop() {
  obj->run();
}

void initializeInputs() {
  for (int i = 0; i < BUTTON_PIN_AMOUNT; i++) {
    pinMode(BUTTON_PINS[i], INPUT);
  }
  pinMode(MICROPHONE_PIN, INPUT);
}

void initializeOutputs() {
  for (int i = 0; i < LIGHT_PIN_AMOUNT; i++) {
    pinMode(LIGHT_PINS[i], OUTPUT);
  }
  pinMode(BUZZER_PIN, OUTPUT);
}
