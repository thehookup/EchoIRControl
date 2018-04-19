/*
 * IRremote: IRrecvDemo - demonstrates receiving IR codes with IRrecv
 * An IR detector/demodulator must be connected to the input RECV_PIN.
 * Version 0.1 July, 2009
 * Copyright 2009 Ken Shirriff
 * http://arcfn.com
 */

#include <IRremote.h>

const int RECV_PIN = 2;
const int onOff = 3;

IRrecv irrecv(RECV_PIN);

decode_results results;

void setup()
{
  Serial.begin(9600);
  // In case the interrupt driver crashes on setup, give a clue
  // to the user what's going on.
  Serial.println("Enabling IRin");
  irrecv.enableIRIn(); // Start the receiver
  Serial.println("Enabled IRin");
  pinMode(onOff, OUTPUT);
}

void loop() {
  if (irrecv.decode(&results)) {
    Serial.println(results.value, HEX);
    if(results.value == 0x10E23DC)
    {
      Serial.println("CD");
      digitalWrite(onOff, HIGH);      
    }
    if(results.value == 0x10E4FB0)
    {
      Serial.println("HDMI 1");
      digitalWrite(onOff, LOW);
    }
    if(results.value == 0x10ECF30)
    {
      Serial.println("HDMI 2");
      digitalWrite(onOff, LOW);
    }
    if(results.value == 0x10E3FC0)
    {
      Serial.println("HDMI 3");
      digitalWrite(onOff, LOW);
    }
    if(results.value == 0x10E7F80)
    {
      Serial.println("HDMI 4");
      digitalWrite(onOff, LOW);
    }
    if(results.value == 0x10E0BF4)
    {
      Serial.println("DVD");
      digitalWrite(onOff, LOW);
    }
    irrecv.resume(); // Receive the next value
  }
  delay(100);
}
