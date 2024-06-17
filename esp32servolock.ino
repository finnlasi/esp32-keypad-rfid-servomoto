#include <Servo.h>
#include <Keypad.h>

Servo myServo;
const int servoPin = 9;

const byte ROWS = 4; // four rows
const byte COLS = 4; // four columns
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte rowPins[ROWS] = {5, 4, 3, 2}; // connect to the row pinouts of the keypad
byte colPins[COLS] = {9, 8, 7, 6}; // connect to the column pinouts of the keypad
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

String password = "1234";
String enteredPassword = "";

void setup() {
  myServo.attach(servoPin);
  Serial.begin(9600);
}

void loop() {
  char key = keypad.getKey();
  
  if (key) {
    if (key == '*') {
      if (enteredPassword == password) {
        moveServo(); // Call the function to move the servo (open position)
      }
      enteredPassword = ""; // Reset entered password
    } else if (key == '#') {
      closeLock(); // Call the function to close the lock
    } else {
      enteredPassword += key;
    }
  }
}

void moveServo() {
  myServo.write(90); // Adjust the angle as needed
}

void closeLock() {
  myServo.write(0); // Adjust the angle to close the lock (adjust as needed)

}