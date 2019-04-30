#include <Arduino.h>

void setup() {
  pinMode(PA0, OUTPUT);
  Serial.begin(115200);
}

int i = 0;
void loop() {
  i++;
  if (Serial.availableForWrite() > 50){
    Serial.print("Loop Count: ");
    Serial.println(i);
  };
  digitalWrite(PA0, HIGH);
  delay(250);
  digitalWrite(PA0, LOW);
  delay(250);
}
