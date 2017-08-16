/* OTA enabled firmware for Wemos D1 (ESP 8266, Arduino) */

#include "Arduino.h"
#include <THiNXLib.h>

THiNX thx;
const char* apikey = "71679ca646c63d234e957e37e4f4069bf4eed14afca4569a0c74abf503076732"; // required to checkin

void setup() {
  Serial.begin(115200);
#ifdef __DEBUG__
  while (!Serial);
#else
  delay(500);
#endif  
  Serial.println("Setup started.");
  thx = THiNX(apikey);  
  Serial.println("Setup completed.");
}

void loop()
{
  delay(10000);
  thx.loop(); // registers, checks MQTT status, reconnects, updates, etc.
  Serial.printf("Free size: %u\n", ESP.getFreeSketchSpace());
}
