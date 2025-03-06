#ifndef GLOBAL_H
#define GLOBAL_H

#include <stddef.h> // Arduinos definitioner, vi skal bruge dette import for at kunne bruge typen "size_t"

template <typename T, size_t N>
constexpr int size(T (&array)[N]) {
  return N;
}

extern const int LIGHT_PIN_YELLOW;
extern const int LIGHT_PIN_BLUE;
extern const int LIGHT_PIN_RED;
extern const int LIGHT_PIN_GREEN;

extern const int LIGHT_PINS[];
extern const int LIGHT_PIN_AMOUNT;

extern const int BUTTON_PIN_UP;
extern const int BUTTON_PIN_DOWN;
extern const int BUTTON_PIN_LEFT;
extern const int BUTTON_PIN_RIGHT;
extern const int BUTTON_PIN_CENTER;

extern const int BUTTON_PINS[];
extern const int BUTTON_PIN_AMOUNT;

#endif