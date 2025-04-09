#ifndef AUDIO_H
#define AUDIO_H

#include <SPIFFS.h>
#include <FS.h>
#include "global.h"

const int bufferSize = 128;

byte audioBuffer[bufferSize];

int bufferIndex = 0;
int bytesRead = 0;

unsigned long lastSampleTime = 0;
File audioFile;

void audioInitialize() {
  if (!SPIFFS.begin(true)) {
    while (1);
  }
}

void playSound(const char* filePath, int sampleRate) {
  audioFile = SPIFFS.open(filePath, "r");
  if (!audioFile) {
    return;
  }

  lastSampleTime = micros();
  bufferIndex = 0;
  bytesRead = 0;

  while (audioFile.available()) {
    if (bufferIndex >= bytesRead) {
      bytesRead = audioFile.read(audioBuffer, bufferSize);
      bufferIndex = 0;
      if (bytesRead <= 0) break;
    }

    unsigned long currentTime = micros();
    if (currentTime - lastSampleTime >= (1000000 / sampleRate)) {
      dacWrite(SPEAKER_PIN, audioBuffer[bufferIndex]);
      bufferIndex++;
      lastSampleTime += (1000000 / sampleRate);
    }
  }

  audioFile.close();
}

#endif