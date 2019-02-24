#include <Wire.h>
#include "Adafruit_MCP23017.h"

#define NUM_LEDS      2
#define NUM_SWITCHES  6
#define NUM_BUTTONS   8

#define S_HEADSTART   0
#define S_MOTORS      1
#define S_BLUETOOTH   2
#define S_KICKER      3
#define S_BODENSENSOR 4
#define S_DEBUGINFO   5

#define L_KEEPER      6
#define L_STRIKER     7

#define B_LEFT        8
#define B_MIDDLE      9
#define B_RIGHT       10
#define B_KICK        11
#define B_COMPASS     12
#define B_ANIMATION   13
#define B_LINECAL     14
#define B_LIGHTBCAL   15

Adafruit_MCP23017 mcp;

int switches[NUM_SWITCHES] = {S_HEADSTART, S_MOTORS, S_BLUETOOTH, S_KICKER, S_BODENSENSOR, S_DEBUGINFO};
int leds[NUM_LEDS] = {L_KEEPER, L_STRIKER};
int buttons[NUM_BUTTONS] = {B_LEFT, B_MIDDLE, B_RIGHT, B_KICK, B_COMPASS, B_ANIMATION, B_LINECAL, B_LIGHTBCAL};
  
void setup() {  
  mcp.begin();      // use default address 0
  Serial.begin(9600);

  for(int i = 0; i<NUM_SWITCHES; i++){
    mcp.pinMode(switches[i], INPUT);
    mcp.pullUp(switches[i], HIGH);  // turn on a 100K pullup internally
  }
  
  for(int i = 0; i<NUM_BUTTONS; i++){
    mcp.pinMode(buttons[i], INPUT);
    mcp.pullUp(buttons[i], HIGH);  // turn on a 100K pullup internally
  }

  for(int i = 0; i<NUM_LEDS; i++){
    mcp.pinMode(leds[i], OUTPUT);
  }
}



void loop() {
  Serial.println("Switches: ");
  for(int i = 0; i<NUM_SWITCHES; i++){
    Serial.print(mcp.digitalRead(switches[i]));
    Serial.print(" - ");
  }
  Serial.println("\n");

  
  Serial.println("Buttons: ");
  for(int i = 0; i<NUM_BUTTONS; i++){
    Serial.print(mcp.digitalRead(buttons[i]));
    Serial.print(" - ");
  }
  Serial.println("\n");

  for(int i = 0; i<NUM_LEDS; i++){
    mcp.digitalWrite(leds[i], (millis()%1000 > 500)+i %2);
  }

  delay(100);
}
