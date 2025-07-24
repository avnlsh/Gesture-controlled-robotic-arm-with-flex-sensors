#include <Servo.h>

Servo servos[5];
int flexPins[5] = {A0, A1, A2, A3, A4};
int servoPins[5] = {3, 4, 5, 6, 7};
int flexValues[5];

void setup() {
 Serial.begin(9600);
 for (int i = 0; i < 5; i++) {
   servos[i].attach(servoPins[i]);
 }
}

void loop() {
 for (int i = 0; i < 5; i++) {
   flexValues[i] = analogRead(flexPins[i]);
   int angle = map(flexValues[i], 600, 900, 0, 180);
   angle = constrain(angle, 0, 180);
   servos[i].write(angle);
 }
 delay(50);
}
