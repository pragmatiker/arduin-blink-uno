#include <Arduino.h>
#define GREENLED 13

void showLED(int, int, bool);

void setup() {
  Serial.begin(19200);
  pinMode(GREENLED, OUTPUT);
  Serial.println("Start");
}

void loop() {
 showLED(GREENLED,3050, HIGH);
 showLED(GREENLED,2023, LOW);
}

void showLED(int pin, int delayPeriod, bool LedStatus)
{
  double delayPeriodDbl = delayPeriod / 1000.00;
  char delayPeriodStr[5];
  char buffer[40];
  dtostrf(delayPeriodDbl,2,2,delayPeriodStr);

  if (LedStatus)
  {
    sprintf(buffer,"The green light is on for %s seconds", delayPeriodStr);
    Serial.println(buffer);
    digitalWrite(GREENLED,HIGH);
  }
  else
  {
    sprintf(buffer,"The green light is off for %s seconds", delayPeriodStr);
    Serial.println(buffer);
    digitalWrite(GREENLED,LOW);
  }
  delay(delayPeriod);
}