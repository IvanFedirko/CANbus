#include "variant.h"
#include <due_can.h>

void setup()
{
  Serial.begin(9600);

  //Initialize CAN0, Set the proper baud rates here
  Can0.begin(CAN_BPS_125K);
  Can0.watchFor();
}

void printFrame(CAN_FRAME &frame) {
  Serial.print("ID: 0x");
  Serial.print(frame.id, HEX);
  Serial.print(" Len: ");
  Serial.print(frame.length);
  Serial.print(" Data: 0x");
  for (int count = 0; count < frame.length; count++) {
    Serial.print(frame.data.bytes[count], HEX);
    Serial.print(" ");
  }
  Serial.print("\r\n");
}

void loop() {
  CAN_FRAME incoming;
  static unsigned long lastTime = 0;


  if (Can0.available() > 0) {
    Can0.read(incoming);
    printFrame(incoming);
  }


}