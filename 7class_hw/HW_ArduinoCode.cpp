#include <NinjaIoT.h>

NinjaIoT iot;

void setup() {
  Serial.begin(115200);
  iot.connect(wifi, pwd, uid);   //link: https://iot.roboninja.in/
}

int manual = 0;
// 0 = automatic
// 1 = manual
void loop() {
  iot.SyncIN("D2"); //sending IR reading to cloud
  delay(50);  // wait 50 milliseconds
  iot.SyncOut("D6"); //reading the D6 value. D6 is connected to manual (will be updated later)
  //D6 is connected to the dropdown for manual and automatic.
  iot.ReadAll(); // to update manual

  manual = digitalRead(D6); //linking manual with D6 reading.

  if (manual == 0) { //if the dashboard is in automatic then
    if (digitalRead(D2) == LOW) { //if IR sensor detects something then
      digitalWrite(D5, HIGH); //D5 port connects to LED. This lights up the LED.
    }
    else {
      digitalWrite(D5, LOW); //this dims the LED if IR sensor detects nothing.
    }
  }
  else { //if in manual mode
    iot.SyncOut("D5"); //Take reading from cloud about the value of D5 which comes from the toggle button of on or off.
  }
}
