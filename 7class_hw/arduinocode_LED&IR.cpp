#include <NinjaIoT.h>

NinjaIoT iot;

void setup() {
  Serial.begin(115200);
  iot.connect("wifi", "pwd", "uid");   //link: https://iot.roboninja.in/
}

void loop() {
  // put your main code here, to run repeatedly:
  iot.ReadAll(); // Read all values from the cloud

  // Read button state on D0 and upload it
  iot.SyncIN("D2");
  iot.SyncIN("D5");
  delay(50);  // wait 50 milliseconds

  if (digitalRead(D2) == LOW) {
    digitalWrite(D5, HIGH);
  }
  delay(100); //wait 100 milliseconds
  if (digitalRead(D2) == HIGH) {
    digitalWrite(D5, LOW);
  }
}
