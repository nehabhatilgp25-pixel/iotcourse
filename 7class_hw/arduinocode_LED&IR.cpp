#include <NinjaIoT.h>

NinjaIoT iot;

void setup() {
  Serial.begin(115200);
  iot.connect("wifi", "pwd", "uid");   //link: https://iot.roboninja.in/
}

int manual = 0;
// 0 = automatic
void loop() {
  iot.SyncIN("D2");
  delay(50);  // wait 50 milliseconds
  iot.SyncOut("D6"); //connecting to D6.
  iot.ReadAll(); // to update manual

  manual = digitalRead(D6);

  if (manual == 0) {
    if (digitalRead(D2) == LOW) {
      digitalWrite(D5, HIGH);
    }
    else {
      digitalWrite(D5, LOW);
    }
    iot.SyncIN("D5");
  }
  else {
    iot.ReadAll();
  }
}
