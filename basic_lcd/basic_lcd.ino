#include <LiquidCrystal.h>

const uint8_t rs = 8, enable = 9, d4 = 4, d5 = 5, d6 = 6, d7 = 7;
uint16_t button = 0;
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
  lcd.setCursor(0, 1);
  button = analogRead(0);
  // Print blanks to clear screen
  lcd.print("    ");
  // Go back to beginning of line
  lcd.setCursor(0, 1);
  // Print the analog reading
  lcd.print(button);
  delay(100);

}
