#include "gamemodes/gamemode.h"
#include "gamemodes/simon.h"
#include "gamemodes/aim.h"
#include "gamemodes/rythm.h"
#include "global.h"

Gamemode* obj;
int gamemodeSelect = -1;
int savedGamemode = -1;

void setup() {
  Serial.begin(115200);
  initializeInputs();
  initializeOutputs();
}

void loop() {
  gamemodeSelect = isPressingGameButton();
  if (gamemodeSelect != -1) {
    switchGamemode(gamemodeSelect);
  }
  obj->run();
}

int currentButtonPin = -69;

int isPressingGameButton() {
  for (int i = 0; i < BUTTON_PIN_AMOUNT; i++) {
    currentButtonPin = BUTTON_PINS[i];
    if (currentButtonPin == BUTTON_PIN_CENTER) {
      continue;
    }
    if (digitalRead(currentButtonPin) == HIGH) {
      return currentButtonPin;
    }
  }
  return -1;
}

void switchGamemode(int gamemode) {
  switch(gamemode) {
    case BUTTON_PIN_UP:
      obj = new SimonSays();
      savedGamemode = 0;
    case BUTTON_PIN_DOWN:
      obj = new AimGame();
      savedGamemode = 1;
    case BUTTON_PIN_LEFT:
      obj = new RythmGame();
      savedGamemode = 2;
    case BUTTON_PIN_RIGHT:
      obj = new SimonSays();
      savedGamemode = 3;
    default:
      obj -> init();
  }
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
