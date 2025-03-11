#ifndef GLOBAL_H
#define GLOBAL_H

#include <stddef.h> // Arduinos definitioner, vi skal bruge dette import for at kunne bruge typen "size_t"
#include <Arduino.h> // Så vi får funktioner så som random

template <typename T, size_t N>
constexpr int size(T (&array)[N]) {
  return N;
}

long randomInclusive(long min, long max) {
  return random(min, max + 1);
}

const int LIGHT_PIN_YELLOW = 0;
const int LIGHT_PIN_BLUE = 0;
const int LIGHT_PIN_RED = 0;
const int LIGHT_PIN_GREEN = 0;

const int LIGHT_PINS[] = {LIGHT_PIN_YELLOW, LIGHT_PIN_BLUE, LIGHT_PIN_RED, LIGHT_PIN_GREEN};
const int LIGHT_PIN_AMOUNT = size(LIGHT_PINS);

const int BUZZER_PIN = 0;

// INPUTS

const int BUTTON_PIN_UP = 0;
const int BUTTON_PIN_DOWN = 10;
const int BUTTON_PIN_LEFT = 20;
const int BUTTON_PIN_RIGHT = 30;
const int BUTTON_PIN_CENTER = 40;

const int BUTTON_PINS[] = {BUTTON_PIN_UP, BUTTON_PIN_DOWN, BUTTON_PIN_LEFT, BUTTON_PIN_RIGHT, BUTTON_PIN_CENTER};
const int BUTTON_PIN_AMOUNT = size(BUTTON_PINS);

const int MICROPHONE_PIN = 0;

#endif