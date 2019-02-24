/*
  DS3231_test.pde
  Eric Ayars
  4/11

  Test/demo of read routines for a DS3231 RTC.

  Turn on the serial monitor after loading this to check if things are
  working as they should.

*/

#include <DS3231.h>
#include <Wire.h>

DS3231 Clock;
void setup() {
  // Start the I2C interface
  Wire.begin();
  // Start the serial interface
  Serial.begin(9600);
}

void loop() {
  
  bool temp = false;

  Serial.print("Date: ");
  Serial.print(Clock.getDate(), DEC);
  Serial.print(". ");
  Serial.print(Clock.getMonth(temp), DEC);
  Serial.print(". ");
  Serial.print(Clock.getYear(), DEC);

  Serial.print(" - Day of Week: ");
  Serial.print(Clock.getDoW(), DEC);

  Serial.print(" - Time: ");
  Serial.print(Clock.getHour(temp, temp), DEC);
  Serial.print(":");
  Serial.print(Clock.getMinute(), DEC);
  Serial.print(":");
  Serial.print(Clock.getSecond(), DEC);

  Serial.print(" - Temperature: ");
  Serial.print(Clock.getTemperature(), 2);

  if (Clock.oscillatorCheck()) {
    Serial.print(" - Oscillator working");
  } else {
    Serial.print(" - Oscillator not working");
  }

  Serial.println();

  delay(300);
}
