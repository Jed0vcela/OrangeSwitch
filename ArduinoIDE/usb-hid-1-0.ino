
#include "USB.h"
#include "USBHIDGamepad.h"
USBHIDGamepad Gamepad;

const int buttonPin = 0;
const int mux1 = 9;
const int mux2 = 10;
const int mux3 = 11;
const int A = 13;
const int B = 14;
const int C = 21;
int previousButtonState = HIGH;

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(mux1, INPUT_PULLDOWN);  //imputs from analog switches
  pinMode(mux2, INPUT_PULLDOWN);
  pinMode(mux3, INPUT_PULLDOWN);

  pinMode(A, OUTPUT);   //analog switch adress select pins
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);

  Gamepad.begin();
  USB.begin();
  //analogSetWidth(12);
}

void loop() {
  static uint8_t padID = 0;
  static long lastPress = 0;
  uint16_t analogMux2;
  uint16_t analogMux3;

  digitalWrite(A, LOW); //hsb
  digitalWrite(B, LOW);
  digitalWrite(C, LOW); //least significant byte
  delay(1);
  analogMux2 = (analogRead(mux2)/16-128);
  analogMux3 = (analogRead(mux3)/16)-128;
  Gamepad.leftStick(analogMux2, analogMux3); // X Axis, Y Axis
  //Gamepad.leftStick(analogRead(mux2), (analogRead(mux3)); // X Axis, Y Axis
  delay(1);

  digitalWrite(A, LOW);
  digitalWrite(B, LOW);
  digitalWrite(C, HIGH);
  delay(1);
  analogMux2 = analogRead(mux2)/16-128;
  analogMux3 = analogRead(mux3)/16-128;
  Gamepad.rightStick(analogMux2, analogMux3);
  //Gamepad.rightStick(analogRead(mux2), (analogRead(mux3)); // X Axis, Y Axis
  delay(1);

  digitalWrite(A, LOW);
  digitalWrite(B, HIGH);
  digitalWrite(C, LOW);
  delay(1);

  if(analogRead(mux1)>800){
    Gamepad.pressButton(1);
  }
  else{
    Gamepad.releaseButton(1);
    }

  if(analogRead(mux2)>800){
    Gamepad.pressButton(2);
    }
  else{
    Gamepad.releaseButton(2);
  }

  if(analogRead(mux3)>800){
    Gamepad.pressButton(3);
    }
  else{
    Gamepad.releaseButton(3);
  }

  digitalWrite(A, LOW);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  delay(1);
  if(analogRead(mux1)>800){
    Gamepad.pressButton(4);
  }
  else{
    Gamepad.releaseButton(4);
    }

  if(analogRead(mux2)>800){
    Gamepad.pressButton(5);
    }
  else{
    Gamepad.releaseButton(5);
  }

  if(analogRead(mux3)>800){
    Gamepad.pressButton(6);
    }
  else{
    Gamepad.releaseButton(6);
  }

  digitalWrite(A, HIGH);
  digitalWrite(B, LOW);
  digitalWrite(C, LOW);
  delay(1);
  if(analogRead(mux1)>800){
    Gamepad.pressButton(7);
  }
  else{
    Gamepad.releaseButton(7);
    }

  if(analogRead(mux2)>800){
    Gamepad.pressButton(8);
    }
  else{
    Gamepad.releaseButton(8);
  }

  if(analogRead(mux3)>800){
    Gamepad.pressButton(9);
    }
  else{
    Gamepad.releaseButton(9);
  }

  digitalWrite(A, HIGH);
  digitalWrite(B, LOW);
  digitalWrite(C, HIGH);
  delay(1);
  if(analogRead(mux1)>800){
    Gamepad.pressButton(10);
  }
  else{
    Gamepad.releaseButton(10);
    }

  if(analogRead(mux2)>800){
    Gamepad.pressButton(11);
    }
  else{
    Gamepad.releaseButton(11);
  }

  if(analogRead(mux3)>800){
    Gamepad.pressButton(12);
    }
  else{
    Gamepad.releaseButton(12);
  }

  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, LOW);
  delay(1);
  if(analogRead(mux1)>800){
    Gamepad.pressButton(13);
  }
  else{
    Gamepad.releaseButton(13);
    }

  if(analogRead(mux2)>800){
    Gamepad.pressButton(14);
    }
  else{
    Gamepad.releaseButton(14);
  }

  if(analogRead(mux3)>800){
    Gamepad.pressButton(15);
    }
  else{
    Gamepad.releaseButton(15);
  }

  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  delay(1);
  if(analogRead(mux1)>800){
    Gamepad.pressButton(16);
  }
  else{
    Gamepad.releaseButton(16);
    }

  if(analogRead(mux2)>800){
    Gamepad.pressButton(17);
    }
  else{
    Gamepad.releaseButton(17);
  }

  if(analogRead(mux3)>800){
    Gamepad.pressButton(18);
    }
  else{
    Gamepad.releaseButton(18);
  }
}
