#include <Wire.h>

/*
 * Adressen:
 *   _________      __________   
 *  /224   232\    /0xE0  0xE8\ 
 * |           |  |            |
 * |226     230|  |0xE2    0xE6|
 *  \         /    \          /
 *    --228--        --0xE4--
 */

#define ADDRESS 112                 //Aus irgendeinem Grund die Hälfte der angegebenen Adresse

void setup() {
  Wire.begin();
  Serial.begin(9600);

  Wire.beginTransmission(ADDRESS);
  Wire.write(byte(0x02));           //Register zuim Einstellen der Reichweite
  Wire.write(byte(70));             //Reichweite wird auf ~3m gesetzt, dadurch sind die Messwerte nach 21ms verfügbar
  Wire.endTransmission();   

  //changeAddress(112, 0xE8);
}

int reading = 0;

void loop() {
  // Schritt 1: Messung starten 
  Wire.beginTransmission(ADDRESS);
  Wire.write(byte(0x00));      // Command-Register wird angesprochen
  Wire.write(byte(0x51));      // Messung in cm wird gestartet
  Wire.endTransmission();      

  delay(25);                   // Warten bis Messung fertig, bei eingestellter Reichweite min 21ms

  Serial.print("1.Echo :");
  Wire.beginTransmission(ADDRESS); 
  Wire.write(byte(0x02));      // Register des 1. Echos wird angesprochen
  Wire.endTransmission();      
  Wire.requestFrom(ADDRESS, 2);// result besteht aus 2 Bytes
  
  if (2 <= Wire.available()) { 
    reading = Wire.read();  
    reading = reading << 8;    
    reading |= Wire.read(); 
    Serial.print(reading);   
  }
  
  Serial.print(" - 2.Echo: ");
  Wire.beginTransmission(ADDRESS); 
  Wire.write(byte(0x04));      // Register des 2. Echos wird angesprochen; es stehen insgesamt 17 echos zur Verfügung jeweils an Register (#Echo*2)
  Wire.endTransmission();      
  Wire.requestFrom(ADDRESS, 2);  // result besteht aus 2 Bytes
  
  if (2 <= Wire.available()) { 
    reading = Wire.read();  
    reading = reading << 8;   
    reading |= Wire.read(); 
    Serial.print(reading);   
  }

  Serial.println();

  delay(40); //Cycle muss mindestens 65ms betragen
}




// The following code changes the address of a Devantech Ultrasonic Range Finder (SRF10 or SRF08)
// usage: changeAddress(0x70, 0xE6);

void changeAddress(byte oldAddress, byte newAddress)
{
  Wire.beginTransmission(oldAddress);
  Wire.write(byte(0x00));
  Wire.write(byte(0xA0));
  Wire.endTransmission();

  Wire.beginTransmission(oldAddress);
  Wire.write(byte(0x00));
  Wire.write(byte(0xAA));
  Wire.endTransmission();

  Wire.beginTransmission(oldAddress);
  Wire.write(byte(0x00));
  Wire.write(byte(0xA5));
  Wire.endTransmission();

  Wire.beginTransmission(oldAddress);
  Wire.write(byte(0x00));
  Wire.write(newAddress);
  Wire.endTransmission();
}
