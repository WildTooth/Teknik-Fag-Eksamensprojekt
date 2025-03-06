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

#endif