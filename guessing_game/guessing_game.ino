/*
 * Plays simple number guessing game with user.
 *  - Computer generates random number.
 *  - User chooses number with UP, DOWN, LEFT, RIGHT buttons
 *    and enters value with SELECT button.
 *	  - UP increases user's number by 1
 *	  - DOWN decreases user's number by 1
 *	  - RIGHT increases user's number by 10
 *	  - LEFT decreases the user's number by 10
 *  - Program responds with "Too low", "Too high" or
 *	  "You guessed it!"
 *  Reset Arduino to begin new game
 */

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
  // Seed PRNG with input from unconnected pin
  randomSeed(analogRead(3));
  compNum = random(1, 101);
}

void loop()
{
  lcd.setCursor(0, 0);
  lcd.print("Guess a number");
  lcd.setCursor(0, 1);
  lcd.print("          ");
  lcd.setCursor(0, 1);
  lcd.print("1-100: ");
  lcd.print(userNum);

  button_val = analogRead(0);
  if (abs(button_val-RIGHT) < 10)
    userNum += 10;
  else if (abs(button_val-UP) < 10)
    userNum++;
  else if (abs(button_val-DOWN) < 10)
    userNum--;
  else if (abs(button_val-LEFT) < 10)
    userNum -= 10;
  else if (abs(button_val-SELECT) < 10)
  {
	// Clear screen
    lcd.setCursor(0, 0);
    lcd.print("                ");
    lcd.setCursor(0, 1);
    lcd.print("                ");
    lcd.setCursor(0, 0);
	
    if (userNum == compNum)
      lcd.print("You guessed it!");
    else if (userNum < compNum)
      lcd.print("Too low");
    else
      lcd.print("Too high");
    delay(1500);
    
  }
    delay(200);
}
