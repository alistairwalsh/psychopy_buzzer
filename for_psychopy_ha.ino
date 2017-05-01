
#include <Wire.h>
#include "Adafruit_DRV2605.h"
char val;
Adafruit_DRV2605 drv;


void setup() {
  Serial.begin(9600);
  drv.begin();

  // Set Real-Time Playback mode
  drv.setMode(DRV2605_MODE_REALTIME);//
}


void loop() {
  if (Serial.available()){
    val=Serial.read();
    if ((val)=='1'){
//first stimulus
      drv.setRealtimeValue(70);//intensity value
      delay(500);// this delay is how long the intensity value is sent for
//ISI
      drv.setRealtimeValue(0x00);
      delay(500);
//second stimulus
      drv.setRealtimeValue(70);
      delay(200);
      drv.setRealtimeValue(0);//turn-off
    }
    }
}

