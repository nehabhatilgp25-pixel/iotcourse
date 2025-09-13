#include <NinjaIoT.h>

NinjaIoT iot;

bool infra = LOW;

void setup() {
  Serial.begin(115200);
  iot.connect("wifi", "pwd", "uid");   //link: https://iot.roboninja.in/
  pinMode(D3, INPUT);
  pinMode(D5, OUTPUT);
}

void loop() {
  iot.SyncIN("D3");
  infra = digitalRead(D3); // Read the analog value from A0 pin
  iot.WriteVar("InfraredDetection", infra); // Send the value to the cloud
  if (infra == HIGH) {
    digitalWrite(D5, 1000);
  }
  else {
    digitalWrite(D5, LOW);
  }
  Serial.println(infra);
  delay(50); // Wait for 1.5 seconds before sending the next value
}