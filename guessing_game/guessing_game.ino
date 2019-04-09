#include <LiquidCrystal.h>

// Analog read values for each button
#define RIGHT 0
#define DOWN 257
#define UP 99
#define LEFT 411
#define SELECT 640

// Pin values
const uint8_t rs = 8, enable = 9, d4 = 4, d5 = 5, d6 = 6, d7 = 7;

// Read analog value from button
uint16_t button_val = 0;

// Create LCD object
LiquidCrystal lcd(rs, enable, d4, d5, d6, d7);

// The computer's number and person's guess
uint8_t compNum, userNum = 1;

void setup()
{
  lcd.begin(16, 2);
  compNum = random(1, 101);
}

void loop()
{
  lcd.setCursor(0, 0);
  lcd.print("Guess a number");
  lcd.setCursor(0, 1);
  lcd.print("1-100: ");
  lcd.print(userNum);

  button_val = analogRead(0);
  if (button_val == RIGHT)
    userNum += 10;
  else if (button_val == UP)
    userNum++;

    delay(200);
  
}
