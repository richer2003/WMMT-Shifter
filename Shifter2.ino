#include <Joystick.h>

// Define the joystick object with 6 buttons
Joystick_ joystick;

// Define the pin numbers
const int pin2 = 2;
const int pin3 = 3;
const int pin4 = 4;
const int pin5 = 5;

void setup() {
  // Initialize the joystick library
  joystick.begin();

  // Set the pins as input and enable the internal pull-up resistors for pin 4 and pin 5
  pinMode(pin2, INPUT);
  pinMode(pin3, INPUT);
  pinMode(pin4, INPUT_PULLUP);
  pinMode(pin5, INPUT_PULLUP);
}

void loop() {
  // Read the state of the pins
  int gear = 0;

  if (digitalRead(pin2) == LOW) {
    if (digitalRead(pin4) == LOW) {
      gear = 1;
    } else if (digitalRead(pin5) == LOW) {
      gear = 2;
    }
  } else if (digitalRead(pin3) == LOW) {
    if (digitalRead(pin4) == LOW) {
      gear = 5;
    } else if (digitalRead(pin5) == LOW) {
      gear = 6;
    }
  } else if (digitalRead(pin4) == LOW) {
    gear = 3;
  } else if (digitalRead(pin5) == LOW) {
    gear = 4;
  }

  // Send the gear information to the joystick
  joystick.setButton(1, gear == 1);
  joystick.setButton(2, gear == 2);
  joystick.setButton(3, gear == 3);
  joystick.setButton(4, gear == 4);
  joystick.setButton(5, gear == 5);
  joystick.setButton(6, gear == 6);

  // Update the joystick state
  joystick.sendState();

  // Add a small delay to debounce the input
  delay(50);
}
