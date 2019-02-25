#define TEMP_MOTORTREIBER A5
#define TEMP_RELAIS A13

void setup() {
  Serial.begin(9600);
}

void loop() {
  float temperature = analogRead(TEMP_MOTORTREIBER) * 0.4888;
  Serial.println(sensorValue);
}
