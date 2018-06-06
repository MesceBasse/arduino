// Volume Library 1KHz Sketch (c) 2016 Connor Nishijima
// Released under the GPLv3 license

#include "Volume.h" // Include the Volume library

Volume vol; // Plug your speaker into the default pin for your board type:
            // https://github.com/connornishijima/arduino-volume#supported-pins

// the setup routine runs once when you press reset:
void setup() {
  vol.begin();
  Serial.begin(9600);
}

// the loop routine runs over and over again forever:
void loop() {
  int sensorReading = analogRead(A0);
  int volume = map(sensorReading, 100, 1000, 0, 255);
  Serial.println(volume);
  float mv = constrain(volume / 10, 0, 100) / 100.00;
  vol.tone(1000, 255*mv);
}
