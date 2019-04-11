#include <LiquidCrystal.h>

// Pins for LCD connection
const uint8_t rs = 8, enable = 9, d4 = 4, d5 = 5, d6 = 6, d7 = 7;
// Stores the analog read value from the button: 0-1023
uint16_t button = 0;
// Initialize LCD
LiquidCrystal lcd(rs, enable, d4, d5, d6, d7);

void setup()
{
  // 16 cols, 2 rows
  lcd.begin(16, 2);
  // Start at col, 0 row 0
  lcd.setCursor(0, 0);
  lcd.print("Hello, World!");
}

void loop()
{
  // Go to beginning of 2nd line
  lcd.setCursor(0, 1);
  // Read value from analog pin 0
  button = analogRead(0);
  // Print blanks to clear screen
  lcd.print("    ");
  // Go back to beginning of line
  lcd.setCursor(0, 1);
  // Print the analog reading
  lcd.print(button);
  delay(100);
}
