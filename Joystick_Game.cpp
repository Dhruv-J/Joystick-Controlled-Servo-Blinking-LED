#include <Servo.h>
Servo my_servo_x;
int xpos;
Servo my_servo_y;
int ypos;
const byte pin_analog_x = 1;
const byte pin_analog_y = 0;
const byte pin_button = 9; // Select button


void setup() {
  Serial.begin(9600);  
  my_servo_x.attach(13);
  my_servo_y.attach(12);
  pinMode(7, OUTPUT);
  digitalWrite(7, LOW);
  pinMode(pin_button , INPUT);
  digitalWrite(pin_button , LOW);
}


void loop() {
  // Print the current values of the inputs (joystick and
  // buttons) to the console.
  Serial.print("x:");
  int x_val = analogRead(pin_analog_x);
  Serial.print(" ");
  
  int x_ServPos = x_val/ 5.69;
  
  Serial.print("y:");
  int y_val = analogRead(pin_analog_y);
  Serial.print(" ");  
  
  int y_ServPos = y_val/ 5.69;
  
  my_servo_x.write(x_ServPos);
  my_servo_y.write(y_ServPos);
  int button_val = digitalRead(pin_button);
  
  Serial.print(x_ServPos);
  Serial.print("  ");
  Serial.print(y_ServPos);
    Serial.print("  ");
  Serial.print(button_val);
  //Serial.println("-----------------------");
  
  Serial.println();
  
  if(button_val == 1) {
    digitalWrite(7, HIGH);  
    delay (1000);
    digitalWrite(7, LOW);
  }
  else {
    digitalWrite(7, LOW);
  }
}
