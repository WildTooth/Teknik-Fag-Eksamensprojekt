#include "gamemodes/simon.h"

void setup() {
  Serial.begin(9600);
  SimonSays obj;
  obj.init();
  obj.run();
}

void loop() {

}

