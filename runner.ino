#include "gamemodes/gamemode.h"
#include "gamemodes/simon.h"
#include "gamemodes/aim.h"
#include "gamemodes/rythm.h"
#include "gamemodes/demo.h"
#include "global.h"
#include "audio.h"

/**
 * Gamemode Objektet hvor der kan benyttes polymorphism
 * til at skifte mellem de forskellige gamemodes.
 */
Gamemode* obj;

/**
 * En integer der beskriver hvorvidt at brugeren er i gang med at skifte spil.
 * Hvis denne er -1 betyder det at der ikke er ved at blive valgt et nyt spil.
 */
int gamemodeSelect = -1;

/**
 * Denne integer beskriver hvorvidt at der er valgt et spil.
 * Hvis denne er -1 betyder det at der ikke er valgt et spil.
 */
int savedGamemode = -1;

void setup() {
  Serial.begin(115200);
  initializeInputs();
  initializeOutputs();
  audioInitialize();
  playSound("/Win.dat", 22000);
  digitalWrite(LIGHT_PIN_YELLOW,HIGH);
  digitalWrite(LIGHT_PIN_RED,HIGH);
  digitalWrite(LIGHT_PIN_BLUE,HIGH);
  digitalWrite(LIGHT_PIN_GREEN,HIGH);
  delay(800);
  digitalWrite(LIGHT_PIN_YELLOW,LOW);
  digitalWrite(LIGHT_PIN_RED,LOW);
  digitalWrite(LIGHT_PIN_BLUE,LOW);
  digitalWrite(LIGHT_PIN_GREEN,LOW);
  
}

void loop() {
  gamemodeSelect = isPressingGameButton();
  if (gamemodeSelect != -1) {
    switchGamemode(gamemodeSelect);
    obj->init();
    gamemodeSelect = -1;
  }
  if (savedGamemode == -1) {
    return;
  }
  obj->run();
}

/**
 * Den fundne knap der bliver benyttet i momentet.
 */
 // Her sættes den til -69, bare fordi.
int currentButtonPin = -69;

/**
 * Tjekker for om der bliver holdt en knap nede, dette kunne godt have været en booleansk funktion,
 * men vi har valgt at lade den returnere en integer i stedet da vi på den måde kan få mere detaljeret information
 * ud af returneringen.
 * 
 * @return en integer som fortæller hvilken knap der bliver trykket på, hvis ingen bliver trykket på returneres -1
 */
int isPressingGameButton() {
  for (int i = 0; i < BUTTON_PIN_AMOUNT; i++) {
    currentButtonPin = BUTTON_PINS[i];
    if (currentButtonPin == BUTTON_PIN_CENTER) {
      continue;
    }
    if (digitalRead(currentButtonPin) == LOW) {
      return currentButtonPin;
    }
  }
  return -1;
}

/**
 * En simpel funktion til at håndtere skift mellem de forskellige spiltilstande
 * @param gamemode en integer svarende til den knap der er blevet trykket på.
 */
void switchGamemode(int gamemode) {
  switch(gamemode) {
    case BUTTON_PIN_UP:
      obj = new SimonSays();
      savedGamemode = 0;
      Serial.println("SIMONNNNN!");
      delay(500);
      break;
    case BUTTON_PIN_DOWN:
      obj = new AimGame();
      savedGamemode = 1;
      Serial.println("Sigte!!");
      delay(500);
      break;
    case BUTTON_PIN_LEFT:
      obj = new RythmGame();
      savedGamemode = 2;
      Serial.println("Rytme!");
      delay(500);
      break;
    case BUTTON_PIN_RIGHT:
      obj = new DemoGame();
      savedGamemode = 3;
      Serial.println("DEMO!");
      delay(500);
      break;
    default:
      return;
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
  pinMode(SPEAKER_PIN, OUTPUT);
}
