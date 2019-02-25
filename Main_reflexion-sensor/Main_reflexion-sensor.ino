#define BALL_LIGHT 47
#define BALL_TOUCH A15

void setup() {
  pinMode(BALL_LIGHT, OUTPUT);
  pinMode(BALL_TOUCH, INPUT_PULLUP);

  digitalWrite(BALL_LIGHT, HIGH);
  
  /*  Der Sensor hat eine Reaktionszeit von 5ms -> nach einschalten der LED muss mindestens 5ms gewarten
   *  werden bevor der Sensor ausgelesen wird.
   *  
   *  Man kann die LED also entweder konstant anlassen oder man wartet immer 5ms.
   */
}

void loop() {
  int value = analogRead(A15);
  
  Serial.println(value);
}
