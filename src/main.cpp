#include <Arduino.h>
bool light;

void setup()
{
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(D5, INPUT_PULLUP);
  pinMode(D4, OUTPUT);
  analogWriteRange(1023);
  light = false;
}

void loop()
{
  // put your main code here, to run repeatedly:
  int iButton;
  int iVal = analogRead(A0);
  iButton = digitalRead(D5);
  delay(100);
  Serial.println("button " + String(iButton));
  if (light == 1)
  {
    Serial.println("light " + String(light));
    analogWrite(D4, iVal);
  }
  else
  {
    digitalWrite(D4, 1);
  }
  if (iButton == 0)
  {
    light = !light;
  }

  delay(200);
}