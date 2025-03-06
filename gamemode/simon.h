#ifndef SIMON_H
#define SIMON_H

#include "gamemode.h"

#define YES_INPUT 0

#define SPEED_FASTEST 250
#define SPEED_VERY_FAST 500
#define SPEED_FAST 750
#define SPEED_NORMAL 1000
#define SPEED_SLOW 1250
#define SPEED_SLOWER_THAN_SLOW 1500
#define SPEED_VERY_SLOW 1750
#define SPEED_SLOWEST 2000

int randomPin();

void doRound(int speed, int sequenceLength);

class SimonSays : public Gamemode {
public:
    int count = 1;
};

#endif