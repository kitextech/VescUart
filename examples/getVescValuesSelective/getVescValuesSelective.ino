/*
  Name:    getVescValuesSelective.ino
  Created: 19-08-2018
  Author:  SolidGeek
  Description:  This example is made using a Arduino Micro (Atmega32u4) that has a HardwareSerial port (Serial1) seperated from the Serial port.
                A Arduino Nano or Uno that only has one Serial port will not be able to display the data returned.
*/

#include <VescUart.h>

uint32_t mask = 0x000002A0; // this selection mask reflects which values are requested to the VESC

/** Initiate VescUart class */
VescUart UART;

void setup() {

  /** Setup Serial port to display data */
  Serial.begin(115200);

  /** Setup UART port (Serial1 on Atmega32u4) */
  Serial1.begin(115200);

  while (!Serial) {;}

  /** Define which ports to use as UART */
  UART.setSerialPort(&Serial1);
}

void loop() {

  /** Call the function getVescValues() to acquire data from VESC */
  if ( UART.getVescValuesSetupSelective(mask) ) {

    Serial.println(UART.data.rpm);
    Serial.println(UART.data.inpVoltage);
    Serial.println(UART.data.ampHours);

  }
  else
  {
    Serial.println("Failed to get data!");
  }

  delay(50);
}
