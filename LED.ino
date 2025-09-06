#include <NinjaIoT.h>

NinjaIoT iot;

void setup() {
  Serial.begin(115200);
  iot.connect("WIFI_NAME", "WIFI_PASS", "USER_ID");   //link: https://iot.roboninja.in/
}

void loop() {
  iot.ReadAll();   // Read all values from the cloud

  // Control LED D1 according to server value (ON/OFF)
  iot.SyncOut("D1");

  delay(50);  // wait 50 milliseconds
}