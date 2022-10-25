#include <Wire.h>
#include "Adafruit_DRV2605.h"

Adafruit_DRV2605 drv;

void setup() {
  Serial.begin(9600);
  Serial.flush();

  drv.begin();
  drv.selectLibrary(6);
  drv.useLRA();

  // Set Real-Time Playback mode
  // drv.setMode(DRV2605_MODE_REALTIME);
}

// int amplitude;
// int delayBetweenTap;
// int iterationValue4;

// char serialInput;

// bool newData = false;

// const byte numChars = 32;
// char receivedChars[numChars];

// int index = 0;

void loop() {
  if (Serial.available() > 0) {
    int effectId = Serial.read();
    drv.setWaveform(0, effectId);
    drv.setWaveform(1, 0x00);
    drv.go();
    Serial.print(effectId);
  }
//   drv.setRealtimeValue(lowByte(200));
//   delay(100);
//   drv.setRealtimeValue(0x00);
//   delay(100);
}

  // if (Serial.available() > 0) {
  //   serialInput = Serial.read();

  //   // if (serialInput > 0) {

  //   //   for (int i = 0; i < iterationValue; i++) {
  //   //     drv.setRealtimeValue(lowByte(serialInput));
  //   //     delay(delayBetweenTap);
  //   //     drv.setRealtimeValue(0x00);
  //   //     delay(delayBetweenTap);
  //   //   }
  //   // }

  //   Serial.println(serialInput);
  // }

