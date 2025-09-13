#include <NinjaIoT.h>

NinjaIoT iot;


bool infra = 0; //declaring status of infrared sensor.
char status[18] = "Sensor  is  clear"; //[declaring status string which shows the status of the sensor.]

void setup() {
  Serial.begin(115200);
  iot.connect("wifi", "pwd", "uid");   //link: https://iot.roboninja.in/
  pinMode(D3, INPUT);
}

void loop() {
  infra = digitalRead(D3); // Read the digital value from the D3 pin
  if (infra == 1) {
    strcpy(status, "Sensor  is  clear"); //updating status if sensor is clear
  }
  else {
    strcpy(status, "!!Sensor blocked!!"); //updating status if sensor is blocked.
  }
  Serial.println(infra);
  Serial.println(status); //outputting the array status.
  iot.WriteVar("InfraredDetection", infra); // Send the value to the cloud

  //iot.WriteVar("Status", status); //The status array wasn't uploading for some reason. So I just commented it out.
  
  delay(50); // Wait for 0.5 seconds before sending the next value
}