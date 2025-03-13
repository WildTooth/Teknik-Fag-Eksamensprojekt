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

const int LIGHT_PIN_YELLOW = 23;
const int LIGHT_PIN_BLUE = 19;
const int LIGHT_PIN_RED = 22;
const int LIGHT_PIN_GREEN = 21;

const int LIGHT_PINS[] = {LIGHT_PIN_YELLOW, LIGHT_PIN_BLUE, LIGHT_PIN_RED, LIGHT_PIN_GREEN};
const int LIGHT_PIN_AMOUNT = size(LIGHT_PINS);

const int BUZZER_PIN = 16;

// INPUTS

const int BUTTON_PIN_UP = 25;
const int BUTTON_PIN_DOWN = 5;
const int BUTTON_PIN_LEFT = 18;
const int BUTTON_PIN_RIGHT = 27;
const int BUTTON_PIN_CENTER = 26;

const int BUTTON_PINS[] = {BUTTON_PIN_UP, BUTTON_PIN_DOWN, BUTTON_PIN_LEFT, BUTTON_PIN_RIGHT, BUTTON_PIN_CENTER};
const int BUTTON_PIN_AMOUNT = size(BUTTON_PINS);

const int MICROPHONE_PIN = 14;

#endif
