/*
  LiquidCrystal Library - Hello World

 Demonstrates the use a 16x2 LCD display.  The LiquidCrystal
 library works with all LCD displays that are compatible with the
 Hitachi HD44780 driver. There are many of them out there, and you
 can usually tell them by the 16-pin interface.

 This sketch prints "Hello World!" to the LCD
 and shows the time.

  The circuit:
 * LCD RS pin to digital pin 8
 * LCD Enable pin to digital pin 9
 * LCD D4 pin to digital pin 4
 * LCD D5 pin to digital pin 5
 * LCD D6 pin to digital pin 6
 * LCD D7 pin to digital pin 7
 * LCD R/W pin to ground
 * LCD VSS pin to ground
 * LCD VCC pin to 5V
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)

 http://www.arduino.cc/en/Tutorial/LiquidCrystal
 */

// Include the library code:
#include <LiquidCrystal.h>

// Initialize the library with the numbers of the interface pins
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

// Initialize variables
int incoming = 0;
int btn_in = 0;
String message = "";

// Define constants for reading buttons on analog input
const int BTN_NONE = 1023;
const int BTN_SELECT = 723;
const int BTN_LEFT = 481;
const int BTN_DOWN = 308;
const int BTN_UP = 132;
const int BTN_RIGHT = 0;

void setup() {
  // Set up the LCD's number of columns and rows:
  lcd.begin(16, 2);

  // Start serial output
  Serial.begin(9600);
  while(!Serial){
    ;
  }
  
  // Print a message to the LCD.
  lcd.print("Ready.");
}

String readButtons() {
  btn_in = analogRead(0);
  String result = getMessage(btn_in);

  return result;
}

String getMessage(int value) {
  String return_val = "";
  switch (btn_in) {
    case BTN_NONE:
      return_val = "NO BUTTON";
      break;
    case BTN_SELECT:
      return_val = "SELECT   ";
      break;
    case BTN_LEFT:
    case BTN_LEFT - 1:
      return_val = "LEFT     ";
      break;
    case BTN_DOWN:
    case BTN_DOWN - 1:
      return_val = "DOWN     ";
      break;
    case BTN_UP:
    case BTN_UP -1:
      return_val = "UP       ";
      break;
    case BTN_RIGHT:
      return_val = "RIGHT    ";
      break;
    default:
      return_val = String(value, DEC);
      break;
  }

  return return_val;
}

void loop() {
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  //lcd.setCursor(0, 1);
  // print the number of seconds since reset:
  //lcd.print(millis() / 1000);

  //lcd.clear();
  message = readButtons();
  delay(100);
  lcd.setCursor(0,1);
  //Serial.println(message);
  lcd.print(message);
  
  if(Serial.available() > 0 ) {
    incoming = Serial.read();
    
    Serial.print("Incoming: ");
    Serial.println(incoming);
  }
  
}














