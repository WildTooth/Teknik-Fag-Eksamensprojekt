#include "gamemodes/gamemode.h"
#include "gamemodes/simon.h"
#include "global.h"

Gamemode* obj;

void setup() {
  Serial.begin(9600);
  for (int i = 0; i < LIGHT_PIN_AMOUNT; i++) {
    pinMode(LIGHT_PINS[i], OUTPUT);
  }
  pinMode(YES_INPUT, INPUT);
  obj = new SimonSays();
  obj->init();  // Initialize the SimonSays object
}

void loop() {
  obj->run();  // Continuously run the SimonSays game
}