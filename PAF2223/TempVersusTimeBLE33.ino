/*
  HTS221 - Read Sensors

  This example reads temperature from the on-board HTS221 sensor of the
  Nano 33 BLE Sense, gets the measurement date and prints the temperature values to the Serial Monitor once a second.

  The circuit:
  - Arduino Nano 33 BLE Sense

  This example code is in the public domain.
*/

#include <Arduino_HTS221.h>

long InitTime; // variable to store time at the beginning of the measurement

void setup() {
  Serial.begin(9600); 
  while (!Serial); // init the serial connection, restarts until connection is established

  if (!HTS.begin()) {
    Serial.println("Failed to initialize humidity temperature sensor!");
    while (1);
  } // initialize the temperature sensor. 

  InitTime=millis();//measure start time
   Serial.println("t (s) Temperature (°C) "); // name the tab columns
}

void loop() {
  // read sensor value and internal arduino time
  float temperature = HTS.readTemperature();
  long time=millis();

  // print time each of the sensor values
  Serial.print((time-InitTime)/1000.0);
  Serial.print(" ");
  Serial.println(temperature);
  

  // wait 1 second to print again
  delay(1000);
}
