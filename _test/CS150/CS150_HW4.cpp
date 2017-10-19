#line 1 "CS150_HW4.ino"
/* blinks PORTB[5] */

#include "Arduino.h"
void setup();
void loop();
#line 3
const int ledPin = 13;

int ledState = LOW;
long previousMilliS = 0;
long interval = 1000;

void setup()
{
  pinMode(ledPin, OUTPUT);
}


void loop()
{
  unsigned long currentMilliS = millis();
  
  if (currentMilliS - previousMilliS > interval) {
    previousMilliS = currentMilliS;
    
    if (ledState == LOW)
      ledState = HIGH;
    else
      ledState = LOW;
    
    digitalWrite(ledPin, ledState);
  }
}


